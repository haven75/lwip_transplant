#include "fec.h"
#include "fec_private.h"
#include "FIFOQUEUE.h"
#include "debug.h"

/********************* Macro definition ***************************/
#define isVaildFecDev(x)  (x!=(FEC_TAG) 0)
#define isEthFrameLen(x)  ((x>=14) && (x<=1536))
#define isVaildHandle(handle) (handle != (fec_handle)0)
/* frame magic check */
#define getVaildFrameMagic(x) (x->magic = gen_frame_magic(x))
#define isVaildFrameMagic(x) (x->magic == gen_frame_magic(x))
/* BufferDescriptor operate */
#define isTxBDIdle(x) ((txDesc[x].status & BD_ENET_TX_READY) == 0)
#define txBDCntAdd(x,y) ((x+y)%TX_BUFF_DES_NUM)
#define txBDCntDec(x,y) (x>=y?x-y:x+TX_BUFF_DES_NUM-y)
/* harware control */
#define FecTxStart() do{FEC->TDAR.R = 0x01000000;}while(0)
/********************* local variable ***************************/
#if RX_BUFF_DES_NUM > 255
#error "RX_BUFF_DES_NUM is too large"
#endif
static BufferDescriptor rxDesc[RX_BUFF_DES_NUM]
#ifndef WIN32
    __attribute__ ((aligned (16)))
#endif
    ;
#if TX_BUFF_DES_NUM > 255
#error "TX_BUFF_DES_NUM is too large"
#endif
static BufferDescriptor txDesc[TX_BUFF_DES_NUM]
#ifndef WIN32
    __attribute__ ((aligned (16)))
#endif
    ;
static uint8_t tx_bd_cnt = 0;
static uint8_t rxBuf[RX_BUFF_NUM][RX_BUFF_MAX_LEN]
#ifndef WIN32
    __attribute__ ((aligned (16)))
#endif
    ;

static FEC_TAG FEC = (FEC_TAG) 0;
struct FEC_handles
{
    uint8_t cnt;
    fec_handle handle[MAX_RX_OR_TX_HANDLE_NUM];
};
static struct FEC_handles rx_handles;
static struct FEC_handles tx_handles;

static struct FifoQueue high_tx_queue;
static struct FifoQueue mid_tx_queue;
static struct FifoQueue low_tx_queue;
static struct FifoQueue tx_complete_queue;

static struct eth_frame_t *last_tx_frame = (struct eth_frame_t *) 0;
static uint16_t tx_remain_cnt = 0;;
static uint8_t rx_bd_cnt = 0;

/********************* local functions ***************************/
static uint8_t regFecHandle(struct FEC_handles* handles, fec_handle fun);
static uint8_t isTxDesEnd (uint16_t index);
static void markRxDescEmpty (uint16_t index);
static void markTxDescEmpty (uint16_t index);

static uint8_t checkDummyAddr (uint8_t * addr, uint8_t dummy);
static uint8_t isValidNodeMacAddr (uint8_t * addr);

// 0 for tx not done, 1 for tx done, -1 for error
static uint8_t isFrameTxComplete (struct eth_frame_t *frame);
static uint8_t isVaildQueueType (uint8_t type);
static uint8_t isVaildLength (struct eth_frame_t *frame);
static uint8_t isVaildSegData (struct eth_frame_t *frame);
static uint8_t isVaildSegPointers (struct eth_frame_t *frame);
static uint8_t isValidFrame (struct eth_frame_t *frame);
static uint32_t gen_frame_magic (struct eth_frame_t *frame);

static void
setCurrentTxBD (struct data_seg_t *seg, unsigned short status_set,
                unsigned short status_clr);
static uint8_t setFrameToTxBDs (struct eth_frame_t *frame);
static uint8_t handleTxFrame(struct eth_frame_t *frame);

/********************* local functions start ***************************/
static uint8_t regFecHandle(struct FEC_handles* handles, fec_handle fun)
{
	if (!isVaildFecDev(FEC))
		return FEC_NO_INIT;
	if (!isVaildHandle(fun))
		return FEC_NOK;
	if (handles->cnt >= MAX_RX_HANDLE_NUM)
		return FEC_NOK;
	handles->handle[handles->cnt] = fun;
	handles->cnt++;
	return FEC_OK;
}

