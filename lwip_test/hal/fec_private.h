#ifndef FEC_PRIVATE_H
#define FEC_PRIVATE_H
#include "fec.h"
struct FEC_tag_struct
{

    int8_t FEC_reserved_0000[4];

    union
    {                           /* Bits are write 1 to clear */
        vuint32_t R;
        struct
        {
            vuint32_t IR_HBERR:1;   /*  */
            vuint32_t IR_BABR:1;    /*  */
            vuint32_t IR_BABT:1;    /*  */
            vuint32_t IR_GRA:1; /*  */
            vuint32_t IR_TXF:1; /*  */
            vuint32_t IR_TXB:1; /*  */
            vuint32_t IR_RXF:1; /*  */
            vuint32_t IR_RXB:1; /*  */
            vuint32_t IR_MII:1; /*  */
            vuint32_t IR_EBERR:1;   /*  */
            vuint32_t IR_LC:1;  /*  */
            vuint32_t IR_RL:1;  /*  */
            vuint32_t IR_UN:1;  /*  */
              vuint32_t:19;
        } B;
    } EIR;

    union
    {                           /*  */
        vuint32_t R;
        struct
        {
            vuint32_t IR_HBERR:1;   /*  */
            vuint32_t IR_BABR:1;    /*  */
            vuint32_t IR_BABT:1;    /*  */
            vuint32_t IR_GRA:1; /*  */
            vuint32_t IR_TXF:1; /*  */
            vuint32_t IR_TXB:1; /*  */
            vuint32_t IR_RXF:1; /*  */
            vuint32_t IR_RXB:1; /*  */
            vuint32_t IR_MII:1; /*  */
            vuint32_t IR_EBERR:1;   /*  */
            vuint32_t IR_LC:1;  /*  */
            vuint32_t IR_RL:1;  /*  */
            vuint32_t IR_UN:1;  /*  */
              vuint32_t:19;
        } B;
    } EIMR;

    int8_t FEC_reserved_000C[4];

    union
    {                           /*  */
        vuint32_t R;
        struct
        {
            vuint32_t:7;
            vuint32_t R_DES_ACTIVE:1;   /*  */
              vuint32_t:24;
        } B;
    } RDAR;

    union
    {                           /*  */
        vuint32_t R;
        struct
        {
            vuint32_t:7;
            vuint32_t X_DES_ACTIVE:1;   /*  */
              vuint32_t:24;
        } B;
    } TDAR;

    int8_t FEC_reserved_0018[12];

    union
    {                           /*  */
        vuint32_t R;
        struct
        {
            vuint32_t:30;
            vuint32_t ETHER_EN:1;   /*  */
            vuint32_t RESET:1;  /*  */
        } B;
    } ECR;

    int8_t FEC_reserved_0028[24];

    union
    {                           /* The MII_DATA register does not reset to a defined value */
        vuint32_t R;
        struct
        {
            vuint32_t ST:2;     /*  */
            vuint32_t OP:2;     /*  */
            vuint32_t PA:5;     /*  */
            vuint32_t RA:5;     /*  */
            vuint32_t TA:2;     /*  */
            vuint32_t DATA:16;  /*  */
        } B;
    } MMFR;

    union
    {                           /*  */
        vuint32_t R;
        struct
        {
            vuint32_t:24;
            vuint32_t DIS_PREAMBLE:1;   /*  */
            vuint32_t MII_SPEED:6;  /*  */
              vuint32_t:1;
        } B;
    } MSCR;

    int8_t FEC_reserved_0048[28];


    union
    {                           /* MIB Control Register */
        vuint32_t R;
        struct
        {
            vuint32_t MIB_DISABLE:1;    /*  */
            vuint32_t MIB_IDLE:1;   /*  */
              vuint32_t:30;
        } B;
    } MIBC;

    int8_t FEC_reserved_0068[28];

    union
    {                           /* Receive Control register */
        vuint32_t R;
        struct
        {
            vuint32_t:5;
            vuint32_t MAX_FL:11;    /*  */
              vuint32_t:10;
            vuint32_t RCR_FCE:1;    /*  */
            vuint32_t RCR_BC_REJ:1; /*  */
            vuint32_t RCR_PROM:1;   /*  */
            vuint32_t RCR_MII_MODE:1;   /*  */
            vuint32_t RCR_DRT:1;    /*  */
            vuint32_t RCR_LOOP:1;   /*  */
        } B;
    } RCR;

