#ifndef FEC_H
#define FEC_H
#include "typedefs.h"
 
#define FEC_OK 0 
#define FEC_NOK 255
#define FEC_NO_INIT 254


// queue priority
#define FEC_HIGH 1
#define FEC_MID 2
#define FEC_LOW 4

typedef volatile struct FEC_tag_struct * FEC_TAG;
#define FEC_dev   	((FEC_TAG) 			0xFFF4C000UL )    

#ifndef TX_FRAME_MAX_SEG
#define TX_FRAME_MAX_SEG 10
#endif

struct data_seg_t
{
	uint16_t len;
	const uint8_t *data;
};
// note: insert order reverse 
struct eth_frame_t
{
	uint8_t type;  // only used for tx
	uint8_t seg_num;
	struct data_seg_t seg[TX_FRAME_MAX_SEG]; 
	uint8_t tx_bd_cnt; // used to store the address of BufferDescriptor 
	uint32_t  magic; //used to check vaild of eth_frame_t, it must be the last one eletment
};
// return FEC_OK means data have been handled
typedef uint8_t (*fec_handle)(struct eth_frame_t * rx_frame);

struct FEC_device_struct{
	FEC_TAG hal;
	uint8_t mac_addr[6];
};

// note: one rx frame can not  beyond one reg segment, this is easier for rx handle
uint8_t Fec_init(struct FEC_device_struct *dev); 
uint8_t Fec_remove(void); 
uint8_t Fec_frame_insert(struct eth_frame_t* frame); 
uint8_t Fec_register_rx_handle(fec_handle rx_handle); 
uint8_t Fec_register_tx_complete_handle(fec_handle tx_handle); 
// type: handle queue according to priority
// can not call this function from multi task or interrupt
uint8_t Fec_start_xmit(uint8_t type, uint16_t max_tx_cnt); 
uint8_t Fec_check_tx_buff(void); 
uint8_t Fec_check_rx_buff(void); 
#endif