static uint8_t
isTxDesEnd (uint16_t index)
{
    if (index == (TX_BUFF_DES_NUM - 1))
        return 1;
    else
        return 0;
}

// Mark specified rx desc as empty
static void
markRxDescEmpty (uint16_t index)
{
    BufferDescriptor *used = &rxDesc[index];
    used->length = 0;
    if (used != &rxDesc[RX_BUFF_DES_NUM - 1])
    {
        used->status = BD_ENET_RX_EMPTY;    // Empty        
    }
    else
    {
        used->status = BD_ENET_RX_EMPTY | BD_ENET_RX_WRAP;  // Wrap and Empty
    }
	if (FEC)
	{
		// Flag descriptors available to allow reception
		FEC->RDAR.R = 0x0100000;
	}
}

static void
markTxDescEmpty (uint16_t index)
{
    BufferDescriptor *tx = &txDesc[index];
    if (!isTxDesEnd (index))
    {
        tx->status = 0;         // Empty        
    }
    else
    {
        tx->status = BD_ENET_TX_WRAP;   // Wrap and Empty
    }
    tx->length = 0;
}

static uint8_t
checkDummyAddr (uint8_t * addr, uint8_t dummy)
{
    uint8_t i;
    for (i = 0; i < 6; i++)
    {
        if (addr[i] != dummy)
        {
            break;
        }
    }
    return i == 6;
}

// 0 for tx not done, 1 for tx done, -1 for error
static uint8_t
isFrameTxComplete (struct eth_frame_t *frame)
{
    uint8_t i;
    uint8_t bd_cnt = frame->tx_bd_cnt;
    uint8_t res = TX_FRAME_COMPLETE;
    if (isVaildFrameMagic (frame))
    {
        for (i = 0; i < frame->seg_num; i++)
        {
            if ((txDesc[bd_cnt].status & BD_ENET_TX_READY) == 0)
            {
                if ((i == frame->seg_num - 1)
                    && ((txDesc[bd_cnt].status & BD_ENET_TX_LAST) == 0))
                {
                    res = TX_FRAME_COMPLETE_ERROR;
                    break;
                }
                bd_cnt = txBDCntAdd (bd_cnt, 1);
            }
            else
            {
                res = TX_FRAME_NOT_COMPLETE;
                break;
            }
        }
    }
    else
    {
        res = TX_FRAME_COMPLETE_ERROR;
    }
    return res;
}

static uint8_t
isValidNodeMacAddr (uint8_t * addr)
{
    if (checkDummyAddr (addr, 0))
    {
        return 0;
    }
    else
    {
        if (checkDummyAddr (addr, 0xff))
        {
            return 0;
        }
    }
    return 1;
}