    int8_t FEC_reserved_0088[60];

    union
    {                           /* Transmit control register */
        vuint32_t R;
        struct
        {
            vuint32_t:27;
            vuint32_t RFC_PAUSE:1;  /*  */
            vuint32_t TFC_PAUSE:1;  /*  */
            vuint32_t FDEN:1;   /*  */
            vuint32_t HBC:1;    /*  */
            vuint32_t GTS:1;    /*  */
        } B;
    } TCR;

    int8_t FEC_reserved_00C8[28];

    union
    {                           /* Reset value is not defined */
        vuint32_t R;
        struct
        {
            vuint32_t PADDR1:32;    /*  */
        } B;
    } PALR;

    union
    {                           /* Reset Value of upper 16-bits is not defined */
        vuint32_t R;
        struct
        {
            vuint32_t PADDR2:16;    /*  */
            vuint32_t TYPE:16;  /*  */
        } B;
    } PAUR;

    union
    {                           /* Reset Value of lower 16-bits is not defined */
        vuint32_t R;
        struct
        {
            vuint32_t OPCODE:16;    /*  */
            vuint32_t PAUSE_DUR:16; /*  */
        } B;
    } OPDR;

    int8_t FEC_reserved_00F0[40];

    union
    {                           /* This register is not reset to a defined value */
        vuint32_t R;
        struct
        {
            vuint32_t IADDR1:32;    /*  */
        } B;
    } IAUR;

    union
    {                           /* This register is not reset to a defined value */
        vuint32_t R;
        struct
        {
            vuint32_t IADDR2:32;    /*  */
        } B;
    } IALR;

    union
    {                           /* This register is not reset to a defined value */
        vuint32_t R;
        struct
        {
            vuint32_t GADDR1:32;    /*  */
        } B;
    } GAUR;

    union
    {                           /* This register is not reset to a defined value */
        vuint32_t R;
        struct
        {
            vuint32_t GADDR2:32;    /*  */
        } B;
    } GALR;

    int8_t FEC_reserved_0128[28];

    union
    {                           /*  */
        vuint32_t R;
        struct
        {
            vuint32_t:30;
            vuint32_t X_WMRK:2; /*  */
        } B;
    } TFWR;

    int8_t FEC_reserved_0148[4];

    union
    {                           /*  */
        vuint32_t R;
        struct
        {
            vuint32_t:22;
            vuint32_t R_BOUND:8;    /*  */
              vuint32_t:2;
        } B;
    } FRBR;

    union
    {                           /*  */
        vuint32_t R;
        struct
        {
            vuint32_t:22;
            vuint32_t R_FSTART:8;   /*  */
              vuint32_t:2;
        } B;
    } FRSR;

    int8_t FEC_reserved_0154[44];

    union
    {                           /* This register is not reset to a defined value */
        vuint32_t R;
        struct
        {
            vuint32_t R_DES_START:30;   /*  */
              vuint32_t:2;
        } B;
    } ERDSR;

    union
    {                           /* This register is not reset to a defined value */
        vuint32_t R;
        struct
        {
            vuint32_t X_DES_START:30;   /*  */
              vuint32_t:2;
        } B;
    } ETDSR;

    union
    {                           /* This register is not reset to a defined value */
        vuint32_t R;
        struct
        {
            vuint32_t:21;
            vuint32_t R_BUFF_SIZE:7;    /*  */
              vuint32_t:4;
        } B;
    } EMRBR;

    int8_t FEC_reserved_018C[116];

    union
    {                           /* Count of frames not counted correctly */
        vuint32_t R;
    } RMON_T_DROP;

    union
    {                           /* RMON Tx packet count */
        vuint32_t R;
    } RMON_T_PACKETS;

    union
    {                           /* RMON Tx Broadcast Packets */
        vuint32_t R;
    } RMON_T_BC_PKT;

    union
    {                           /* RMON Tx Multicast Packets */
        vuint32_t R;
    } RMON_T_MC_PKT;

    union
    {                           /* RMON Tx Packets w CRC Align error */
        vuint32_t R;
    } RMON_T_CRC_ALIGN;

    union
    {                           /* RMON Tx Packets lt 64 bytes good crc */
        vuint32_t R;
    } RMON_T_UNDERSIZE;

    union
    {                           /* RMON Tx Packets gt MAX_FL bytes good crc */
        vuint32_t R;
    } RMON_T_OVERSIZE;

    union
    {                           /* Tx Packets lt 64 bytes bad crc */
        vuint32_t R;
    } RMON_T_FRAG;

    union
    {                           /* Tx Packets gt MAX_FL bytes bad crc */
        vuint32_t R;
    } RMON_T_JAB;

    union
    {                           /* Tx collision count */
        vuint32_t R;
    } RMON_T_COL;

    union
    {                           /* Tx 64 byte packets */
        vuint32_t R;
    } RMON_T_P64;

    union
    {                           /* RMON Tx 65 to 127 byte packets */
        vuint32_t R;
    } RMON_T_P65TO127;

    union
    {                           /* RMON Tx 128 to 255 byte packets */
        vuint32_t R;
    } RMON_T_P128TO255;

    union
    {                           /* RMON Tx 256 to 511 byte packets */
        vuint32_t R;
    } RMON_T_P256TO511;

    union
    {                           /* RMON Tx 512 to 1023 byte packets */
        vuint32_t R;
    } RMON_T_P512TO1023;

    union
    {                           /* RMON Tx 1024 to 2047 byte packets */
        vuint32_t R;
    } RMON_T_P1024TO2047;

    union
    {                           /* RMON Tx packets w > 2048 bytes */
        vuint32_t R;
    } RMON_T_P_GTE2048;

    union
    {                           /* RMON Tx Octets */
        vuint32_t R;
    } RMON_T_OCTETS;

    union
    {                           /* Count of frames not counted correctly */
        vuint32_t R;
    } IEEE_T_DROP;

    union
    {                           /* Frames Transmitted OK */
        vuint32_t R;
    } IEEE_T_FRAME_OK;

    union
    {                           /* Frames Transmitted with Single Collision */
        vuint32_t R;
    } IEEE_T_1COL;

    union
    {                           /* Frames Transmitted with Multiple Collisions */
        vuint32_t R;
    } IEEE_T_MCOL;

    union
    {                           /* Frames Transmitted after Deferral Delay */
        vuint32_t R;
    } IEEE_T_DEF;

    union
    {                           /* Frames Transmitted with Late Collision */
        vuint32_t R;
    } IEEE_T_LCOL;

    union
    {                           /* Frames Transmitted with Excessive Collisions */
        vuint32_t R;
    } IEEE_T_EXCOL;

    union
    {                           /* Frames Transmitted with Tx FIFO Underrun */
        vuint32_t R;
    } IEEE_T_MACERR;

    union
    {                           /* Frames Transmitted with Carrier Sense Error */
        vuint32_t R;
    } IEEE_T_CSERR;

    union
    {                           /* Frames Transmitted with SQE Error */
        vuint32_t R;
    } IEEE_T_SQE;

    union
    {                           /* Flow Control Pause frames transmitted */
        vuint32_t R;
    } T_FDXFC;

    union
    {                           /* Octet count  Frames Transmitted w/o Error */
        vuint32_t R;
    } IEEE_T_OCTETS_OK;

    int8_t FEC_reserved_0278[12];

    union
    {                           /* RMON Rx packet count */
        vuint32_t R;
    } RMON_R_PACKETS;

    union
    {                           /* RMON Rx Broadcast Packets */
        vuint32_t R;
    } RMON_R_BC_PKT;

    union
    {                           /* RMON Rx Multicast Packets */
        vuint32_t R;
    } RMON_R_MC_PKT;

    union
    {                           /* RMON Rx Packets w CRC/Align error */
        vuint32_t R;
    } RMON_R_CRC_ALIGN;

    union
    {                           /* RMON Rx Packets lt 64 bytes good crc */
        vuint32_t R;
    } RMON_R_UNDERSIZE;

    union
    {                           /* RMON Rx Packets gt MAX_FL bytes good crc */
        vuint32_t R;
    } RMON_R_OVERSIZE;

    union
    {                           /* Rx Packets lt 64 bytes bad crc */
        vuint32_t R;
    } RMON_R_FRAG;

    union
    {                           /* Rx Packets gt MAX_FL bytes bad crc */
        vuint32_t R;
    } RMON_R_JAB;

    union
    {                           /*  */
        vuint32_t R;
    } RMON_R_RESVD_0;