static uint8_t
isVaildQueueType (uint8_t type)
{
    if ((type == FEC_HIGH) || (type == FEC_MID) || (type == FEC_LOW))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static uint8_t
isVaildLength (struct eth_frame_t *frame)
{
    uint16_t i, len = 0;
    for (i = 0; i < frame->seg_num; i++)
    {
        len += frame->seg[i].len;
    }
    if (isEthFrameLen (len))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static uint8_t
isVaildSegData (struct eth_frame_t *frame)
{
    uint16_t i;
    for (i = 0; i < frame->seg_num; i++)
    {
        if ((const uint8_t *) 0 == frame->seg[i].data)
        {
            return 0;
        }
    }
    return 1;
}

static uint8_t
isVaildSegPointers (struct eth_frame_t *frame)
{
    uint16_t i;
    for (i = 0; i < frame->seg_num; i++)
    {
        if (0 != (((uint32_t) frame->seg[i].data) & 0xf))
        {
            return 0;
        }
    }
    return 1;
}

static uint8_t
isValidFrame (struct eth_frame_t *frame)
{
    if ((isVaildQueueType (frame->type))
        && (isVaildLength (frame))
        && (isVaildSegData (frame)) && (isVaildSegPointers (frame)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static uint32_t
gen_frame_magic (struct eth_frame_t *frame)
{
    uint32_t magic = 0;
    uint32_t *data = (uint32_t *) frame;
    uint32_t i;
    uint32_t loop =
        (sizeof (struct eth_frame_t) -
         sizeof (uint32_t) * 3) / sizeof (uint32_t);
    /* last 3 uint32_t is not check */
    for (i = 0; i < loop; i++)
    {
        magic += *data++;
    }
    return magic;
}

static void
setCurrentTxBD (struct data_seg_t *seg, unsigned short status_set,
                unsigned short status_clr)
{
    unsigned short status;
    txDesc[tx_bd_cnt].length = seg->len;
    txDesc[tx_bd_cnt].bufferPointer = seg->data;
    status = txDesc[tx_bd_cnt].status;
    status |= status_set;
    status &= ~status_clr;
    txDesc[tx_bd_cnt].status = status;
}

static uint8_t
setFrameToTxBDs (struct eth_frame_t *frame)
{
    int i;
    uint8_t tx_bd_cnt_new;

    for (i = 0; i < frame->seg_num; i++)
    {
        if (!isTxBDIdle (txBDCntAdd (tx_bd_cnt, i)))
        {
            return FEC_NOK;
        }
    }

    frame->tx_bd_cnt = tx_bd_cnt;
    tx_bd_cnt = txBDCntAdd (tx_bd_cnt, frame->seg_num - 1);
    tx_bd_cnt_new = tx_bd_cnt;
    for (i = frame->seg_num - 1; i >= 0; i--)
    {
        unsigned short status_set = BD_ENET_TX_READY | BD_ENET_TX_TC;
        unsigned short status_clr = 0;
        if (tx_bd_cnt == (TX_BUFF_DES_NUM - 1))
        {
            status_set |= BD_ENET_TX_WRAP;
        }
        if (i == (frame->seg_num - 1))
        {
            status_set |= BD_ENET_TX_LAST;
        }
        else
        {
            status_clr |= BD_ENET_TX_LAST;
        }
        setCurrentTxBD (&frame->seg[frame->seg_num - 1 - i], status_set, status_clr);
        tx_bd_cnt = txBDCntDec (tx_bd_cnt, 1);
    }
    tx_bd_cnt = txBDCntAdd (tx_bd_cnt_new, 1);
    return FEC_OK;
}

static void
fecHardwareInit (struct FEC_device_struct *dev)
{
    FEC->ECR.R = 0x1;           // Start reset
    while (FEC->ECR.B.RESET)
    {
    };                          // Wait for reset to complete
    FEC->EIMR.R = 0;            // Disable interrupts
    FEC->EIR.R = 0xFFFFFFFF;    // Clear any interrupts
    // Reset multicast fields
    FEC->GAUR.R = 0;
    FEC->GALR.R = 0;
    FEC->IAUR.R = 0;
    FEC->IALR.R = 0;

    // Set rx buf size 
    FEC->EMRBR.R = RX_BUFF_MAX_LEN;

    // Point FEC to our (single) tx and rx descriptors
    FEC->ETDSR.R = (unsigned long) &txDesc[0];
    FEC->ERDSR.R = (unsigned long) &rxDesc[0];

    // Enable full duplex 
    FEC->TCR.R = 0x00000004;

    // Set in MII mode with full frame size
    FEC->RCR.R = 0x05EE0004;
    FEC->RCR.B.MAX_FL = RX_BUFF_MAX_LEN;

    // Set MII speed - assume operation at 64Mhz
    FEC->MSCR.B.MII_SPEED = 0x8;

    // Set in MII mode with full frame size
    FEC->RCR.R = 0x05EE0004;
    FEC->RCR.B.RCR_PROM = 1;    //Promiscuous mode. All frames are accepted regardless of address matching.
    // Set MII speed - assume operation at 64Mhz
    FEC->MSCR.B.MII_SPEED = 0x8;

    // Enable module
    FEC->ECR.R = 0x2;

    // Configure a MAC address
    FEC->PALR.R =
        (unsigned long) ((dev->mac_addr[0] << 24) | (dev->mac_addr[1] << 16) |
                         (dev->mac_addr[2] << 8) | (dev->mac_addr[3] << 0));
    FEC->PAUR.R =
        (unsigned long) (dev->mac_addr[4] << 24) | (dev->mac_addr[5] << 16);

    // Flag descriptors available to allow reception
    FEC->RDAR.R = 0x0100000;
}

static uint8_t
txFramesForQueue (struct FifoQueue *queue)
{
    uint8_t res;
    struct eth_frame_t *frame;
    res = FEC_OK;
	if (!tx_remain_cnt) return res;
    while (QueueOperateOk == QueueOut (queue, (ElemType *) & frame))
    {
        if (isVaildFrameMagic (frame))
        {
            if (FEC_OK == setFrameToTxBDs (frame))
            {
            	uint8_t insert_res = QueueIn (&tx_complete_queue, (ElemType *) frame);
                FecTxStart ();  // Tell FEC frame is ready
				if (tx_remain_cnt) tx_remain_cnt--;
				if (!tx_remain_cnt) break;
                if(QueueOperateOk != insert_res)
                {
                	pr_info_const("FEC: error when insert tx complete queue\n");
                }
            }
            else
            {
                res = FEC_NOK;
                break;
            }
        }
        else
        {
            res = FEC_NOK;
        }
    }
    return res;
}

static uint8_t
handleTxFrame(struct eth_frame_t *frame)
{
	uint8_t frame_res;
	frame_res = isFrameTxComplete(frame);
	if (frame_res == TX_FRAME_COMPLETE)
	{
		int i;
		for (i = 0; i < tx_handles.cnt; i++)
		{
			if (FEC_OK == tx_handles.handle[i](frame))
			{
				break;
			}
		}
	}
	return frame_res;
}


/********************* global functions ***************************/
uint8_t
Fec_remove (void)
{
    FEC = (FEC_TAG) 0;
    tx_handles.cnt = 0;
    rx_handles.cnt = 0;
    return FEC_OK;
}


uint8_t
Fec_init (struct FEC_device_struct * dev)
{
    uint8_t i;
    if ((struct FEC_device_struct *) 0 == dev)
        return FEC_NOK;
    if (!isVaildFecDev (dev->hal))
        return FEC_NOK;
    if (!isValidNodeMacAddr (dev->mac_addr))
        return FEC_NOK;
    if (isVaildFecDev (FEC))
        return FEC_NOK;
    // init eth buffer
    for (i = 0; i < sizeof (rxDesc) / sizeof (BufferDescriptor); i++)
    {
        markRxDescEmpty (i);
        rxDesc[i].bufferPointer = rxBuf[i];
    }

    for (i = 0; i < sizeof (txDesc) / sizeof (BufferDescriptor); i++)
    {
        markTxDescEmpty (i);
    }
    // init queues
    QueueInit (&high_tx_queue);
    QueueInit (&mid_tx_queue);
    QueueInit (&low_tx_queue);
    QueueInit (&tx_complete_queue);
    // init handles
    tx_handles.cnt = 0;
    rx_handles.cnt = 0;
	// init bd cnt
	tx_bd_cnt = 0;
	rx_bd_cnt = 0;
    // init variables
    last_tx_frame = (struct eth_frame_t *) 0;
	tx_remain_cnt = 0;
    // init hardware
    FEC = dev->hal;
    fecHardwareInit (dev);
    return FEC_OK;
}

uint8_t
Fec_frame_insert (struct eth_frame_t * frame)
{
    if (!isVaildFecDev (FEC))
        return FEC_NO_INIT;
    if ((struct eth_frame_t *) 0 == frame)
        return FEC_NOK;
    if (!isValidFrame (frame))
        return FEC_NOK;
    getVaildFrameMagic (frame);
    switch (frame->type)
    {
    case FEC_HIGH:
        QueueIn (&high_tx_queue, (ElemType) frame);
        break;
    case FEC_MID:
        QueueIn (&mid_tx_queue, (ElemType) frame);
        break;
    case FEC_LOW:
        QueueIn (&low_tx_queue, (ElemType) frame);
        break;
    default:
        return FEC_NOK;

    }
    return FEC_OK;
}


// type: handle queue according to priority
uint8_t
Fec_start_xmit (uint8_t type, uint16_t max_tx_cnt)
{
    uint8_t res;
    if (!isVaildFecDev (FEC))
        return FEC_NO_INIT;
    res = FEC_OK;
	tx_remain_cnt = max_tx_cnt;
    if (type & FEC_HIGH)
    {
        res |= txFramesForQueue (&high_tx_queue);
    }
    if (type & FEC_MID)
    {
        res |= txFramesForQueue (&mid_tx_queue);
    }
    if (type & FEC_LOW)
    {
        res |= txFramesForQueue (&low_tx_queue);
    }
	if (res != FEC_OK)
		res = FEC_NOK;
    return res;
}


uint8_t
Fec_register_rx_handle (fec_handle rx_handle)
{
	return regFecHandle(&rx_handles, rx_handle);
}

uint8_t
Fec_register_tx_complete_handle (fec_handle tx_handle)
{
	return regFecHandle(&tx_handles, tx_handle);
}


uint8_t
Fec_check_tx_buff (void)
{
    struct eth_frame_t *frame;
    uint8_t queue_res;
    uint8_t res = FEC_OK;
    uint8_t frame_res;
    if (!isVaildFecDev (FEC))
        return FEC_NO_INIT;
	queue_res = QueueEmpty;
    do
    {
        frame = (struct eth_frame_t *) 0;
        if (last_tx_frame != (struct eth_frame_t *) 0)
        {
            frame = last_tx_frame;
            last_tx_frame = (struct eth_frame_t *) 0;
        }
        else
        {
            queue_res = QueueOut (&tx_complete_queue, (ElemType *) & frame);
        }
        if (frame || (QueueOperateOk == queue_res))
        {
            frame_res = handleTxFrame (frame);
            if (frame_res == TX_FRAME_NOT_COMPLETE)
            {
                last_tx_frame = frame;
                break;
            }
            else if (frame_res == TX_FRAME_COMPLETE_ERROR)
            {
                //frame error, drop this frame and handle next one
                res = FEC_NOK;
            }
            else
            {
                // tx frame done, handle next one
            }
        }
        else
        {
            // no more frame need handle
            break;
        }
    }
    while (1);

    return res;
}

uint8_t
Fec_check_rx_buff (void)
{
	uint8_t rx_bd_cnt_old = rx_bd_cnt;
	struct eth_frame_t frame;
    if (!isVaildFecDev (FEC))
        return FEC_NO_INIT;
	frame.seg_num = 1;
	do {
		if ((rxDesc[rx_bd_cnt].status & BD_ENET_RX_EMPTY) == 0)
		{
			if (isEthFrameLen(rxDesc[rx_bd_cnt].length) 
				&& (rxDesc[rx_bd_cnt].status & BD_ENET_RX_LAST)
				&& ((rxDesc[rx_bd_cnt].status & BD_ENET_RX_CR) == 0)
				&& ((rxDesc[rx_bd_cnt].status & BD_ENET_RX_LG) == 0)
				)
			{
				int i;
				frame.seg[0].data = rxDesc[rx_bd_cnt].bufferPointer;
				frame.seg[0].len = rxDesc[rx_bd_cnt].length;
				for (i = 0; i < rx_handles.cnt; i++)
				{
					if (FEC_OK == rx_handles.handle[i](&frame))
					{
						break;
					}
				}
			}else{
				pr_info_const("fec: rx frame error\n");
			}
			markRxDescEmpty(rx_bd_cnt);
			rx_bd_cnt++;
			rx_bd_cnt %= RX_BUFF_DES_NUM;
		}else{
			break;
		}
	} while (rx_bd_cnt != rx_bd_cnt_old);
    return FEC_OK;
}