    union
    {                           /* Rx 64 byte packets */
        vuint32_t R;
    } RMON_R_P64;

    union
    {                           /* RMON Rx 65 to 127 byte packets */
        vuint32_t R;
    } RMON_R_P65TO127;

    union
    {                           /* RMON Rx 128 to 255 byte packets */
        vuint32_t R;
    } RMON_R_P128TO255;

    union
    {                           /* RMON Rx 256 to 511 byte packets */
        vuint32_t R;
    } RMON_R_P256TO511;

    union
    {                           /* RMON Rx 512 to 1023 byte packets */
        vuint32_t R;
    } RMON_R_P512TO1023;

    union
    {                           /* RMON Rx 1024 to 2047 byte packets */
        vuint32_t R;
    } RMON_R_P1024TO2047;

    union
    {                           /* RMON Rx packets w > 2048 bytes */
        vuint32_t R;
    } RMON_R_P_GTE2048;

    union
    {                           /* RMON Rx Octets */
        vuint32_t R;
    } RMON_R_OCTETS;

    union
    {                           /* Count of frames not counted correctly */
        vuint32_t R;
    } IEEE_R_DROP;

    union
    {                           /* Frames Received OK */
        vuint32_t R;
    } IEEE_R_FRAME_OK;

    union
    {                           /* Frames Received with CRC Error */
        vuint32_t R;
    } IEEE_R_CRC;

    union
    {                           /* Frames Received with Alignment Error */
        vuint32_t R;
    } IEEE_R_ALIGN;

    union
    {                           /* Receive Fifo Overflow count */
        vuint32_t R;
    } IEEE_R_MACERR;

    union
    {                           /* Control Pause frames received */
        vuint32_t R;
    } R_FDXFC;

    union
    {                           /* Octet count  Frames Rcvd w/o Error */
        vuint32_t R;
    } IEEE_R_OCTETS_OK;
};

typedef struct
{
    volatile unsigned short status; /* Control and status info. */
    volatile unsigned short length; /* Data length. */
    const unsigned char *bufferPointer; /* Buffer pointer. */
}
BufferDescriptor;

/* Buffer descriptor control/status used by Ethernet receive.
*/
#define BD_ENET_RX_EMPTY        (0x8000)
#define BD_ENET_RX_WRAP         (0x2000)
#define BD_ENET_RX_LAST         (0x0800)
#define BD_ENET_RX_PTP          (0x0400)
#define BD_ENET_RX_MISS         (0x0100)
#define BD_ENET_RX_BC           (0x0080)    /*is set if the DA is broadcast (FF:FF:FF:FF:FF:FF) */
#define BD_ENET_RX_MC           (0x0040)    /*s set if the DA is multicast and not BC */
#define BD_ENET_RX_LG           (0x0020)    /* Rx frame length violation */
#define BD_ENET_RX_NO           (0x0010)    /* Receive non-octet aligned frame */
#define BD_ENET_RX_CR           (0x0004)    /* Receive CRC error */
#define BD_ENET_RX_OV           (0x0002)    /* Overrun */
#define BD_ENET_RX_TR           (0x0001)    /* s set if the receive frame is truncated (frame length > 2047 bytes) */
/* Buffer descriptor control/status used by Ethernet transmit.
*/
#define BD_ENET_TX_READY        (0x8000)
#define BD_ENET_TX_WRAP         (0x2000)
#define BD_ENET_TX_LAST         (0x0800)
#define BD_ENET_TX_TC           (0x0400)
#define BD_ENET_TX_ABC          (0x0200)    /* Append bad CRC */
#define BD_ENET_TX_PTP          (0x0100)


// must multi of 16
#define RX_BUFF_MAX_LEN 160
#define RX_BUFF_NUM 50
#define RX_BUFF_DES_NUM RX_BUFF_NUM

#define TX_BUFF_NUM 10
#define TX_BUFF_DES_NUM (TX_BUFF_NUM*TX_FRAME_MAX_SEG)

#define MAX_RX_HANDLE_NUM 10
#define MAX_TX_HANDLE_NUM 10

// define flags
#define TX_FRAME_COMPLETE 1
#define TX_FRAME_NOT_COMPLETE 0
#define TX_FRAME_COMPLETE_ERROR 255

// define rx or tx handle max number
#define MAX_RX_OR_TX_HANDLE_NUM 10
#endif
