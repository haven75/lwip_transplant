/**************************************************************************
 * FILE NAME: MPC5604E.h                     COPYRIGHT (c) Freescale 2011 * 
 * REVISION:  1.0                                     All Rights Reserved *
 *                                                                        *
 * DESCRIPTION:                                                           *
 * This file contain all of the register and bit field definitions for    *
 * MPC5604E.                                                              *
 *========================================================================*
 * UPDATE HISTORY                                                         *
 * REV      AUTHOR      DATE       DESCRIPTION OF CHANGE                  *
 * ---   -----------  ---------    ---------------------                  *
 * 0.1  Pavel Bohacik 22/Oct/10   Initial Prototype Release               *
 * 1.0	Pavel Bohacik 26/Sep/11	  Release version			  *
 *                                                                        *
 *========================================================================*
 * COPYRIGHT:                                                             *
 *	Freescale Semiconductor, INC. All Rights Reserved. You are hereby *
 *  granted a copyright license to use, modify, and distribute the        *
 *  SOFTWARE so long as this entire notice is retained without alteration *
 *  in any modified and/or redistributed versions, and that such modified *
 *  versions are clearly identified as such. No licenses are granted by   *
 *  implication, estoppel or otherwise under any patentsor trademarks     *
 *  of Freescale Semiconductor, Inc. This software is provided on an      *
 *  "AS IS" basis and without warranty.                                   *
 *                                                                        *
 *  To the maximum extent permitted by applicable law, Freescale          *
 *  Semiconductor DISCLAIMS ALL WARRANTIES WHETHER EXPRESS OR IMPLIED,    *
 *  INCLUDING IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A      *
 *  PARTICULAR PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH REGARD  *
 *  TO THE SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF) AND ANY     *
 *  ACCOMPANYING WRITTEN MATERIALS.                                       *
 *                                                                        *
 *  To the maximum extent permitted by applicable law, IN NO EVENT        *
 *  SHALL Freescale Semiconductor BE LIABLE FOR ANY DAMAGES WHATSOEVER    *
 *  (INCLUDING WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS,  *
 *  BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER         *
 *  PECUNIARY LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.  *
 *                                                                        *
 *  Freescale Semiconductor assumes no responsibility for the             *
 *  maintenance and support of this software                              *
 *                                                                        *
 **************************************************************************/ 
/**************************************************************************
 * Example register & bit field write:                                    *
 *                                                                        *
 *  <MODULE>.<REGISTER>.B.<BIT> = 1;                                      *
 *  <MODULE>.<REGISTER>.R       = 0x10000000;                             *
 *                                                                        *
 **************************************************************************/

#ifndef _MPC5604E_H_  /* _<device>_H_ */
#define _MPC5604E_H_  /* _<device>_H_ */

#include "typedefs.h"

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef __MWERKS__
#pragma push
#pragma ANSI_strict off
#endif

/* Define memories - based on Salsa*/

// 512K SRAM
#define SRAM_START    0x40000000
#define SRAM_SIZE        0x18000
#define SRAM_END      0x40017FFF

// 512KB CODE FLASH - 
#define CFLASH_START         0x0
#define CFLASH_SIZE      0x80000
#define CFLASH_END       0x7FFFF

// 64kB DATA FLASH
#define DFLASH_START    0x800000
#define DFLASH_SIZE      0x10000
#define DFLASH_END      0x80FFFF
/****************************************************************/
/*                                                              */
/* Module: CFLASH_SHADOW  */
/*                                                              */
/****************************************************************/
struct CFLASH_SHADOW_tag {

    int8_t CFLASH_SHADOW_reserved_0000[15832];
    union {   /* NVPWD0-1 - Non Volatile Private Censorship PassWorD Register */
	vuint32_t R;
	struct {
	    vuint32_t  PWD:32;   /* PassWorD */
	} B;
    } NVPWD0;

    union {   /* NVPWD0-1 - Non Volatile Private Censorship PassWorD Register */
	vuint32_t R;
	struct {
	    vuint32_t  PWD:32;   /* PassWorD */
	} B;
    } NVPWD1;

    union {   /* NVSCI - Non Volatile System Censoring Information Register */
	vuint32_t R;
	struct {
	    vuint32_t  SC:16;   /* Serial Censorship Control Word */
	    vuint32_t  CW:16;   /* Censorship Control Word */
	} B;
    } NVSCI0;

    union {   /* NVSCI - Non Volatile System Censoring Information Register */
	vuint32_t R;
	struct {
	    vuint32_t  SC:16;   /* Serial Censorship Control Word */
	    vuint32_t  CW:16;   /* Censorship Control Word */
	} B;
    } NVSCI1;
    int8_t CFLASH_SHADOW_reserved_3DE8[24];
    union {   /* Non Volatile Bus Interface Unit Register */
	vuint32_t R;
	struct {
	    vuint32_t  BI:32;   /* Bus interface Unit */
	} B;
    } NVBIU2;
    int8_t CFLASH_SHADOW_reserved_3E04[4];
    union {   /* Non Volatile Bus Interface Unit Register */
	vuint32_t R;
	struct {
	    vuint32_t  BI:32;   /* Bus interface Unit */
	} B;
    } NVBIU3;
    int8_t CFLASH_SHADOW_reserved_3E0C[12];
    union {   /* NVUSRO - Non Volatile USeR Options Register */
	vuint32_t R;
	struct {
	    vuint32_t  UO:32;   /* User Options */
	} B;
    } NVUSRO;
};                                                

/****************************************************************/
/*                                                              */
/* Module: PFLASH  */
/*                                                              */
/****************************************************************/
struct PFLASH_tag {
    int8_t CFLASH_reserved_0000[0x1C];
    union {   
	vuint32_t R;
	struct {
	    vuint32_t  BK0_APC:5;   
	    vuint32_t  BK0_WWSC:5;
	    vuint32_t  BK0_RWSC:5;
	    vuint32_t  BK0_RWWC2:1;
	    vuint32_t  BK0_RWWC1:1;
	    vuint32_t:7;
	    vuint32_t  BK0_RWWC0:1;
	    vuint32_t  B0_P0_BCFG:2;
	    vuint32_t  B0_P0_DPFE:1;
	    vuint32_t  B0_P0_IPFE:1;
	    vuint32_t  B0_P0_PFLM:2;
	    vuint32_t  B0_P0_BFE:1;
	} B;
    } PFCR0;

    union {   
	vuint32_t R;
	struct {
	    vuint32_t  BK1_APC:5;   
	    vuint32_t  BK1_WWSC:5;
	    vuint32_t  BK1_RWSC:5;
	    vuint32_t  BK1_RWWC2:1;
	    vuint32_t  BK1_RWWC1:1;
	    vuint32_t:6;
	    vuint32_t  B1_P1_BFE:1;
	    vuint32_t  BK1_RWWC0:1;
	    vuint32_t:6;
	    vuint32_t  B0_P0_BFE:1;
	} B;
    } PFCR1;

    union {   
	vuint32_t R;
	struct {
	    vuint32_t:6;
	    vuint32_t  ARBM:2;   
	    vuint32_t  M7PFD:1;
	    vuint32_t  M6PFD:1;
	    vuint32_t  M5PFD:1;
	    vuint32_t  M4PFD:1;
	    vuint32_t  M3PFD:1;
	    vuint32_t  M2PFD:1;
	    vuint32_t  M1PFD:1;
	    vuint32_t  M0PFD:1;
	    vuint32_t  M7AP:2;
	    vuint32_t  M6AP:2;
	    vuint32_t  M5AP:2;
	    vuint32_t  M4AP:2;
	    vuint32_t  M3AP:2;
	    vuint32_t  M2AP:2;
	    vuint32_t  M1AP:2;
	    vuint32_t  M0AP:2;
	} B;
    } PFAPR;
};

/****************************************************************/
/*                                                              */
/* Module: CFLASH  */
/*                                                              */
/****************************************************************/
struct CFLASH_tag
{
    union {   /* MCR - Module Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t  EDC:1;   /* ECC Data Correction */
	    vuint32_t:4;
	    vuint32_t  SIZE2:1;   /* Array Space Size */
	    vuint32_t  SIZE1:1;   /* Array Space Size */
	    vuint32_t  SIZE0:1;   /* Array Space Size */
	    vuint32_t:1;
	    vuint32_t  LAS2:1;   /* Low Address Space */
	    vuint32_t  LAS1:1;   /* Low Address Space */
	    vuint32_t  LAS0:1;   /* Low Address Space */
	    vuint32_t:3;
	    vuint32_t  MAS:1;   /* Mid Address Space Configuration */
	    vuint32_t  EER:1;   /* ECC Event Error */
	    vuint32_t  RWE:1;   /* Read-while-Write Event Error */
	    vuint32_t:2;
	    vuint32_t  PEAS:1;   /* Program/Erase Access Space */
	    vuint32_t  DONE:1;   /* modify operation DONE */
	    vuint32_t  PEG:1;   /* Program/Erase Good */
	    vuint32_t:4;
	    vuint32_t  PGM:1;   /* Program Bit */
	    vuint32_t  PSUS:1;   /* Program Suspend */
	    vuint32_t  ERS:1;   /* Erase Bit */
	    vuint32_t  ESUS:1;   /* Erase Suspend */
	    vuint32_t  EHV:1;   /* Enable High Voltage */
	} B;
    } MCR;

    union {   /* LML - Low/Mid Address Space Block Locking Register */
	vuint32_t R;
	struct {
	    vuint32_t  LME:1;   /* Low/Mid Address Space Block Enable */
	    vuint32_t:10;
	    vuint32_t  TSLK:1;   /* Test/Shadow Address Space Block Lock */
	    vuint32_t:2;
	    vuint32_t  MLK1:1;   /* Mid Address Space Block Lock */
	    vuint32_t  MLK0:1;   /* Mid Address Space Block Lock */
	    vuint32_t:8;
	    vuint32_t  LLK7:1;   /* Low Address Space Block Lock */
	    vuint32_t  LLK6:1;   /* Low Address Space Block Lock */
	    vuint32_t  LLK5:1;   /* Low Address Space Block Lock */
	    vuint32_t  LLK4:1;   /* Low Address Space Block Lock */
	    vuint32_t  LLK3:1;   /* Low Address Space Block Lock */
	    vuint32_t  LLK2:1;   /* Low Address Space Block Lock */
	    vuint32_t  LLK1:1;   /* Low Address Space Block Lock */
	    vuint32_t  LLK0:1;   /* Low Address Space Block Lock */
	} B;
    } LML;

    union {   /* HBL - High Address Space Block Locking Register */
	vuint32_t R;
	struct {
	    vuint32_t  HBE:1;   /* High Address Space Block Enable */
	    vuint32_t:31;
	} B;
    } HBL;

    union {   /* SLL - Secondary Low/Mid Address Space Block Locking Register */
	vuint32_t R;
	struct {
	    vuint32_t  SLE:1;   /* Secondary Low/Mid Address Space Block Enable */
	    vuint32_t:10;
	    vuint32_t  STSLK:1;   /* Secondary Test/Shadow Address Space Block Lock */
	    vuint32_t:2;
	    vuint32_t  SMK1:1;   /* Secondary Mid Address Space Block Lock */
	    vuint32_t  SMK0:1;   /* Secondary Mid Address Space Block Lock */
	    vuint32_t:8;
	    vuint32_t  SLK7:1;   /* Secondary Low Address Space Block Lock */
	    vuint32_t  SLK6:1;   /* Secondary Low Address Space Block Lock */
	    vuint32_t  SLK5:1;   /* Secondary Low Address Space Block Lock */
	    vuint32_t  SLK4:1;   /* Secondary Low Address Space Block Lock */
	    vuint32_t  SLK3:1;   /* Secondary Low Address Space Block Lock */
	    vuint32_t  SLK2:1;   /* Secondary Low Address Space Block Lock */
	    vuint32_t  SLK1:1;   /* Secondary Low Address Space Block Lock */
	    vuint32_t  SLK0:1;   /* Secondary Low Address Space Block Lock */
	} B;
    } SLL;

    union {   /* LMS - Low/Mid Address Space Block Select Register */
	vuint32_t R;
	struct {
	    vuint32_t:14;
	    vuint32_t  MSL1:1;   /* Mid Address Space Block Select */
	    vuint32_t  MSL0:1;   /* Mid Address Space Block Select */
	    vuint32_t:8;
	    vuint32_t  LSL7:1;   /* Low Address Space Block Select */
	    vuint32_t  LSL6:1;   /* Low Address Space Block Select */
	    vuint32_t  LSL5:1;   /* Low Address Space Block Select */
	    vuint32_t  LSL4:1;   /* Low Address Space Block Select */
	    vuint32_t  LSL3:1;   /* Low Address Space Block Select */
	    vuint32_t  LSL2:1;   /* Low Address Space Block Select */
	    vuint32_t  LSL1:1;   /* Low Address Space Block Select */
	    vuint32_t  LSL0:1;   /* Low Address Space Block Select */
	} B;
    } LMS;

    union {   /* HBS - High Address Space Block Select Register */
	vuint32_t R;
	struct { 
	    vuint32_t:32; 
	}B;
    } HBS;

    union {   /* ADR - Address Register */
	vuint32_t R;
	struct {
	    vuint32_t  SAD:1;   /* Shadow Address */
	    vuint32_t  TAD:1;   /* Test Address */
	    vuint32_t:9;
	    vuint32_t  AD20:1;   /* Address */
	    vuint32_t  AD19:1;   /* Address */
	    vuint32_t  AD18:1;   /* Address */
	    vuint32_t  AD17:1;   /* Address */
	    vuint32_t  AD16:1;   /* Address */
	    vuint32_t  AD15:1;   /* Address */
	    vuint32_t  AD14:1;   /* Address */
	    vuint32_t  AD13:1;   /* Address */
	    vuint32_t  AD12:1;   /* Address */
	    vuint32_t  AD11:1;   /* Address */
	    vuint32_t  AD10:1;   /* Address */
	    vuint32_t  AD9:1;   /* Address */
	    vuint32_t  AD8:1;   /* Address */
	    vuint32_t  AD7:1;   /* Address */
	    vuint32_t  AD6:1;   /* Address */
	    vuint32_t  AD5:1;   /* Address */
	    vuint32_t  AD4:1;   /* Address */
	    vuint32_t  AD3:1;   /* Address */
	    vuint32_t:3;
	} B;
    } ADR;

    union {   /* Bus Interface Unit Register */
	vuint32_t R;
	struct {
	    vuint32_t  BI:32;   /* Bus Interface */
	} B;
    } BIU0;

    union {   /* Bus Interface Unit Register */
	vuint32_t R;
	struct {
	    vuint32_t  BI:32;   /* Bus Interface */
	} B;
    } BIU1;

    union {   /* Bus Interface Unit Register */
	vuint32_t R;
	struct {
	    vuint32_t  BI:32;   /* Bus Interface */
	} B;
    } BIU2;
    int8_t CFLASH_reserved_0028[20];
    union {   /* UT0 - User Test Register */
	vuint32_t R;
	struct {
	    vuint32_t  UTE:1;   /* User Test Enable */
	    vuint32_t  SBCE:1;   /* single bit correction enable */
	    vuint32_t:6;
	    vuint32_t  DSI7:1;   /* Data Syndrome Input */
	    vuint32_t  DSI6:1;   /* Data Syndrome Input */
	    vuint32_t  DSI5:1;   /* Data Syndrome Input */
	    vuint32_t  DSI4:1;   /* Data Syndrome Input */
	    vuint32_t  DSI3:1;   /* Data Syndrome Input */
	    vuint32_t  DSI2:1;   /* Data Syndrome Input */
	    vuint32_t  DSI1:1;   /* Data Syndrome Input */
	    vuint32_t  DSI0:1;   /* Data Syndrome Input */
	    vuint32_t:10;
	    vuint32_t  MRE:1;   /* Margin Read Enable */
	    vuint32_t  MRV:1;   /* Margin Read Value */
	    vuint32_t  EIE:1;   /* ECC Data Input Enable */
	    vuint32_t  AIS:1;   /* Array Integrity Sequence */
	    vuint32_t  AIE:1;   /* Array Integrity Enable */
	    vuint32_t  AID:1;   /* Array Integrity Done */
	} B;
    } UT0;

    union {   /* UT - User Test Register */
	vuint32_t R;
	struct {
	    vuint32_t  DAI:32;   /* Data Array Input */
	} B;
    } UT1;

    union {   /* UT - User Test Register */
	vuint32_t R;
	struct {
	    vuint32_t  DAI:32;   /* Data Array Input */
	} B;
    } UT2;

    union {   /* UMISR - User Multiple Input Signature Register */
	vuint32_t R;
	struct {
	    vuint32_t  MS:32;   /* Multiple Input Signature */
	} B;
    } UMISR[5];
};                                                

/****************************************************************/
/*                                                              */
/* Module: DFLASH  */
/*                                                              */
/****************************************************************/

struct DFLASH_tag
{
    union{   /* MCR - Module Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t  EDC:1;   /* ECC Data Correction */
	    vuint32_t:4;
	    vuint32_t  SIZE2:1;   /* Array Space Size */
	    vuint32_t  SIZE1:1;   /* Array Space Size */
	    vuint32_t  SIZE0:1;   /* Array Space Size */
	    vuint32_t:1;
	    vuint32_t  LAS2:1;   /* Low Address Space */
	    vuint32_t  LAS1:1;   /* Low Address Space */
	    vuint32_t  LAS0:1;   /* Low Address Space */
	    vuint32_t:1;
	    vuint32_t  MAS2:1;   /* Mid Address Space Configuration */
	    vuint32_t  MAS1:1;   /* Mid Address Space Configuration */
	    vuint32_t  MAS0:1;   /* Mid Address Space Configuration */
	    vuint32_t  EER:1;   /* ECC Event Error */
	    vuint32_t  RWE:1;   /* Read-while-Write Event Error */
	    vuint32_t:2;
	    vuint32_t  PEAS:1;   /* Program/Erase Access Space */
	    vuint32_t  DONE:1;   /* modify operation DONE */
	    vuint32_t  PEG:1;   /* Program/Erase Good */
	    vuint32_t:4;
	    vuint32_t  PGM:1;   /* Program Bit */
	    vuint32_t  PSUS:1;   /* Program Suspend */
	    vuint32_t  ERS:1;   /* Erase Bit */
	    vuint32_t  ESUS:1;   /* Erase Suspend */
	    vuint32_t  EHV:1;   /* Enable High Voltage */
	} B;
    } MCR;

    union{   /* LML - Low/Mid Address Space Block Locking Register */
	vuint32_t R;
	struct {
	    vuint32_t  LME:1;   /* Low/Mid Address Space Block Enable */
	    vuint32_t:10;
	    vuint32_t  TSLK:1;   /* Test/Shadow Address Space Block Lock */
	    vuint32_t:16;
	    vuint32_t  LLK3:1;   /* Low Address Space Block Lock */
	    vuint32_t  LLK2:1;   /* Low Address Space Block Lock */
	    vuint32_t  LLK1:1;   /* Low Address Space Block Lock */
	    vuint32_t  LLK0:1;   /* Low Address Space Block Lock */
	} B;
    } LML;
    int8_t DFLASH_reserved_0008[4];
    union{   /* SLL - Secondary Low/Mid Address Space Block Locking Register */
	vuint32_t R;
	struct {
	    vuint32_t  SLE:1;   /* Secondary Low/Mid Address Space Block Enable */
	    vuint32_t:10;
	    vuint32_t  STSLK:1;   /* Secondary Test/Shadow Address Space Block Lock */
	    vuint32_t:16;
	    vuint32_t  SLK3:1;   /* Secondary Low Address Space Block Lock */
	    vuint32_t  SLK2:1;   /* Secondary Low Address Space Block Lock */
	    vuint32_t  SLK1:1;   /* Secondary Low Address Space Block Lock */
	    vuint32_t  SLK0:1;   /* Secondary Low Address Space Block Lock */
	} B;
    } SLL;

    union{   /* LMS - Low/Mid Address Space Block Select Register */
	vuint32_t R;
	struct {
	    vuint32_t:28;
	    vuint32_t  LSL3:1;   /* Low Address Space Block Select */
	    vuint32_t  LSL2:1;   /* Low Address Space Block Select */
	    vuint32_t  LSL1:1;   /* Low Address Space Block Select */
	    vuint32_t  LSL0:1;   /* Low Address Space Block Select */
	} B;
    } LMS;
    int8_t DFLASH_reserved_0014[4];
    union{   /* ADR - Address Register */
	vuint32_t R;
	struct {
	    vuint32_t:9;
	    vuint32_t  AD:20;   /* Address */
	    vuint32_t:3;
	} B;
    } ADR;
    int8_t DFLASH_reserved_001C[32];
    union{   /* UT0 - User Test Register */
	vuint32_t R;
	struct {
	    vuint32_t  UTE:1;   /* User Test Enable */
	    vuint32_t  SBCE:1;   
	    vuint32_t:7;
	    vuint32_t  DSI:7;   /* Data Syndrome Input */
	    vuint32_t:10;
	    vuint32_t  MRE:1;   /* Margin Read Enable */
	    vuint32_t  MRV:1;   /* Margin Read Value */
	    vuint32_t  EIE:1;   /* ECC Data Input Enable */
	    vuint32_t  AIS:1;   /* Array Integrity Sequence */
	    vuint32_t  AIE:1;   /* Array Integrity Enable */
	    vuint32_t  AID:1;   /* Array Integrity Done */
	} B;
    } UT0;

    union{   /* UT - User Test Register */
	vuint32_t R;
	struct {
	    vuint32_t  DAI:32;   /* Data Array Input */
	} B;
    } UT1;
    int8_t DFLASH_reserved_0044[4];
    union{   /* UMISR - User Multiple Input Signature Register */
	vuint32_t R;
	struct {
	    vuint32_t  MS:32;   /* Multiple Input Signature */
	} B;
    } UMISR[2];
};                                                

/****************************************************************/
/*                                                              */
/* Module: SIUL  */
/*                                                              */
/****************************************************************/

struct SIUL_tag
{

    int8_t SIUL_reserved_0000[4];

    union {   /* MIDR1 - MCU ID Register #1 */
	vuint32_t R;
	struct {
	    vuint32_t  PARTNUM:16;   /* MCU Part Number */
	    vuint32_t  CSP:1;   /* CSP Package */
	    vuint32_t  PKG:5;   /* Package Settings */
	    vuint32_t:2;
	    vuint32_t  MAJOR_MASK:4;   /* Major Mask Revision */
	    vuint32_t  MINOR_MASK:4;   /* Minor Mask Revision */
	} B;
    } MIDR1;

    union {   /* MIDR2 - MCU ID Register #2 */
	vuint32_t R;
	struct {
	    vuint32_t  SF:1;   /* Manufacturer */
	    vuint32_t  FLASH_SIZE_1:4;   /* Coarse Flash Memory Size */
	    vuint32_t  FLASH_SIZE_2:4;   /* Fine Flash Memory Size */
	    vuint32_t:7;
	    vuint32_t  PARTNUM:8;   /* MCU Part Number */
	    vuint32_t:3;
	    vuint32_t  EE:1;   /* Data Flash Present */
	    vuint32_t:3;
	    vuint32_t  FR:1;   /* Flexray Present */
	} B;
    } MIDR2;

    int8_t SIUL_reserved_000C[8];

    union {   /* ISR - Interrupt Status Flag Register */
	vuint32_t R;
	struct {
	    vuint32_t  EIF:32;   /* External Interrupt Status Flag */
	} B;
    } ISR;

    union {   /* IRER - Interrupt Request Enable Register */
	vuint32_t R;
	struct {
	    vuint32_t  IRE:32;   /* Enable External Interrupt Requests */
	} B;
    } IRER;


    int8_t SIUL_reserved_001C[12];

    union {   /* IREER - Interrupt Rising Edge Event Enable */
	vuint32_t R;
	struct {
	    vuint32_t  IREE:32;   /* Enable rising-edge events */
	} B;
    } IREER;

    union {   /* IFEER - Interrupt Falling-Edge Event Enable */
	vuint32_t R;
	struct {
	    vuint32_t  IFEE:32;   /* Enable Falling Edge Events */
	} B;
    } IFEER;

    union {   /* IFER Interrupt Filter Enable Register */
	vuint32_t R;
	struct {
	    vuint32_t  IFE:32;   /* Enable Digital Glitch Filter */
	} B;
    } IFER;

    int8_t SIUL_reserved_0034[12];

    union {   /* PCR - Pad Configuration Register */
	vuint16_t R;
	struct {
	    vuint16_t:1;
	    vuint16_t  SMC:1;   /* Safe Mode Control */
	    vuint16_t  APC:1;   /* Analog Pad Control */
	    vuint16_t:1;
	    vuint16_t  PA:2;   /* Pad Output Assignment */
	    vuint16_t  OBE:1;   /* Output Buffer Enable */
	    vuint16_t  IBE:1;   /* Input Buffer Enable */
	    vuint16_t:2;   
	    vuint16_t  ODE:1;   /* Open Drain Output Enable */
	    vuint16_t:2;   
	    vuint16_t  SRC:1;   /* Slew Rate Control */
	    vuint16_t  WPE:1;   /* Weak Pull Up/Down Enable */
	    vuint16_t  WPS:1;   /* Weak Pull Up/Down Select */
	} B;
    } PCR[71];


    int8_t SIUL_reserved_00CE[1074];

    union {   /* PSMI - Pad Selection for Multiplexed Inputs */
	vuint8_t R;
	struct {
	    vuint8_t:4;
	    vuint8_t  PADSEL:4;   /* Pad selection for pin */
	} B;
    }PSMI[28]; 

    int8_t SIUL_reserved_051C[228];

    union {   /* GPDO - GPIO Pad Data Output Register */
	vuint8_t R;
	struct {
	    vuint8_t:7;
	    vuint8_t  PDO:1;   /* Pad Data Out */
	} B;
    }GPDO[72];

    int8_t SIUL_reserved_0648[440];


    union {   /* GPDI - GPIO Pad Data Input Register */
	vuint8_t R;
	struct {
	    vuint8_t:7;
	    vuint8_t  PDI:1;   /* Pad Data In */
	} B;
    } GPDI[72];

    int8_t SIUL_reserved_0848[952];

    union {   /* PGPDO - Parallel GPIO Pad Data Out Register */
	vuint32_t R;
	struct { 
	    vuint32_t PORTA:16;
	    vuint32_t PORTB:16;
	} B;
    } PGPDO0;
    union {   /* PGPDO - Parallel GPIO Pad Data Out Register */
	vuint32_t R;
	struct { 
	    vuint32_t PORTC:16;
	    vuint32_t PORTD:16;
	} B;
    } PGPDO1;

    union {   /* PGPDO - Parallel GPIO Pad Data Out Register */
	vuint32_t R;
	struct { 
	    vuint32_t PORTE:8;
	    vuint32_t:24;
	} B;
    } PGPDO2;

    int8_t SIUL_reserved_0C0C[52];


    union {   /* PGPDI - Parallel GPIO Pad Data In Register */
	vuint32_t R;
	struct { 
	    vuint32_t PORTA:16;
	    vuint32_t PORTB:16;
	} B;
    } PGPDI0;

    union {   /* PGPDI - Parallel GPIO Pad Data In Register */
	vuint32_t R;
	struct { 
	    vuint32_t PORTC:16;
	    vuint32_t PORTD:16;
	} B;
    } PGPDI1;
    union {   /* PGPDI - Parallel GPIO Pad Data In Register */
	vuint32_t R;
	struct { 
	    vuint32_t PORTE:8;
	    vuint32_t:24;
	} B;
    } PGPDI2;

    int8_t SIUL_reserved_0C4C[52];

    union {   /* MPGPDO - Masked Parallel GPIO Pad Data Out Register */
	vuint32_t R;
	struct { 
	    vuint32_t MASK0:16;
	    vuint32_t MPPDO0:16;
	} B;
    } MPGPDO0;

    union {   /* MPGPDO - Masked Parallel GPIO Pad Data Out Register */
	vuint32_t R;
	struct { 
	    vuint32_t MASK1:16;
	    vuint32_t MPPDO1:16;
	} B;
    } MPGPDO1;

    union {   /* MPGPDO - Masked Parallel GPIO Pad Data Out Register */
	vuint32_t R;
	struct { 
	    vuint32_t MASK2:16;
	    vuint32_t MPPDO2:16;
	} B;
    } MPGPDO2;

    union {   /* MPGPDO - Masked Parallel GPIO Pad Data Out Register */
	vuint32_t R;
	struct { 
	    vuint32_t MASK3:16;
	    vuint32_t MPPDO3:16;
	} B;
    } MPGPDO3;

    union {   /* MPGPDO - Masked Parallel GPIO Pad Data Out Register */
	vuint32_t R;
	struct { 
	    vuint32_t MASK4:8;
	    vuint32_t :8;
	    vuint32_t MPPDO4:8;
	    vuint32_t :8;
	} B;
    } MPGPDO4;

    int8_t SIUL_reserved_0C94[876];


    union {   /* IFMC - Interrupt Filter Maximum Counter Register */
	vuint32_t R;
	struct {
	    vuint32_t:28;
	    vuint32_t  MAXCNT:4;   /* Maximum Interrupt Filter Counter Setting */
	} B;
    } IFMC[32];

    union {   /* IFCPR - Inerrupt Filter Clock Prescaler Register */
	vuint32_t R;
	struct {
	    vuint32_t:28;
	    vuint32_t  IFCP:4;   /* Interrupt Filter Clock Prescaler Setting */
	} B;
    } IFCPR;
};

/****************************************************************/
/*                                                              */
/* Module: WKPU  */
/*                                                              */
/****************************************************************/

struct WKPU_tag {

    union {   /* WKPU_NSR - NMI Status Flag Register */
	vuint32_t R;
	struct {
	    vuint32_t  NIF0:1;   /* NMI Status Flag 0 */
	    vuint32_t  NOVF0:1;   /* NMI Overrun Status Flag 0 */
	    vuint32_t:30;
	} B;
    } NSR;

    int8_t WKPU_reserved_0004[4];

    union {   /* WKPU_NCR - NMI Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t  NLOCK0:1;   /* NMI Configuration Lock Register 0 */
	    vuint32_t  NDSS0:2;   /* NMI Desination Source Select 0 */
	    vuint32_t  NWRE0:1;   /* NMI Wakeup Request Enable 0 */
	    vuint32_t:1;
	    vuint32_t  NREE0:1;   /* NMI Rising Edge Events Enable 0 */
	    vuint32_t  NFEE0:1;   /* NMI Falling Edge Events Enable 0 */
	    vuint32_t  NFE0:1;   /* NMI Filter Enable 0 */
	    vuint32_t:24;
	} B;
    } NCR;
};                                                

/****************************************************************/
/*                                                              */
/* Module: SSCM  */
/*                                                              */
/****************************************************************/
struct SSCM_tag {
    union {   /* SSCM_STATUS - System Status Register */
	vuint16_t R;
	struct {
	    vuint16_t:4;
	    vuint16_t  NXEN:1;   /* Security Status */
	    vuint16_t  PUB:1;   /* Public Serial Access Status */
	    vuint16_t  SEC:1;   /* Security Status */
	    vuint16_t:1;
	    vuint16_t  BMODE:3;   /* Device Boot Mode */
	    vuint16_t:1;
	    vuint16_t  ABD:1;   /* Autobaud detection */
	    vuint16_t:3;
	} B;
    } STATUS;


    union {   /* SSCM_MEMCONFIG - System Memory Configuration Register */
	vuint16_t R;
	struct {
	    vuint16_t  JPIN:10;   /* SRAM Size */
	    vuint16_t  IVLD:1;   /* Instruction Flash Valid */
	    vuint16_t  MREV:4;   /* Data Flash Size */
	    vuint16_t  DVLD:1;   /* Data Flash Valid */
	} B;
    } MEMCONFIG;

    int8_t SSCM_reserved_0004[2];

    union {   /* SSCM_ERROR - Error Configuration */
	vuint16_t R;
	struct {
	    vuint16_t:14;
	    vuint16_t  PAE:1;   /* Peripheral Bus Abort Enable */
	    vuint16_t  RAE:1;   /* Register Bus Abort Enable */
	} B;
    } ERROR;

    union {   /* SSCM_DEBUGPORT - Debug Status Port Register */
	vuint16_t R;
	struct {
	    vuint16_t:13;
	    vuint16_t  DEBUG_MODE:3;   /* Debug Status Port Mode */
	} B;
    } DEBUGPORT;

    int8_t SSCM_reserved_000A[22];

    union {   /* SSCM_User_Option_Status  - User Option Status Register */
	vuint32_t R;
	struct {
	    vuint32_t  UOPT:32;   /* Shows the values read from the User Option Bits location in the */
	} B;
    } UOPS;

    int8_t SSCM_reserved_0024[4];

    union {   
	vuint32_t R;
	struct {
	    vuint32_t  SADR:32;   
	} B;
    } PBAR;
};                                                

/****************************************************************/
/*                                                              */
/* Module: ME  */
/*                                                              */
/****************************************************************/


struct ME_tag {

    union {   /* ME_GS - Global Status Register */
	vuint32_t R;
	struct {
	    vuint32_t  S_CURRENT_MODE:4;   /* Current device mode status */
	    vuint32_t  S_MTRANS:1;   /* Mode transition status */
	    vuint32_t:3;
	    vuint32_t  S_PDO:1;   /* Output power-down status */
	    vuint32_t:2;
	    vuint32_t  S_MVR:1;   /* Main voltage regulator status */
	    vuint32_t  S_DFLA:2;   /* Data flash availability status */
	    vuint32_t  S_CFLA:2;   /* Code flash availability status */
	    vuint32_t:9;   
	    vuint32_t  S_FMPLL_0:1;   /* System PLL status */
	    vuint32_t  S_XOSC:1;   /* System crystal oscillator status */
	    vuint32_t  S_IRC:1;   /* System RC oscillator status */
	    vuint32_t  S_SYSCLK:4;   /* System clock switch status */
	} B;
    } GS;

    union {   /* ME_MCTL - Mode Control Register */
	vuint32_t R;
	struct {
	    vuint32_t  TARGET_MODE:4;   /* Target device mode */
	    vuint32_t:12;
	    vuint32_t  KEY:16;   /* Control key */
	} B;
    } MCTL;

    union {   /* ME_ME - Mode Enable Register */
	vuint32_t R;
	struct {
	    vuint32_t:21;
	    vuint32_t  STOP0:1;   /* STOP0 mode enable */
	    vuint32_t:1;
	    vuint32_t  HALT0:1;   /* HALT0 mode enable */
	    vuint32_t  RUN3:1;   /* RUN3 mode enable */
	    vuint32_t  RUN2:1;   /* RUN2 mode enable */
	    vuint32_t  RUN1:1;   /* RUN1 mode enable */
	    vuint32_t  RUN0:1;   /* RUN0 mode enable */
	    vuint32_t  DRUN:1;   /* DRUN mode enable */
	    vuint32_t  SAFE:1;   /* SAFE mode enable */
	    vuint32_t  TEST:1;   /* TEST mode enable */
	    vuint32_t  RESET_FUNC:1;   /* RESET mode enable */
	} B;
    } MER;

    union {   /* ME_IS - Interrupt Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:27;
	    vuint32_t  I_ICONF_CU:1;   /* Invalid mode configuration interrupt (Clock Usage) */
	    vuint32_t  I_ICONF:1;   /* Invalid mode config interrupt */
	    vuint32_t  I_IMODE:1;   /* Invalid mode interrupt */
	    vuint32_t  I_SAFE:1;   /* SAFE mode interrupt */
	    vuint32_t  I_MTC:1;   /* Mode transition complete interrupt */
	} B;
    } IS;

    union {   /* ME_IM - Interrupt Mask Register */
	vuint32_t R;
	struct {
	    vuint32_t:27;
	    vuint32_t  M_ICONF_CU:1;   /* Invalid mode configuration (clock usage) interrupt mask */
	    vuint32_t  M_ICONF:1;   /* Invalid mode config interrupt mask */
	    vuint32_t  M_IMODE:1;   /* Invalid mode interrupt mask */
	    vuint32_t  M_SAFE:1;   /* SAFE mode interrupt mask */
	    vuint32_t  M_MTC:1;   /* Mode transition complete interrupt mask */
	} B;
    } IM;

    union {   /* ME_IMTS - Invalid Mode Transition Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:27;
	    vuint32_t  S_MTI:1;   /* Mode Transition Illegal status */
	    vuint32_t  S_MRI:1;   /* Mode Request Illegal status */
	    vuint32_t  S_DMA:1;   /* Disabled Mode Access status */
	    vuint32_t  S_NMA:1;   /* Non-existing Mode Access status */
	    vuint32_t  S_SEA:1;   /* Safe Event Active status */
	} B;
    } IMTS;

    union {   /* ME_DMTS - Debug Mode Transition Status Register */
	vuint32_t R;
	struct {
	    vuint32_t PREVIOUS_MODE:4;
	    vuint32_t:4;
	    vuint32_t  MPH_BUSY:1;   /* MC_ME/MC_PCU Handshake Busy Indicator */
	    vuint32_t:2;
	    vuint32_t  PMC_PROG:1;   /* MC_PCU Mode Change in Process Indicator */
	    vuint32_t  CORE_DBG:1;   /* Processor is in Debug Mode Indicator */
	    vuint32_t:2;
	    vuint32_t  SMR:1;   /* SAFE Mode Request */
	    vuint32_t:1;
	    vuint32_t  VREG_CSRC_SC:1;   
	    vuint32_t  CSRC_CSRC_SC:1;   
	    vuint32_t  IRC_SC:1;   /* RC State Change */
	    vuint32_t  SCSRC_SC:1;   /* Secondary System Clock Sources State Change */
	    vuint32_t  SYSCLK_SW:1;   /* System Clock Switching pending Status */
	    vuint32_t  DFLASH_SC:1;   /* DFLASH State Change */
	    vuint32_t  CFLASH_SC:1;   /* CFLASH State Change */
	    vuint32_t  CDP_PRPH_0_143:1;   /* Clock Disable Process Pending Status for Periph. 0-143 */
	    vuint32_t:3;
	    vuint32_t  CDP_PRPH_96_127:1;   /* Clock Disable Process Pending Status for Periph. 96-127 */
	    vuint32_t  CDP_PRPH_64_95:1;   /* Clock Disable Process Pending Status for Periph. 64-95 */
	    vuint32_t  CDP_PRPH_32_63:1;   /* Clock Disable Process Pending Status for Periph. 32-63 */
	    vuint32_t  CDP_PRPH_0_31:1;   /* Clock Disable Process Pending Status for Periph. 0-31 */
	} B;
    } DMTS;

    int8_t ME_reserved_001C[4];

    union {   /* ME_RESET_MC - RESET Mode Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t:8;
	    vuint32_t  PDO:1;   /* IOs output power-down control */
	    vuint32_t:2;
	    vuint32_t  MVRON:1;   /* Main voltage regulator control */
	    vuint32_t  DFLAON:2;   /* Data flash power-down control */
	    vuint32_t  CFLAON:2;   /* Code flash power-down control */
	    vuint32_t:9;  
	    vuint32_t  FMPLL0_ON:1;   /* System PLL control */
	    vuint32_t  XOSCON:1;   /* System crystal oscillator control */
	    vuint32_t  IRCON:1;   /* System RC oscillator control */
	    vuint32_t  SYSCLK:4;   /* System clock switch control */
	} B;
    } RESET;

    union {   /* ME_TEST_MC - TEST Mode Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t:8;
	    vuint32_t  PDO:1;   /* IOs output power-down control */
	    vuint32_t:2;
	    vuint32_t  MVRON:1;   /* Main voltage regulator control */
	    vuint32_t  DFLAON:2;   /* Data flash power-down control */
	    vuint32_t  CFLAON:2;   /* Code flash power-down control */
	    vuint32_t:9;  
	    vuint32_t  FMPLL0_ON:1;   /* System PLL control */
	    vuint32_t  XOSCON:1;   /* System crystal oscillator control */
	    vuint32_t  IRCON:1;   /* System RC oscillator control */
	    vuint32_t  SYSCLK:4;   /* System clock switch control */
	} B;
    } TEST;

    union {   /* ME_SAFE_MC - Mode Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t:8;
	    vuint32_t  PDO:1;   /* IOs output power-down control */
	    vuint32_t:2;
	    vuint32_t  MVRON:1;   /* Main voltage regulator control */
	    vuint32_t  DFLAON:2;   /* Data flash power-down control */
	    vuint32_t  CFLAON:2;   /* Code flash power-down control */
	    vuint32_t:9;  
	    vuint32_t  FMPLL0_ON:1;   /* System PLL control */
	    vuint32_t  XOSCON:1;   /* System crystal oscillator control */
	    vuint32_t  IRCON:1;   /* System RC oscillator control */
	    vuint32_t  SYSCLK:4;   /* System clock switch control */
	} B;
    } SAFE;

    union {   /* ME_DRUN_MC - DRUN Mode Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t:8;
	    vuint32_t  PDO:1;   /* IOs output power-down control */
	    vuint32_t:2;
	    vuint32_t  MVRON:1;   /* Main voltage regulator control */
	    vuint32_t  DFLAON:2;   /* Data flash power-down control */
	    vuint32_t  CFLAON:2;   /* Code flash power-down control */
	    vuint32_t:9;  
	    vuint32_t  FMPLL0_ON:1;   /* System PLL control */
	    vuint32_t  XOSCON:1;   /* System crystal oscillator control */
	    vuint32_t  IRCON:1;   /* System RC oscillator control */
	    vuint32_t  SYSCLK:4;   /* System clock switch control */
	} B;
    } DRUN;

    union {   /* ME_RUN[0..3]_MC - RUN[0..3] Mode Configuration Registers */
	vuint32_t R;
	struct {
	    vuint32_t:8;
	    vuint32_t  PDO:1;   /* IOs output power-down control */
	    vuint32_t:2;
	    vuint32_t  MVRON:1;   /* Main voltage regulator control */
	    vuint32_t  DFLAON:2;   /* Data flash power-down control */
	    vuint32_t  CFLAON:2;   /* Code flash power-down control */
	    vuint32_t:9;  
	    vuint32_t  FMPLL0_ON:1;   /* System PLL control */
	    vuint32_t  XOSCON:1;   /* System crystal oscillator control */
	    vuint32_t  IRCON:1;   /* System RC oscillator control */
	    vuint32_t  SYSCLK:4;   /* System clock switch control */
	} B;
    } RUN[4];

    union {   /* ME_HALT0_MC - HALT0 Mode Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t:8;
	    vuint32_t  PDO:1;   /* IOs output power-down control */
	    vuint32_t:2;
	    vuint32_t  MVRON:1;   /* Main voltage regulator control */
	    vuint32_t  DFLAON:2;   /* Data flash power-down control */
	    vuint32_t  CFLAON:2;   /* Code flash power-down control */
	    vuint32_t:9;  
	    vuint32_t  FMPLL0_ON:1;   /* System PLL control */
	    vuint32_t  XOSCON:1;   /* System crystal oscillator control */
	    vuint32_t  IRCON:1;   /* System RC oscillator control */
	    vuint32_t  SYSCLK:4;   /* System clock switch control */
	} B;
    } HALT0;

    int8_t ME_reserved_0044[4];

    union {   /* ME_STOP0_MC - STOP0 Mode Configration Register */
	vuint32_t R;
	struct {
	    vuint32_t:8;
	    vuint32_t  PDO:1;   /* IOs output power-down control */
	    vuint32_t:2;
	    vuint32_t  MVRON:1;   /* Main voltage regulator control */
	    vuint32_t  DFLAON:2;   /* Data flash power-down control */
	    vuint32_t  CFLAON:2;   /* Code flash power-down control */
	    vuint32_t:9;  
	    vuint32_t  FMPLL0_ON:1;   /* System PLL control */
	    vuint32_t  XOSCON:1;   /* System crystal oscillator control */
	    vuint32_t  IRCON:1;   /* System RC oscillator control */
	    vuint32_t  SYSCLK:4;   /* System clock switch control */
	} B;
    } STOP0;

    int8_t ME_reserved_004C[20];

    union {   /* ME_PS[0..4] - Peripheral Status Registers */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t  S_Video:1;
	    vuint32_t  S_SAI2:1;
	    vuint32_t  S_SAI1:1;
	    vuint32_t:4;
	    vuint32_t	S_DMA_CH_MUX:1;
	    vuint32_t	S_SAI0:1;
	    vuint32_t:5;
	    vuint32_t	S_FlexCAN0:1;
	    vuint32_t:9;
	    vuint32_t	S_DSPI2:1;
	    vuint32_t	S_DSPI1:1;
	    vuint32_t	S_DSPI0:1;
	    vuint32_t:4;
	} B;
    } PS0;

    union {   /* ME_PS[0..4] - Peripheral Status Registers */
	vuint32_t R;
	struct {
	    vuint32_t:1;
	    vuint32_t  S_RTC:1;
	    vuint32_t	S_PTP:1;
	    vuint32_t:2;
	    vuint32_t	S_CRC:1;
	    vuint32_t:8;
	    vuint32_t	S_LIN_FLEX1:1;
	    vuint32_t	S_LIN_FLEX0:1;
	    vuint32_t:2;
	    vuint32_t	S_I2C_DMA1:1;
	    vuint32_t	S_I2C_DMA0:1;
	    vuint32_t:5;
	    vuint32_t	S_eTimer0:1;
	    vuint32_t:5;
	    vuint32_t	S_ADC0:1;
	} B;
    } PS1;

    union {   /* ME_PS[0..4] - Peripheral Status Registers */
	vuint32_t R;
	struct {
	    vuint32_t:3;
	    vuint32_t	S_PIT_RTI:1;
	    vuint32_t:28;
	} B;
    } PS2;

    union {   /* ME_PS[0..4] - Peripheral Status Registers */
	vuint32_t R;
	struct {
	    vuint32_t:23;
	    vuint32_t	S_CMU0:1;
	    vuint32_t:8;
	} B;
    } PS3;

    int8_t ME_reserved_006C[16];

    union {   
	vuint32_t R;
	struct {
	    vuint32_t:24;
	    vuint32_t  RUN3:1;   /* Peripheral control during RUN3 */
	    vuint32_t  RUN2:1;   /* Peripheral control during RUN2 */
	    vuint32_t  RUN1:1;   /* Peripheral control during RUN1 */
	    vuint32_t  RUN0:1;   /* Peripheral control during RUN0 */
	    vuint32_t  DRUN:1;   /* Peripheral control during DRUN */
	    vuint32_t  SAFE:1;   /* Peripheral control during SAFE */
	    vuint32_t  TEST:1;   /* Peripheral control during TEST */
	    vuint32_t  RESET:1;   /* Peripheral control during RESET */
	} B;
    } RUN_PC[8];

    union {   
	vuint32_t R;
	struct {
	    vuint32_t:21;
	    vuint32_t  STOP0:1;   /* Peripheral control during STOP0 */
	    vuint32_t:1;
	    vuint32_t  HALT0:1;   /* Peripheral control during HALT0 */
	    vuint32_t:8;
	} B;
    } LP_PC[8];

    union {   
	vuint8_t R;
	struct {
	    vuint8_t:1;
	    vuint8_t  DBG_F:1;   /* Peripheral control in debug mode */
	    vuint8_t  LP_CFG:3;   /* Peripheral configuration select for non-RUN modes */
	    vuint8_t  RUN_CFG:3;   /* Peripheral configuration select for RUN modes */
	} B;
    } PCTL[144];
};                                                

/****************************************************************/
/*                                                              */
/* Module: CGM  */
/*                                                              */
/****************************************************************/
struct CGM_tag {
    union {/* XOSC_CTL - Control Register */
	vuint32_t R;
	struct {
	    vuint32_t  OSCBYP:1;   /* High Frequency Oscillator Bypass */
	    vuint32_t:7;
	    vuint32_t  EOCV:8;   /* End of Count Value */
	    vuint32_t  M_OSC:1;   /* High Frequency Oscillator Clock Interrupt Mask */
	    vuint32_t:7;
	    vuint32_t  I_OSC:1;   /* High Frequency Oscillator Clock Interrupt */
	    vuint32_t:7;
	} B;
    } XOSC_CTL;

    int8_t CGM_reserved_004[0x5C];

    union {   /* IRC_CTL - Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:10;
	    vuint32_t  IRCTRIM:6;   /* Main RC Trimming Bits */
	    vuint32_t:10;
	    vuint32_t  IRCON_STDBY:1;   /* MRC Oscillator Powerdown Status */
	    vuint32_t:5;
	} B;
    } IRC_CTL;

    int8_t CGM_reserved_064[0x3C];

    union {   /* FMPLL_CR - Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:2;
	    vuint32_t  IDF:4;   /* PLL Input Division Factor */
	    vuint32_t  ODF:2;   /* PLL Output Division Factor */
	    vuint32_t:1;
	    vuint32_t  NDIV:7;   /* PLL Loop Division Factor */
	    vuint32_t:7;
	    vuint32_t  EN_PLL_SW:1;   /* Enable Progressive Clock Switching */
	    vuint32_t:3;   
	    vuint32_t  I_LOCK:1;   /* PLL Lock Signal Toggle Indicator */
	    vuint32_t  S_LOCK:1;   /* PLL has Aquired Lock */
	    vuint32_t  PLL_FAIL_MASK:1;   /* PLL Fail Mask */
	    vuint32_t  PLL_FAIL_FLAG:1;   /* PLL Fail Flag */
	    vuint32_t:1;
	} B;
    } FMPLL_CR;

    union {   /* FMPLL_MR - PLLD Modulation Register */
	vuint32_t R;
	struct {
	    vuint32_t  STRB_BYPASS:1;   /* Strobe Bypass */
	    vuint32_t:1;
	    vuint32_t  SPRD_SEL:1;   /* Spread Type Selection */
	    vuint32_t  MOD_PERIOD:13;   /* Modulation Period */
	    vuint32_t  FM_EN:1;   /* Spread Spectrum Clock Generation Enable */
	    vuint32_t  INC_STEP:15;   /* Increment Step */
	} B;
    } FMPLL_MR;

    int8_t CGM_reserved_0A8[0x58];

    union {   /* CMU_CSR - Control Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:8;
	    vuint32_t  SFM:1;   /* Start Frequency Measure */
	    vuint32_t:13;
	    vuint32_t  CKSEL1:2;   /* RC Oscillator(s) Selection Bit */
	    vuint32_t:5;
	    vuint32_t  RCDIV:2;   /* RCfast Clock Division Factor */
	    vuint32_t  CME_A:1;   /* PLL_A Clock Monitor Enable */
	} B;
    } CMU_CSR;

    union {   /* CMU_FDR - Frequency Display Register */
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t  FD:20;   /* Measured Frequency Bits */
	} B;
    } CMU_FDISP;

    union {   /* CMU_HFREFR_A - High Frequency Reference Register */
	vuint32_t R;
	struct {
	    vuint32_t:20;
	    vuint32_t  HFREF_A:12;   /* High Frequency Reference Value */
	} B;
    } CMU_HFREFR_A;

    union {   /* CMU_LFREFR_A - Low Frequency Reference Register */
	vuint32_t R;
	struct {
	    vuint32_t:20;
	    vuint32_t  LFREF_A:12;   /* Low Frequency Reference Value */
	} B;
    } CMU_LFREFR_A;

    union {   /* CMU_ISR - Interrupt Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:28;
	    vuint32_t  FLCI_A:1;   /* PLL_A Clock Frequency less than Reference Clock Interrupt */
	    vuint32_t  FHH_AI:1;   /* PLL_A Clock Frequency higher than high Reference Interrupt */
	    vuint32_t  FLLI_A:1;   /* PLL_A Clock Frequency less than low Reference Interrupt */
	    vuint32_t  OLRI:1;   /* Oscillator Frequency less than RC Frequency Interrupt */
	} B;
    } CMU_ISR;

    int8_t CGM_reserved_114[4];

    union {   /* CMU_MDR - Measurement Duration Register */
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t  MD:20;   /* Measurment Duration Bits */
	} B;
    } CMU_MDR;

    int8_t CGM_reserved_11C[4];

    union {   /* CCR - Clk Configuration Register */
	vuint8_t R;
	struct {
	    vuint8_t:7;
	    vuint8_t  DIV:1;   /* Divider Value */
	} B;
    } PLL_CLK_DIV;

    int8_t CGM_reserved_0121[31];

    union {   /* CCR - Clk Configuration Register */
	vuint8_t R;
	struct {
	    vuint8_t:7;
	    vuint8_t  DIV:1;   /* Divider Value */
	} B;
    }SYSTEM_CLK_DIV;

    int8_t CGM_reserved_00141[31];

    union {   /* CCR - Clk Configuration Register */
	vuint8_t R;
	struct {
	    vuint8_t:7;
	    vuint8_t  DIV:1;   /* Divider Value */
	} B;
    } RTC_CLK_DIV;

    int8_t CGM_reserved_0161[527];

    union {   /* CGM_OC_EN - Output Clock Enable Register */
	vuint32_t R;
	struct {
	    vuint32_t:31;
	    vuint32_t  EN:1;   /* Clock Enable Bit */
	} B;
    } OC_EN;

    union {   /* CGM_OCDS_SC - Output Clock Division Select Register */
	vuint8_t R;
	struct {
	    vuint8_t:2;
	    vuint8_t  SELDIV:2;   /* Output Clock Division Select */
	    vuint8_t  SELCTL:4;   /* Output Clock Source Selection Control */
	} B;
    } OCDS_SC;

    int8_t CGM_reserved_0375[3];

    union {   /* CGM_SC_SS - System Clock Select Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t  SELSTAT:4;   /* System Clock Source Selection Status */
	    vuint32_t:24;
	} B;
    } SC_SS;
};                                                

/****************************************************************/
/*                                                              */
/* Module: RGM  */
/*                                                              */
/****************************************************************/

struct RGM_tag{

    union {   /* RGM_FES - Functional Event Status Register */
	vuint16_t R;
	struct {
	    vuint16_t  F_EXR:1;   /* Flag for External Reset */
	    vuint16_t:6;
	    vuint16_t  F_FLASH:1;   /* Flag for Functional Reset */
	    vuint16_t:1;
	    vuint16_t  F_CMU0_FHL:1;
	    vuint16_t  F_CMU0_OLR:1;
	    vuint16_t  F_PLL0:1;
	    vuint16_t  F_CHKSTOP:1;
	    vuint16_t  F_SOFT:1;
	    vuint16_t  F_CORE:1;
	    vuint16_t  F_JTAG:1;
	} B;
    } FES;

    union {   /* RGM_DES - Destructive Event Status Register */
	vuint16_t R;
	struct {
	    vuint16_t  F_POR:1;   /* Flag for Power on Reset */
	    vuint16_t:10;
	    vuint16_t F_LVD27_VREG:1;
	    vuint16_t:1;
	    vuint16_t F_SWT:1;
	    vuint16_t:1;
	    vuint16_t F_LVD12:1;
	} B;
    } DES;

    union {   /* RGM_FERD - Functional Event Reset Disable Register */
	vuint16_t R;
	struct {
	    vuint16_t  D_EXR: 1;
	    vuint16_t:6;
	    vuint16_t  D_FLASH:1;   
	    vuint16_t:1;
	    vuint16_t  D_CMU0_FHL:1;
	    vuint16_t  D_CMU0_OLR:1;
	    vuint16_t  D_PLL0:1;   /* Disable Functional Event Reset */
	    vuint16_t  D_CHKSTOP:1;   /* Disable Functional Event Reset */
	    vuint16_t  D_SOFT:1;   /* Disable Functional Event Reset */
	    vuint16_t  D_CORE:1;   /* Disable Functional Event Reset */
	    vuint16_t  D_JTAG:1;   /* Disable Functional Event Reset */
	} B;
    } FERD;

    union {   /* RGM_DERD - Destructive Event Reset Disable Register */
	vuint16_t R;
	struct { 
	    vuint16_t:11;
	    vuint16_t  D_LVD27_VREG:1;
	    vuint16_t:1;
	    vuint16_t  D_SWT:1;
	    vuint16_t:1;
	    vuint16_t  D_LVD12:1;
	} B;
    } DERD;

    int8_t RGM_reserved_0008[8];

    union {   /* RGM_FEAR - Functional Event Alternate Request Register */
	vuint16_t R;
	struct {
	    vuint16_t:9;
	    vuint16_t  AR_CMU0_FHL:1;   /* Functional Event Alternate Request Register */
	    vuint16_t  AR_CMU0_OLR:1;   /* Functional Event Alternate Request Register */
	    vuint16_t  AR_PLL0:1;   /* Functional Event Alternate Request Register */
	    vuint16_t:2;
	    vuint16_t  AR_CORE:1;   /* Functional Event Alternate Request Register */
	    vuint16_t  AR_JTAG:1;   /* Functional Event Alternate Request Register */
	} B;
    } FEAR;

    int8_t RGM_reserved_0012[6];

    union {   /* RGM_FESS - Functional Event Short Sequence Register */
	vuint16_t R;
	struct {
	    vuint16_t  SS_EXR:1;
	    vuint16_t:6;
	    vuint16_t  SS_FLASH:1;   /* Functional Reset Short Sequence */
	    vuint16_t:1;
	    vuint16_t  SS_CMU0_FHL:1;   /* Functional Reset Short Sequence */
	    vuint16_t  SS_CMU0_OLR:1;   /* Functional Reset Short Sequence */
	    vuint16_t  SS_PLL0:1;   /* Functional Reset Short Sequence */
	    vuint16_t  SS_CHKSTOP:1;   /* Functional Reset Short Sequence */
	    vuint16_t  SS_SOFT:1;   /* Functional Reset Short Sequence */
	    vuint16_t  SS_CORE:1;   /* Functional Reset Short Sequence */
	    vuint16_t  SS_JTAG:1;   /* Functional Reset Short Sequence */
	} B;
    } FESS;

    int8_t RGM_reserved_001A[2];

    union {   /* RGM_FBRE - Functional Bidirectional Reset Enable Register */
	vuint16_t R;
	struct {
	    vuint16_t  BE_EXR:1;   /* Funtional Reset Bidirectional Reset Enable */
	    vuint16_t:6;
	    vuint16_t  BE_FLASH:1;   /* Funtional Reset Bidirectional Reset Enable */
	    vuint16_t:1;
	    vuint16_t  BE_CMU0_FHL:1;   /* Funtional Reset Bidirectional Reset Enable */
	    vuint16_t  BE_CMU0_OLR:1;   /* Funtional Reset Bidirectional Reset Enable */
	    vuint16_t  BE_PLL0:1;   /* Funtional Reset Bidirectional Reset Enable */
	    vuint16_t  BE_CHKSTOP:1;   /* Funtional Reset Bidirectional Reset Enable */
	    vuint16_t  BE_SOFT:1;   /* Funtional Reset Bidirectional Reset Enable */
	    vuint16_t  BE_CORE:1;   /* Funtional Reset Bidirectional Reset Enable */
	    vuint16_t  BE_JTAG:1;   /* Funtional Reset Bidirectional Reset Enable */
	} B;
    } FBRE;
};                                                

/****************************************************************/
/*                                                              */
/* Module: PCU  */
/*                                                              */
/****************************************************************/

struct PCU_tag {
    int8_t PCU_reserved_0000[64];
    union  {   /* PCU_PSTAT - Power Domain Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:31;
	    vuint32_t  PD0:1;   /* Power Status for Power Domain 0 */
	} B;
    } PSTAT;
};

/****************************************************************/
/*                                                              */
/* Module: PIT_RTI  */
/*                                                              */
/****************************************************************/

struct PIT_RTI_tag {


    union {   /* PIT_RTI_PITMCR - PIT Module Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:30;
	    vuint32_t  MDIS:1;   /* Module Disable. Disable the module clock */
	    vuint32_t  FRZ:1;   /* Freeze. Allows the timers to be stoppedwhen the device enters debug mode */
	} B;
    } PITMCR;

    int8_t PIT_RTI_reserved_0004[252];

    struct{
	union {   /* PIT_RTI_LDVAL - Timer Load Value Register */
	    vuint32_t R;
	    struct {
		vuint32_t  TSV:32;   /* Time Start Value Bits */
	    } B;
	} LDVAL;

	union {   /* PIT_RTI_CVAL - Current Timer Value Register */
	    vuint32_t R;
	    struct {
		vuint32_t  TVL:32;   /* Current Timer Value Bits */
	    } B;
	} CVAL;

	union {   /* PIT_RTI_TCTRL - Timer Control Register */
	    vuint32_t R;
	    struct {
		vuint32_t:30;
		vuint32_t  TIE:1;   /* Timer Interrupt Enable Bit */
		vuint32_t  TEN:1;   /* Timer Enable Bit */
	    } B;
	} TCTRL;

	union {   /* PIT_RTI_TFLG - Timer Flag Register */
	    vuint32_t R;
	    struct {
		vuint32_t:31;
		vuint32_t  TIF:1;   /* Timer Interrupt Flag Bit */
	    } B;
	} TFLG;
    }CH[4];
};                                                

/****************************************************************/
/*                                                              */
/* Module: ADC  */
/*                                                              */
/****************************************************************/

struct ADC_tag {

    union {   /* module configuration register */
	vuint32_t R;
	struct {
	    vuint32_t  OWREN:1;   /* Overwrite enable */
	    vuint32_t  WLSIDE:1;   /* Write Left/right Alligned */
	    vuint32_t  MODE:1;   /* One Shot/Scan Mode Selectiom */
	    vuint32_t  EDGLEV:1;   /* edge or level selection for external start trigger */
	    vuint32_t  TRGEN:1;   /* external trigger enable */
	    vuint32_t  EDGE:1;   /* start trigger egde /level detection */
	    vuint32_t  XSTRTEN:1;   /* EXTERNAL START ENABLE */
	    vuint32_t  NSTART:1;   /* start normal conversion */
	    vuint32_t:1;
	    vuint32_t  JTRGEN:1;   /* Injectin External Trigger Enable */
	    vuint32_t  JEDGE:1;   /* start trigger egde /level detection for injected */
	    vuint32_t  JSTART:1;   /* injected conversion start */
	    vuint32_t:11;
	    vuint32_t  ADCLKSEL:1;   /* Select which clock for device */
	    vuint32_t  ABORTCHAIN:1;   /* abort chain conversion */
	    vuint32_t  ABORT:1;   /* abort current conversion */
	    vuint32_t  ACKO:1;   /* Auto Clock Off Enable */
	    vuint32_t:4;
	    vuint32_t  PWDN:1;   /* Power Down Enable */
	} B;
    } MCR;

    union {   /* module status register */
	vuint32_t R;
	struct {
	    vuint32_t:7;
	    vuint32_t  NSTART:1;   /* normal conversion status */
	    vuint32_t  JABORT:1;   /* Injection chain abort status */
	    vuint32_t:2;
	    vuint32_t  JSTART:1;   /* Injection Start status */
	    vuint32_t  REF_RANGE:1;   /* ref_range */
	    vuint32_t  SELF_TEST_S:1;   /* self test status */
	    vuint32_t:1;
	    vuint32_t  CTUSTART:1;   /* ctu start status */
	    vuint32_t  CHADDR:7;   /* which address conv is goin on */
	    vuint32_t:3;
	    vuint32_t  ACKO:1;   /* Auto Clock Off Enable status */
	    vuint32_t  OFFREFRESH:1;   /* offset refresh status */
	    vuint32_t  OFFCANC:1;   /* offset phase cancellation status */
	    vuint32_t  ADCSTATUS:3;   /* status of ADC FSM */
	} B;
    } MSR;

    int8_t ADC_reserved_0008[8];

    union {   /* Interrupt status register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  REF_RANGE:1;   /* ref_range */
	    vuint32_t:8;
	    vuint32_t  OFFCANCOVR:1;   /* Offset cancellation phase over */
	    vuint32_t  EOFFSET:1;   /* error in offset refresh */
	    vuint32_t  EOCTU:1;   /* end of CTU channel conversion */
	    vuint32_t  JEOC:1;   /* end of injected channel conversion */
	    vuint32_t  JECH:1;   /* end ofinjected chain conversion */
	    vuint32_t  EOC:1;   /* end of channel conversion */
	    vuint32_t  ECH:1;   /* end of chain conversion */
	} B;
    } ISR;

    int8_t ADC_reserved_00014[12];

    union {   /* interrupt mask register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  MSKREFRANGE:1;   /* mask bit for ref_range */
	    vuint32_t:8;
	    vuint32_t  MSKOFFCANCOVR:1;   /* mask bit for Calibration over */
	    vuint32_t  MSKEOFFSET:1;   /* mask bit for Error in offset refresh */
	    vuint32_t  MSKEOCTU:1;   /* mask bit for EOCTU */
	    vuint32_t  MSKJEOC:1;   /* mask bit for JEOC */
	    vuint32_t  MSKJECH:1;   /* mask bit for JECH */
	    vuint32_t  MSKEOC:1;   /* mask bit for EOC */
	    vuint32_t  MSKECH:1;   /* mask bit for ECH */
	} B;
    } IMR;
    int8_t ADC_reserved_00024[12];
    union {   /* Watchdog Threshold interrupt status register */
	vuint32_t R;
	struct {
	    vuint32_t:24;
	    vuint32_t  WDG3H:1;   /* Interrupt generated on the value being higher than the HTHV 3 */
	    vuint32_t  WDG2H:1;   /* Interrupt generated on the value being higher than the HTHV 2 */
	    vuint32_t  WDG1H:1;   /* Interrupt generated on the value being higher than the HTHV 1 */
	    vuint32_t  WDG0H:1;   /* Interrupt generated on the value being higher than the HTHV 0 */
	    vuint32_t  WDG3L:1;   /* Interrupt generated on the value being lower than the LTHV 3 */
	    vuint32_t  WDG2L:1;   /* Interrupt generated on the value being lower than the LTHV 2 */
	    vuint32_t  WDG1L:1;   /* Interrupt generated on the value being lower than the LTHV 1 */
	    vuint32_t  WDG0L:1;   /* Interrupt generated on the value being lower than the LTHV 0 */
	} B;
    } WTISR;

    union {   /* Watchdog interrupt MASK register */
	vuint32_t R;
	struct {
	    vuint32_t:24;
	    vuint32_t  MSKWDG3H:1;   /* Mask enable for Interrupt generated on the value being higher than the HTHV 3 */
	    vuint32_t  MSKWDG2H:1;   /* Mask enable for  Interrupt generated on the value being higher than the HTHV 2 */
	    vuint32_t  MSKWDG1H:1;   /* Mask enable for Interrupt generated on the value being higher than the HTHV 1 */
	    vuint32_t  MSKWDG0H:1;   /* Mask enable for Interrupt generated on the value being higher than the HTHV 0 */
	    vuint32_t  MSKWDG3L:1;   /* Mask enable for Interrupt generated on the value being lower than the LTHV 3 */
	    vuint32_t  MSKWDG2L:1;   /* Mask enable for Interrupt generated on the value being lower than the LTHV 2 */
	    vuint32_t  MSKWDG1L:1;   /* MAsk enable for Interrupt generated on the value being lower than the LTHV 1 */
	    vuint32_t  MSKWDG0L:1;   /* Mask enable for Interrupt generated on the value being lower than the LTHV 0 */
	} B;
    } WTIMR;

    int8_t ADC_reserved_0038[8];

    union {   /* DMAE register */
	vuint32_t R;
	struct {
	    vuint32_t:30;
	    vuint32_t  DCLR:1;   /* DMA clear sequence enable */
	    vuint32_t  DMAEN:1;   /* DMA global enable */
	} B;
    } DMAE;

    union {   /* DMA  REGISTER 0 */
	vuint32_t R;
	struct {
	    vuint32_t : 24;	     //Register bits 31:8 are unused
	    vuint32_t  DMA7:1;   /* Channel 7 DMA Enable */
	    vuint32_t  DMA6:1;   /* Channel 6 DMA Enable */
	    vuint32_t  DMA5:1;   /* Channel 5 DMA Enable */
	    vuint32_t  DMA4:1;   /* Channel 4 DMA Enable */
	    vuint32_t  DMA3:1;   /* Channel 3 DMA Enable */
	    vuint32_t  DMA2:1;   /* Channel 2 DMA Enable */
	    vuint32_t  DMA1:1;   /* Channel 1 DMA Enable */
	    vuint32_t  DMA0:1;   /* Channel 0 DMA Enable */
	} B;
    } DMAR0;

    int8_t ADC_reserved_0048[24];

    union {   /* Upper Threshold register */
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t  THRH:12;   /* high threshold value s */
	    vuint32_t:4;
	    vuint32_t  THRL:12;   /* low threshold value s */
	} B;
    } THRHLR[4];

    int8_t ADC_reserved_0070[36];

    union {   /* conversion timing register 0 */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  INPLATCH:1;   /* configuration bits for the LATCHING PHASE duration */
	    vuint32_t:1;
	    vuint32_t  OFFSHIFT:2;   /* configuration for offset shift characteristics */
	    vuint32_t:1;
	    vuint32_t  INPCMP:2;   /* configuration bits for the COMPARISON duration */
	    vuint32_t:1;
	    vuint32_t  INSAMP:8;   /* configuration bits for the SAMPLING PHASE duration */
	} B;
    } CTR0;

    union {   /* conversion timing register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  INPLATCH:1;   /* configuration bits for the LATCHING PHASE duration */
	    vuint32_t:1;
	    vuint32_t  OFFSHIFT:2;   /* configuration for offset shift characteristics */
	    vuint32_t:1;
	    vuint32_t  INPCMP:2;   /* configuration bits for the COMPARISON duration */
	    vuint32_t:1;
	    vuint32_t  INSAMP:7;   /* configuration bits for the SAMPLING PHASE duration */
	    vuint32_t  TSENSOR_SEL:1;
	} B;
    } CTR1;

    int8_t ADC_reserved_009C[8];

    union {   /* NORMAL CONVERSION MASK REGISTER 0 */
	vuint32_t R;
	struct {
	    vuint32_t:24;
	    vuint32_t  CH7:1;   /* Channel 7 Normal Sampling Enable */
	    vuint32_t  CH6:1;   /* Channel 6 Normal Sampling Enable */
	    vuint32_t  CH5:1;   /* Channel 5 Normal Sampling Enable */
	    vuint32_t  CH4:1;   /* Channel 4 Normal Sampling Enable */
	    vuint32_t  CH3:1;   /* Channel 3 Normal Sampling Enable */
	    vuint32_t  CH2:1;   /* Channel 2 Normal Sampling Enable */
	    vuint32_t  CH1:1;   /* Channel 1 Normal Sampling Enable */
	    vuint32_t  CH0:1;   /* Channel 0 Normal Sampling Enable */
	} B;
    } NCMR0;

    int8_t ADC_reserved_00A8[12];

    union {   /* Injected Conversion Mask Register 0 */
	vuint32_t R;
	struct {
	    vuint32_t:24;   
	    vuint32_t  CH7:1;   /* Channel 7 Injected   Sampling Enable */
	    vuint32_t  CH6:1;   /* Channel 6 Injected  Sampling Enable */
	    vuint32_t  CH5:1;   /* Channel 5 Injected Sampling Enable */
	    vuint32_t  CH4:1;   /* Channel 4 Injected Sampling Enable */
	    vuint32_t  CH3:1;   /* Channel 3 Injected Sampling Enable */
	    vuint32_t  CH2:1;   /* Channel 2 Injected Sampling Enable */
	    vuint32_t  CH1:1;   /* Channel 1 injected Sampling Enable */
	    vuint32_t  CH0:1;   /* Channel 0 injected Sampling Enable */
	} B;
    } JCMR0;

    int8_t ADC_reserved_00B8[72];

    union {   /* CHANNEL DATA REGS */
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t  VALID:1;   /* validity of data */
	    vuint32_t  OVERW:1;   /* overwrite data */
	    vuint32_t  RESULT:2;   /* reflects mode conversion */
	    vuint32_t:6;
	    vuint32_t  CDATA:10;   /* Channel 0 converted data */
	} B;
    } CDR[8];

    int8_t ADC_reserved_0120[400];

    union {   /* CHANNEL WATCHDOG SELECT REGS */
	vuint32_t R;
	struct {
	    vuint32_t:2;
	    vuint32_t  CH7:2;   
	    vuint32_t:2;
	    vuint32_t  CH6:2;   
	    vuint32_t:2;
	    vuint32_t  CH5:2;   
	    vuint32_t:2;
	    vuint32_t  CH4:2;   
	    vuint32_t:2;
	    vuint32_t  CH3:2;   
	    vuint32_t:2;
	    vuint32_t  CH2:2;   
	    vuint32_t:2;
	    vuint32_t  CH1:2;   
	    vuint32_t:2;
	    vuint32_t  CH0:2;
	} B;
    } CWSEL0;

    int8_t ADC_reserved_02B4[44];

    union {   /* CHANNEL WATCHDOG ENABLE REGS */
	vuint32_t R;
	struct {
	    vuint32_t:24;
	    vuint32_t  CH7:1;   
	    vuint32_t  CH6:1;   
	    vuint32_t  CH5:1;   
	    vuint32_t  CH4:1;   
	    vuint32_t  CH3:1;   
	    vuint32_t  CH2:1;   
	    vuint32_t  CH1:1;   
	    vuint32_t  CH0:1;
	} B;
    } CWENR0;
};                                                

/****************************************************************/
/*                                                              */
/* Module: eTIMER  */
/*                                                              */
/****************************************************************/

struct eTIMER_tag {
    struct
    {
	union {   /* Compare Register 1 */
	    vuint16_t R;
	    struct { 
		vuint16_t	COMP1:16;
	    } B;
	} COMP1;

	union {   /* Compare Register 2 */
	    vuint16_t R;
	    struct { 
		vuint16_t	COMP2:16;
	    } B;
	} COMP2;

	union {   /* Capture Register 1 */
	    vuint16_t R;
	    struct { 
		vuint16_t	CAPT1:16;
	    } B;
	} CAPT1;

	union {   /* Capture Register 2 */
	    vuint16_t R;
	    struct { 
		vuint16_t	CAPT2:16;
	    } B;
	} CAPT2;

	union {   /* Load Register */
	    vuint16_t R;
	    struct { 
		vuint16_t	LOAD:16;
	    } B;
	} LOAD;

	union {   /* Hold Register */
	    vuint16_t R;
	    struct { 
		vuint16_t	HOLD:16;
	    } B;
	} HOLD;

	union {   /* Counter Register */
	    vuint16_t R;
	    struct { 
		vuint16_t	CNTR:16;
	    } B;
	} CNTR;

	union {   /* Control Register */
	    vuint16_t R;
	    struct {
		vuint16_t  CNTMODE:3;   /* Count Mode */
		vuint16_t  PRISRC:5;   /* Primary Count Source */
		vuint16_t  ONCE:1;   /* Count Once */
		vuint16_t  LENGTH:1;   /* Count Length */
		vuint16_t  DIR:1;   /* Count Direction */
		vuint16_t  SECSRC:5;   /* Secondary Count Source */
	    } B;
	} CTRL1;

	union {   /* Control Register 2 */
	    vuint16_t R;
	    struct {
		vuint16_t  OEN:1;   /* Output Enable */
		vuint16_t  RDNT:1;   /* Redundant Channel Enable */
		vuint16_t  INPUT:1;   /* External Input Signal */
		vuint16_t  VAL:1;   /* Forced OFLAG Value */
		vuint16_t  FORCE:1;   /* Force the OFLAG output */
		vuint16_t  COFORC:1;   /* Co-channel OFLAG Force */
		vuint16_t  COINIT:2;   /* Co-channel Initialization */
		vuint16_t  SIPS:1;   /* Secondary Source Input Polarity Select */
		vuint16_t  PIPS:1;   /* Primary Source Input Polarity Select */
		vuint16_t  OPS:1;   /* Output Polarity Select */
		vuint16_t  MSTR:1;   /* Master Mode */
		vuint16_t  OUTMODE:4;   /* Output Mode */
	    } B;
	} CTRL2;

	union {   /* Control Register 3 */
	    vuint16_t R;
	    struct {
		vuint16_t  STPEN:1;   /* Stop Action Enable */
		vuint16_t  ROC:2;   /* Reload On Capture */
		vuint16_t:5;
		vuint16_t  C2FCNT:3;   /* CAPT2 FIFO Word Count */
		vuint16_t  C1FCNT:3;   /* CAPT1 FIFO Word Count */
		vuint16_t  DBGEN:2;   /* Debug Actions Enable */
	    } B;
	} CTRL3;

	union {   /* Status Register */
	    vuint16_t R;
	    struct {
		vuint16_t:6;
		vuint16_t  WDF:1;   /* Watchdog Time-out Flag */
		vuint16_t  RCF:1;   /* Redundant Channel Flag */
		vuint16_t  ICF2:1;   /* Input Capture 2 Flag */
		vuint16_t  ICF1:1;   /* Input Capture 1 Flag */
		vuint16_t  IEHF:1;   /* Input Edge High Flag */
		vuint16_t  IELF:1;   /* Input Edge Low Flag */
		vuint16_t  TOF:1;   /* Timer Overflow Flag */
		vuint16_t  TCF2:1;   /* Timer Compare 2 Flag */
		vuint16_t  TCF1:1;   /* Timer Compare 1 Flag */
		vuint16_t  TCF:1;   /* Timer Compare Flag */
	    } B;
	} STS;

	union {   /* Interrupt and DMA Enable Register */
	    vuint16_t R;
	    struct {
		vuint16_t  ICF2DE:1;   /* Input Capture 2 Flag DMA Enable */
		vuint16_t  ICF1DE:1;   /* Input Capture 1 Flag DMA Enable */
		vuint16_t  CMPLD2DE:1;   /* Comparator Load Register 2 Flag DMA Enable */
		vuint16_t  CMPLD1DE:1;   /* Comparator Load Register 1 Flag DMA Enable */
		vuint16_t:2;
		vuint16_t  WDFIE:1;   /* Watchdog Flag Interrupt Enable */
		vuint16_t  RCFIE:1;   /* Redundant Channel Flag Interrupt Enable */
		vuint16_t  ICF2IE:1;   /* Input Capture 2 Flag Interrupt Enable */
		vuint16_t  ICF1IE:1;   /* Input Capture 1 Flag Interrupt Enable */
		vuint16_t  IEHFIE:1;   /* Input Edge High Flag Interrupt Enable */
		vuint16_t  IELFIE:1;   /* Input Edge Low Flag Interrupt Enable */
		vuint16_t  TOFIE:1;   /* Timer Overflow Flag Interrupt Enable */
		vuint16_t  TCF2IE:1;   /* Timer Compare 2 Flag Interrupt Enable */
		vuint16_t  TCF1IE:1;   /* Timer Compare 1 Flag Interrupt Enable */
		vuint16_t  TCFIE:1;   /* Timer Compare Flag Interrupt Enable */
	    } B;
	} INTDMA;

	union {   /* Comparator Load Register 1 */
	    vuint16_t R;
	    struct { 
		vuint16_t	CMPLD1:16;
	    } B;
	} CMPLD1;

	union {   /* Comparator Load Register 2 */
	    vuint16_t R;
	    struct { 
		vuint16_t	CMPLD2:16;
	    } B;
	} CMPLD2;

	union {   /* Compare and Capture Control Register */
	    vuint16_t R;
	    struct {
		vuint16_t  CLC2:3;   /* Compare Load Control 2 */
		vuint16_t  CLC1:3;   /* Compare Load Control 1 */
		vuint16_t  CMPMODE:2;   /* Compare Mode */
		vuint16_t  CPT2MODE:2;   /* Capture 2 Mode Control */
		vuint16_t  CPT1MODE:2;   /* Capture 1 Mode Control */
		vuint16_t  CFWM:2;   /* Capture FIFO Water Mark */
		vuint16_t  ONESHOT:1;   /* One Shot Capture Mode */
		vuint16_t  ARM:1;   /* Arm Capture */
	    } B;
	} CCCTRL;

	union {   /* Input Filter Register */
	    vuint16_t R;
	    struct {
		vuint16_t:5;
		vuint16_t  FILT_CNT:3;   /* Input Filter Sample Count */
		vuint16_t  FILT_PER:8;   /* Input Filter Sample Period */
	    } B;
	} FILT;

    }CHANNEL[6];


    int8_t eTIMER_reserved_00C0[64];


    union {   /* Watchdog Time-out Register */
	vuint16_t R;
	struct { 
	    vuint16_t	WDTOL:16;
	} B;
    } WDTOL;

    union {   /* Watchdog Time-out Register */
	vuint16_t R;
	struct { 
	    vuint16_t	WDTOH:16;
	} B;
    } WDTOH;

    int8_t eTIMER_reserved_0104[8];

    union {   /* Channel Enable Registers */
	vuint16_t R;
	struct {
	    vuint16_t:10;
	    vuint16_t  ENBL:6;   /* Timer Channel Enable */
	} B;
    } ENBL;

    int8_t eTIMER_reserved_010E[2];

    union {   /* DMA Request 0 Select Registers */
	vuint16_t R;
	struct {
	    vuint16_t  DREQ0_EN:1;   /* DMA Request Select */
	    vuint16_t:10;
	    vuint16_t  DREQ0:5;   /* DMA Request Select */
	} B;
    } DREQ0;

    union {   /* DMA Request 1 Select Registers */
	vuint16_t R;
	struct {
	    vuint16_t  DREQ1_EN:1;   /* DMA Request Select */
	    vuint16_t:10;
	    vuint16_t  DREQ1:5;   /* DMA Request Select */
	} B;
    } DREQ1;
};                                                

/****************************************************************/
/*                                                              */
/* Module: LINFLEX  */
/*                                                              */
/****************************************************************/

struct LINFLEX_tag {

    union {   /* LINCR1 -  LIN Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  CCD:1;   /* Checksum Calculation Disable */
	    vuint32_t  CFD:1;   /* Checksum Field Disable */
	    vuint32_t  LASE:1;   /* LIN Auto Synchronization Enable */
	    vuint32_t  AUTOWU:1;   /* Auto Wake Up */
	    vuint32_t  MBL:4;   /* Master Break Length */
	    vuint32_t  BF:1;   /* By-Pass Filter */
	    vuint32_t  SLFM:1;   /* Selftest Mode */
	    vuint32_t  LBKM:1;   /* Loopback Mode */
	    vuint32_t  MME:1;   /* Master Mode Enable */
	    vuint32_t  SSBL:1;   /* Slave Mode Synch Break Length */
	    vuint32_t  RBLM:1;   /* Receiver Buffer Locked Mode */
	    vuint32_t  SLEEP:1;   /* Sleep Mode Request */
	    vuint32_t  INIT:1;   /* Initialization Mode Request */
	} B;
    } LINCR1;

    union {   /* LINIER - LIN Interrupt Enable Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  SZIE:1;   /* Stuck at Zero Interrupt Enable */
	    vuint32_t  OCIE:1;   /* Output Compare Interrupt Enable */
	    vuint32_t  BEIE:1;   /* Bit Error Interrupt Enable */
	    vuint32_t  CEIE:1;   /* Checksum Error Interrupt Enable */
	    vuint32_t  HEIE:1;   /* Header Error Interrupt Enable */
	    vuint32_t:2;
	    vuint32_t  FEIE:1;   /* Frame Error Interrupt Enable */
	    vuint32_t  BOIE:1;   /* Buffer Overrun Error Interrupt Enable */
	    vuint32_t  LSIE:1;   /* LIN State Interrupt Enable */
	    vuint32_t  WUIE:1;   /* Wakeup Interrupt Enable */
	    vuint32_t  DBFIE:1;   /* Data Buffer Full Interrupt Enable */
	    vuint32_t  DBEIE:1;   /* Data Buffer Empty Interrupt Enable */
	    vuint32_t  DRIE:1;   /* Data Reception complete Interrupt Enable */
	    vuint32_t  DTIE:1;   /* Data Transmitted Interrupt Enable */
	    vuint32_t  HRIE:1;   /* Header Received Interrupt Enable */
	} B;
    } LINIER;

    union {   /* LINSR - LIN Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  LINS:4;   /* LIN State */
	    vuint32_t:2;
	    vuint32_t  RMB:1;   /* Release Message Buffer */
	    vuint32_t:1;
	    vuint32_t  RXBUSY:1;   /* Receiver Busy Flag */
	    vuint32_t  RDI:1;   /* LIN Receive Signal */
	    vuint32_t  WUF:1;   /* Wake Up Flag */
	    vuint32_t  DBFF:1;   /* Data Buffer Full Flag */
	    vuint32_t  DBEF:1;   /* Data Buffer Empty Flag */
	    vuint32_t  DRF:1;   /* Data Reception Completed Flag */
	    vuint32_t  DTF:1;   /* Data Transmission Completed Flag */
	    vuint32_t  HRF:1;   /* Header Received Flag */
	} B;
    } LINSR;

    union {   /* LINESR - LIN Error Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  SZF:1;   /* Stuck at Zero Flag */
	    vuint32_t  OCF:1;   /* Output Compare Flag */
	    vuint32_t  BEF:1;   /* Bit Error Flag */
	    vuint32_t  CEF:1;   /* Checksum Error Flag */
	    vuint32_t  SFEF:1;   /* Sync Field Error Flag */
	    vuint32_t  SDEF:1;   /* Sync Delimiter Error Flag */
	    vuint32_t  IDPEF:1;   /* ID Parity Error Flag */
	    vuint32_t  FEF:1;   /* Framing Error Flag */
	    vuint32_t  BOF:1;   /* Buffer Overrun Flag */
	    vuint32_t:6;
	    vuint32_t  NF:1;   /* Noise Flag */
	} B;
    } LINESR;

    union {   /* UARTCR - UART Mode Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:17;
	    vuint32_t  TDFL:2;   /* Transmitter Data Field Length/TX FIFO Counter */
	    vuint32_t:1;
	    vuint32_t  RDFL:2;   /* Reception Data Field Length/RX FIFO Counter */
	    vuint32_t:4;
	    vuint32_t  RXEN:1;   /* Receiver Enable */
	    vuint32_t  TXEN:1;   /* Transmitter Enable */
	    vuint32_t  PC0:1;   /* Parity Check - bit 0 */
	    vuint32_t  PCE:1;   /* Parity Control Enable */
	    vuint32_t  WL0:1;   /* Word Length in UART Mode - bit 0 */
	    vuint32_t  UART:1;   /* UART Mode */
	} B;
    } UARTCR;

    union {   /* UARTSR - UART Mode Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  SZF:1;   /* Stuck at Zero Flag */
	    vuint32_t  OCF:1;   /* Output Compare Flag */
	    vuint32_t  PE:4;   /* Parity Error Flag */
	    vuint32_t  RMB:1;   /* Release Message Buffer */
	    vuint32_t  FEF:1;   /* Framing Error Flag */
	    vuint32_t  BOF_FIFO:1;   /* Buffer Overrun Flag */
	    vuint32_t  RDI:1;   /* Receiver Data Input Signal */
	    vuint32_t  WUF:1;   /* Wakeup Flag */
	    vuint32_t:1;
	    vuint32_t	TO:1;
	    vuint32_t  DRFRFE:1;   /* Data Reception Completed Flag/RX FIFO Empty Flag */
	    vuint32_t  DTFTFF:1;   /* Data Transmission Completed Flag/TX FIFO Full Flag */
	    vuint32_t  NF:1;   /* Noise Flag */
	} B;
    } UARTSR;

    union {   /* LINTCSR - LIN Time-Out Control Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:21;
	    vuint32_t  LTOM:1;   /* Time-out Counter Mode */
	    vuint32_t  IOT:1;   /* Idle on Timeout */
	    vuint32_t  TOCE:1;   /* Time-Out Counter Enable */
	    vuint32_t  CNT:8;   /* Counter Value */
	} B;
    } LINTCSR;

    union {   /* LINOCR -  LIN Output Compare Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  OC2:8;   /* Output Compare Value 2 */
	    vuint32_t  OC1:8;   /* Output Compare Value 1 */
	} B;
    } LINOCR;

    union {   /* LINTOCR -  LIN Time-Out Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:20;
	    vuint32_t  RTO:4;   /* Response Time-Out Value */
	    vuint32_t:1;
	    vuint32_t  HTO:7;   /* Header Time-Out Value */
	} B;
    } LINTOCR;

    union {   /* LINFBRR - LIN Fractional Baud Rate Register */
	vuint32_t R;
	struct {
	    vuint32_t:28;
	    vuint32_t  DIV_F:4;   /* Fractional Baud Rates */
	} B;
    } LINFBRR;

    union {   /* LINIBRR - LIN Integer Baud Rate Register */
	vuint32_t R;
	struct {
	    vuint32_t:19;
	    vuint32_t  IBR:13;   /* Integer Baud Rates */
	} B;
    } LINIBRR;

    union {   /* LINCFR - LIN Checksum Field Register */
	vuint32_t R;
	struct {
	    vuint32_t:24;
	    vuint32_t  CF:8;   /* Checksum Bits */
	} B;
    } LINCFR;

    union {   /* LINCR2 - LIN Control Register 2 */
	vuint32_t R;
	struct {
	    vuint32_t:17;
	    vuint32_t  IOBE:1;   /* Idle on Bit Error */
	    vuint32_t  IOPE:1;   /* Idle on Identifier Parity Error */
	    vuint32_t  WURQ:1;   /* Wakeup Generate Request */
	    vuint32_t  DDRQ:1;   /* Data Discard Request */
	    vuint32_t  DTRQ:1;   /* Data Transmission Request */
	    vuint32_t  ABRQ:1;   /* Abort Request */
	    vuint32_t  HTRQ:1;   /* Header Transmission Request */
	    vuint32_t:8;
	} B;
    } LINCR2;

    union {   /* BIDR - Buffer Identifier Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  DFL:6;   /* Data Field Length */
	    vuint32_t  DIR:1;   /* Direction */
	    vuint32_t  CCS:1;   /* Classic Checksum */
	    vuint32_t:2;
	    vuint32_t  ID:6;   /* Identifier */
	} B;
    } BIDR;

    union {   /* BDRL - Buffer Data Register Least Significant */
	vuint32_t R;
	struct {
	    vuint32_t  DATA3:8;   /* Data3 */
	    vuint32_t  DATA2:8;   /* Data2 */
	    vuint32_t  DATA1:8;   /* Data1 */
	    vuint32_t  DATA0:8;   /* Data0 */
	} B;
    } BDRL;

    union {   /* BDRM - Buffer Data Register Most Significant */
	vuint32_t R;
	struct {
	    vuint32_t  DATA7:8;   /* Data7 */
	    vuint32_t  DATA6:8;   /* Data6 */
	    vuint32_t  DATA5:8;   /* Data5 */
	    vuint32_t  DATA4:8;   /* Data4 */
	} B;
    } BDRM;

    union {   /* IFER - Identifier Filter Enable Register */
	vuint32_t R;
	struct {
	    vuint32_t:24;
	    vuint32_t  FACT:8;   /* Filter Active */
	} B;
    } IFER;

    union {   /* IFMI - Identifier Filter Match Index */
	vuint32_t R;
	struct {
	    vuint32_t:28;
	    vuint32_t  IFMI:4;   /* Filter Match Index */
	} B;
    } IFMI;

    union {   /* IFMR - Identifier Filter Mode Register */
	vuint32_t R;
	struct {
	    vuint32_t:28;
	    vuint32_t  IFM:4;   /* Filter Mode */
	} B;
    } IFMR;

    union {   /* IFCR - Identifier Filter Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:19;
	    vuint32_t  DFL:3;   /* Data Field Length */
	    vuint32_t  DIR:1;   /* Direction */
	    vuint32_t  CCS:1;   /* Classic Checksum */
	    vuint32_t:2;
	    vuint32_t  ID:6;   /* Identifier */
	} B;
    } IFCR[16];
} ;                                                


/****************************************************************/
/*                                                              */
/* Module: CRC  */
/*                                                              */
/****************************************************************/

struct CRC_tag {
    struct
    {
	union {   /* CFG0 - CRC Configuration register */
	    vuint32_t R;
	    vuint8_t   BYTE[4];    /* individual bytes can be accessed */
	    vuint16_t  HALF[2];    /* individual halfwords can be accessed */
	    vuint32_t  WORD;       /* individual words can be accessed */
	    struct {
		vuint32_t:28;
		vuint32_t  POLYG:2;   /* Polynomal selection 0- CRC-CCITT, 1- CRC-CRC-32 INV selection */
		vuint32_t  SWAP:1;   /* SWAP selection */
		vuint32_t  INV:1;   /* INV selection */
	    } B;
	} CFG;

	union {   /* INP - CRC Input register */
	    vuint32_t R;
	    vuint8_t   BYTE[4];    /* individual bytes can be accessed */
	    vuint16_t  HALF[2];    /* individual halfwords can be accessed */
	    vuint32_t  WORD;       /* individual words can be accessed */
	    struct {
		vuint32_t	INP:32;
	    } B;

	} INP;

	union {   /* STATUS - CRC Status register */
	    vuint32_t R;
	    vuint8_t   BYTE[4];    /* individual bytes can be accessed */
	    vuint16_t  HALF[2];    /* individual halfwords can be accessed */
	    vuint32_t  WORD;       /* individual words can be accessed */
	    struct {
		vuint32_t	CSTAT:32;
	    } B;

	} CSTAT;

	union {   /* STATUS - CRC OUTPUT register */
	    vuint32_t R;
	    vuint8_t   BYTE[4];    /* individual bytes can be accessed */
	    vuint16_t  HALF[2];    /* individual halfwords can be accessed */
	    vuint32_t  WORD;       /* individual words can be accessed */
	    struct { 
		vuint32_t	OUTP:32;
	    } B;

	} OUTP;

    }CNTX[2];
};


/****************************************************************/
/*                                                              */
/* Module: FCU  */
/*                                                              */
/****************************************************************/

struct FCU_tag {

    union {   /* MODULE CONFIG REG */
	vuint32_t R;
	struct {
	    vuint32_t  MCL:1;   /* Module Config Lock */
	    vuint32_t  TM:2;   /* Test Mode */
	    vuint32_t:19;
	    vuint32_t  PS:2;   /* Polarity Select */
	    vuint32_t  FOM:2;   /* Fault output Mode Selection */
	    vuint32_t  FOP:6;   /* Fault output Prescaler */
	} B;
    } FCU_MCR;

    union {   /* FAULT FLAG REG */
	vuint32_t R;
	struct {
	    vuint32_t  SRF0:1;   /* Software Recoverable Fault */
	    vuint32_t  SRF1:1;   /* Software Recoverable Fault */	    
	    vuint32_t  SRF2:1;   /* Software Recoverable Fault */
	    vuint32_t  SRF3:1;   /* Software Recoverable Fault */
	    vuint32_t  SRF4:1;   /* Software Recoverable Fault */
	    vuint32_t:11;   
	    vuint32_t  HRF15:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF14:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF13:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF12:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF11:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF10:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF9:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF8:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF7:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF6:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF5:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF4:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF3:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF2:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF1:1;   /* Hardware Recoverable Fault */
	    vuint32_t  HRF0:1;   /* Hardware Recoverable Fault */
	} B;
    } FCU_FFR;

    union {   /* FROZEN FAULT FLAG REG */
	vuint32_t R;
	struct {
	    vuint32_t:2;
	    vuint32_t  FRSRF2:1;   /* Frozen Software Recoverable Fault */
	    vuint32_t  FRSRF3:1;   /* Frozen Software Recoverable Fault */
	    vuint32_t  FRSRF4:1;   /* Frozen Software Recoverable Fault */
	    vuint32_t:11;  
	    vuint32_t  FRHRF15:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF14:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF13:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF12:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF11:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF10:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF9:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF8:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF7:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF6:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF5:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF4:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF3:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF2:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF1:1;   /* Frozen Hardware Recoverable Fault */
	    vuint32_t  FRHRF0:1;   /* Frozen Hardware Recoverable Fault */
	} B;
    } FCU_FFFR;

    union {   /* FAKE FAULT GENERATION REG */
	vuint32_t R;
	struct {
	    vuint32_t:2;
	    vuint32_t  FSRF2:1;   /* Fake Software Recoverable Fault */
	    vuint32_t  FSRF3:1;   /* Fake Software Recoverable Fault */
	    vuint32_t  FSRF4:1;   /* Fake Software Recoverable Fault */
	    vuint32_t:11;  
	    vuint32_t  FHRF15:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF14:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF13:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF12:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF11:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF10:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF9:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF8:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF7:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF6:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF5:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF4:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF3:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF2:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF1:1;   /* Fake Hardware Recoverable Fault */
	    vuint32_t  FHRF0:1;   /* Fake Hardware Recoverable Fault */
	} B;
    } FCU_FFGR;

    union {   /* FAULT ENABLE REG */
	vuint32_t R;
	struct {
	    vuint32_t:2;
	    vuint32_t  ESF2:1;   /* Enable Software Recoverable Fault */
	    vuint32_t  ESF3:1;   /* Enable Software Recoverable Fault */
	    vuint32_t  ESF4:1;   /* Enable Software Recoverable Fault */
	    vuint32_t:11;  
	    vuint32_t  EHF15:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF14:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF13:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF12:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF11:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF10:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF9:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF8:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF7:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF6:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF5:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF4:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF3:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF2:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF1:1;   /* Enable Hardware Recoverable Fault */
	    vuint32_t  EHF0:1;   /* Enable Hardware Recoverable Fault */      
	} B;
    } FCU_FER;

    union {   /* FAULT COLLECTION UNIT KEY REG */
	vuint32_t R;
	struct { 
	    vuint32_t FK:32;
	} B;
    } FCU_KR;

    union {   /* FAULT COLLECTION UNIT TIMEOUT REG */
	vuint32_t R;
	struct {
	    vuint32_t  TR:32;   /* Fault Collection Unit Timeout */
	} B;
    } FCU_TR;

    union {   /* FAULT COLLECTION UNIT TIMEOUT ENABLE REG */
	vuint32_t R;
	struct {
	    vuint32_t:2;
	    vuint32_t  TESF2:1;   /* Timeout Enable Software Recoverable Fault */
	    vuint32_t  TESF3:1;   /* Timeout Enable Software Recoverable Fault */
	    vuint32_t  TESF4:1;   /* Timeout Enable Software Recoverable Fault */
	    vuint32_t:11;  
	    vuint32_t  TEHF15:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF14:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF13:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF12:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF11:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF10:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF9:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF8:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF7:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF6:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF5:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF4:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF3:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF2:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF1:1;   /* Timeout Enable Hardware Recoverable Fault */
	    vuint32_t  TEHF0:1;   /* Timeout Enable Hardware Recoverable Fault */
	} B;
    } FCU_TER;

    union {   /* MODULE STATUS REG */
	vuint32_t R;
	struct {
	    vuint32_t:28;
	    vuint32_t  S3:1;   /* Fault State */
	    vuint32_t  S2:1;   /* Alarm State */
	    vuint32_t  S1:1;   /* Normal State */
	    vuint32_t  S0:1;   /* Init State */
	} B;
    } FCU_MSR;

    union {   /* MC STATE REG */
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t  MCPS:4;   /* MC in Previous State */
	    vuint32_t:12;
	    vuint32_t  MCAS:4;   /* MC in Actual State */
	} B;
    } FCU_MCSR;

    union {   /* FROZEN MC STATE REG */
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t  FRMCPS:4;   /* FROZEN MC in Previous State */
	    vuint32_t:12;
	    vuint32_t  FRMCAS:4;   /* FROZEN MC in Actual State */
	} B;
    } FCU_FMCSR;
};                                                

/****************************************************************/
/*                                                              */
/* Module: PTP  */
/*                                                              */
/****************************************************************/

struct PTP_tag {

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  ETT:16;   /*  */
	    vuint32_t  IPT:8;   /*  */
	    vuint32_t:8;
	} B;
    } PTP_TSPDR1;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  DPNGE:16;   /*  */
	    vuint32_t  DPNEV:16;   /*  */
	} B;
    } PTP_TSPDR2;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  SYCTL:8;   /*  */
	    vuint32_t  DRCTL:8;   /*  */
	    vuint32_t  DRPCTL:8;   /*  */
	    vuint32_t  FUCTL:8;   /*  */
	} B;
    } PTP_TSPDR3;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  MACTL:8;   /*  */
	    vuint32_t:8;
	    vuint32_t  VLAN:16;   /*  */
	} B;
    } PTP_TSPDR4;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  ETTOF:8;   /*  */
	    vuint32_t  IPTOF:8;   /*  */
	    vuint32_t  UDOF:8;   /*  */
	    vuint32_t  PTOF:8;   /*  */
	} B;
    } PTP_TSPOV;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t  OPM_ODE1:1;   /*  */
	    vuint32_t  OPM_ODE2:1;   /*  */
	    vuint32_t  OPM_ODE3:1;   /*  */
	    vuint32_t  OPM_ODE4:1;   /*  */
	    vuint32_t:7;
	    vuint32_t  PTPV:1;   /*  */
	    vuint32_t  ENUDP:1;   /*  */
	    vuint32_t  ENTRN:1;   /*  */
	    vuint32_t:2;
	    vuint32_t  EN1:1;   /*  */
	    vuint32_t  EN2:1;   /*  */
	    vuint32_t  EN3:1;   /*  */
	    vuint32_t  EN4:1;   /*  */
	} B;
    } PTP_TSMR;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  EXR:1;   /*  */
	    vuint32_t  OVR1:1;   /*  */
	    vuint32_t  OVT1:1;   /*  */
	    vuint32_t  SYRE1:1;   /*  */
	    vuint32_t  DRQRE1:1;   /*  */
	    vuint32_t  TXE1:1;   /*  */
	    vuint32_t  PDRQRE1:1;   /*  */
	    vuint32_t  PDRSRE1:1;   /*  */
	    vuint32_t  EXT:1;   /*  */
	    vuint32_t  OVR2:1;   /*  */
	    vuint32_t  OVT2:1;   /*  */
	    vuint32_t  SYRE2:1;   /*  */
	    vuint32_t  DRQRE24:1;   /*  */
	    vuint32_t  TXE2:1;   /*  */
	    vuint32_t  PDRQRE2:1;   /*  */
	    vuint32_t  PDRSRE2:1;   /*  */
	    vuint32_t:1;
	    vuint32_t  OVR3:1;   /*  */
	    vuint32_t  OVT3:1;   /*  */
	    vuint32_t  SYRE3:1;   /*  */
	    vuint32_t  DRQRE3:1;   /*  */
	    vuint32_t  TXE3:1;   /*  */
	    vuint32_t  PDRQRE3:1;   /*  */
	    vuint32_t  PDRSRE3:1;   /*  */
	    vuint32_t:1;
	    vuint32_t  OVR4:1;   /*  */
	    vuint32_t  OVT4:1;   /*  */
	    vuint32_t  SYRE4:1;   /*  */
	    vuint32_t  DRQRE4:1;   /*  */
	    vuint32_t  TXE4:1;   /*  */
	    vuint32_t  PDRQRE4:1;   /*  */
	    vuint32_t  PDRSRE4:1;   /*  */
	} B;
    } PTP_TMR_PEVENT;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  EXR:1;   /*  */
	    vuint32_t  OVR1:1;   /*  */
	    vuint32_t  OVT1:1;   /*  */
	    vuint32_t  SYRE1:1;   /*  */
	    vuint32_t  DRQRE1:1;   /*  */
	    vuint32_t  TXE1:1;   /*  */
	    vuint32_t  PDRQRE1:1;   /*  */
	    vuint32_t  PDRSRE1:1;   /*  */
	    vuint32_t  EXT:1;   /*  */
	    vuint32_t  OVR2:1;   /*  */
	    vuint32_t  OVT2:1;   /*  */
	    vuint32_t  SYRE2:1;   /*  */
	    vuint32_t  DRQRE24:1;   /*  */
	    vuint32_t  TXE2:1;   /*  */
	    vuint32_t  PDRQRE2:1;   /*  */
	    vuint32_t  PDRSRE2:1;   /*  */
	    vuint32_t:1;
	    vuint32_t  OVR3:1;   /*  */
	    vuint32_t  OVT3:1;   /*  */
	    vuint32_t  SYRE3:1;   /*  */
	    vuint32_t  DRQRE3:1;   /*  */
	    vuint32_t  TXE3:1;   /*  */
	    vuint32_t  PDRQRE3:1;   /*  */
	    vuint32_t  PDRSRE3:1;   /*  */
	    vuint32_t:1;
	    vuint32_t  OVR4:1;   /*  */
	    vuint32_t  OVT4:1;   /*  */
	    vuint32_t  SYRE4:1;   /*  */
	    vuint32_t  DRQRE4:1;   /*  */
	    vuint32_t  TXE4:1;   /*  */
	    vuint32_t  PDRQRE4:1;   /*  */
	    vuint32_t  PDRSRE4:1;   /*  */
	} B;
    } PTP_TMR_PEMASK;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TSVAL:32;   /*  */
	} B;
    } TMR_RXTS_H;

    int8_t PTP_reserved_0024[12]; 

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TSVAL:32;   /*  */
	} B;
    } TMR_RXTS_L;

    int8_t PTP_reserved_0034[12];

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TSVAL:32;   /*  */
	} B;
    } TMR_TXTS_H;

    int8_t PTP_reserved_0044[12];


    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TSVAL:32;   /*  */
	} B;
    } TMR_TXTS_L;

    int8_t PTP_reserved_0054[12]; 


    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  SYMSG:4;   /*  */
	    vuint32_t:4;
	    vuint32_t  DRMSG:4;   /*  */
	    vuint32_t:4;
	    vuint32_t  PDRMSG:4;   /*  */
	    vuint32_t:4;
	    vuint32_t  PDRPMSG:4;   /*  */
	    vuint32_t:4;
	} B;
    } PTP_TSPDR5;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  FUMSG:4;   /*  */
	    vuint32_t:4;
	    vuint32_t  DRPMSG:4;   /*  */
	    vuint32_t:4;
	    vuint32_t  PDFUMSG:4;   /*  */
	    vuint32_t:4;
	    vuint32_t  ANNMSG:4;   /*  */
	    vuint32_t:4;
	} B;
    } PTP_TSPDR6;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  SIGMSG:4;   /*  */
	    vuint32_t:4;
	    vuint32_t  MAMSG:4;   /*  */
	    vuint32_t:4;
	    vuint32_t  TRANSPEC:4;   /*  */
	    vuint32_t:12;
	} B;
    } PTP_TSPDR7;
};                                                

/****************************************************************/
/*                                                              */
/* Module: RTC  */
/*                                                              */
/****************************************************************/

struct RTC_tag {

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  ALM1P:1;   /*  */
	    vuint32_t  ALM2P:1;   /*  */
	    vuint32_t:2;
	    vuint32_t  PPSW:1;   /*  */
	    vuint32_t:1;   /*  */
	    vuint32_t  TCLK_PERIOD:10;   /*  */
	    vuint32_t:6;
	    vuint32_t  ETEP2:1;   /*  */
	    vuint32_t  ETEP1:1;   /*  */
	    vuint32_t  COPH:1;   /*  */
	    vuint32_t  CIPH:1;   /*  */
	    vuint32_t  TMSR:1;   /*  */
	    vuint32_t  DBG:1;   /*  */
	    vuint32_t  BYP:1;   /*  */
	    vuint32_t  TE:1;   /*  */
	    vuint32_t  CKSEL:2;   /*  */
	} B;
    } TMR_CTRL;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t:6;
	    vuint32_t  ETS2:1;   /*  */
	    vuint32_t  ETS1:1;   /*  */
	    vuint32_t:6;
	    vuint32_t  ALM1:1;   /*  */
	    vuint32_t  ALM2:1;   /*  */
	    vuint32_t  FS:1;   /*  */
	    vuint32_t:7;
	    vuint32_t  PP1:1;   /*  */
	    vuint32_t  PP2:1;   /*  */
	    vuint32_t  PP3:1;   /*  */
	    vuint32_t:5;
	} B;
    } TMR_TEVENT;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t:6;
	    vuint32_t  ETS2:1;   /*  */
	    vuint32_t  ETS1:1;   /*  */
	    vuint32_t:6;
	    vuint32_t  ALM1:1;   /*  */
	    vuint32_t  ALM2:1;   /*  */
	    vuint32_t  FS:1;   /*  */
	    vuint32_t:7;
	    vuint32_t  PP1:1;   /*  */
	    vuint32_t  PP2:1;   /*  */
	    vuint32_t  PP3:1;   /*  */
	    vuint32_t:5;
	} B;
    } TMR_TEMASK;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TMR_CNT:32;   /*  */
	} B;
    } TMR_CNT_L;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TMR_CNT:32;   /*  */
	} B;
    } TMR_CNT_H;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  ADDEND:32;   /*  */
	} B;
    } TMR_ADD;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TMR_ACC:32;   /*  */
	} B;
    } TMR_ACC;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  PRSC_OCK:16;   /*  */
	} B;
    } TMR_PRSC;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TMROFF:32;   /*  */
	} B;
    } TMROFF_L;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TMROFF:32;   /*  */
	} B;
    } TMROFF_H;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TMR_ALARM1:32;   /*  */
	} B;
    } TMR_ALARM1_L;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TMR_ALARM1:32;   /*  */
	} B;
    } TMR_ALARM1_H;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TMR_ALARM2:32;   /*  */
	} B;
    } TMR_ALARM2_L;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TMR_ALARM2:32;   /*  */
	} B;
    } TMR_ALARM2_H;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  FIPER:32;   /*  */
	} B;
    } TMR_FIPER1;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  FIPER:32;   /*  */
	} B;
    } TMR_FIPER2;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  FIPER:32;   /*  */
	} B;
    } TMR_FIPER3;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  ETTS:32;   /*  */
	} B;
    } TMR_ETTS1_L;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  ETTS:32;   /*  */
	} B;
    } TMR_ETTS1_H;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  ETTS:32;   /*  */
	} B;
    } TMR_ETTS2_L;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  ETTS:32;   /*  */
	} B;
    } TMR_ETTS2_H;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TMR_FSV:32;   /*  */
	} B;
    } TMR_FSV_L;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  TMR_FSV:32;   /*  */
	} B;
    } TMR_FSV_H;
};                                                

/****************************************************************/
/*                                                              */
/* Module: SWT  */
/*                                                              */
/****************************************************************/

struct SWT_tag {

    union {   /* SWT_MCR - Control Register */
	vuint32_t R;
	struct {
	    vuint32_t  MAP:8;   /* Master Acces Protection for Master n */
	    vuint32_t:14;
	    vuint32_t  KEY:1;   /* Reset on Invalid Access */
	    vuint32_t  RIA:1;   /* Reset on Invalid Access */
	    vuint32_t  WND:1;   /* Window Mode */
	    vuint32_t  ITR:1;   /* Interrupt Then Reset */
	    vuint32_t  HLK:1;   /* Hard Lock */
	    vuint32_t  SLK:1;   /* Soft Lock */
	    vuint32_t:1;
	    vuint32_t  STP:1;   /* Stop Mode Control */
	    vuint32_t  FRZ:1;   /* Debug Mode Control */
	    vuint32_t  WEN:1;   /* Watchdog Enabled */
	} B;
    } MCR;

    union {   /* SWT_IR - SWT Interrupt Register */
	vuint32_t R;
	struct {
	    vuint32_t:31;
	    vuint32_t  TIF:1;   /* Time Out Interrupt Flag */
	} B;
    } IR;

    union {   /* SWT_TO - SWT Time-Out Register */
	vuint32_t R;
	struct {
	    vuint32_t  WTO:32;   /* Watchdog Time Out Period */
	} B;
    } TO;

    union {   /* SWT_WIN - SWT Window Register */
	vuint32_t R;
	struct {
	    vuint32_t  WST:32;   /* Watchdog Time Out Period */
	} B;
    } WIN;

    union {   /* SWT_SR - SWT Service Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  WSC:16;   /* Watchdog Service Code */
	} B;
    } SR;

    union {   /* SWT_CO - SWT Counter Output Register */
	vuint32_t R;
	struct {
	    vuint32_t  CNT:32;   /* Watchdog Count */
	} B;
    } CO;

    union {   /* SWT_SK - SWT Service Key Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  SK:16;   /* Service Key */
	} B;
    } SK;
};                                                

/****************************************************************/
/*                                                              */
/* Module: STM  */
/*                                                              */
/****************************************************************/

struct STM_tag {

    union {   /* CR - Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  CPS:8;   /* Counter Prescaler */
	    vuint32_t:6;
	    vuint32_t  FRZ:1;   /* Freeze Control */
	    vuint32_t  TEN:1;   /* Timer Counter Enabled */
	} B;
    } CR;

    union {   /* CNT - STM Count Register */
	vuint32_t R;
	struct {
	    vuint32_t  CNT:32;   /* Timer Count Value */
	} B;
    } CNT;
    int8_t STM_reserved_0008[8];
    union {   /* CCRn - STM Channel Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:31;
	    vuint32_t  CEN:1;   /* Channel Enable */
	} B;
    } CCR0;

    union {   /* CIRn - STM Channel Interrupt Register */
	vuint32_t R;
	struct {
	    vuint32_t:31;
	    vuint32_t  CIF:1;   /* Channel Interrupt Flag */
	} B;
    } CIR0;

    union {   /* CMPn - STM Channel Compare Register */
	vuint32_t R;
	struct {
	    vuint32_t  CMP:32;   /* Compare Value for Channel n */
	} B;
    } CMP0;
    int8_t STM_reserved_001C[4];
    union {   /* CCRn - STM Channel Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:31;
	    vuint32_t  CEN:1;   /* Channel Enable */
	} B;
    } CCR1;

    union {   /* CIRn - STM Channel Interrupt Register */
	vuint32_t R;
	struct {
	    vuint32_t:31;
	    vuint32_t  CIF:1;   /* Channel Interrupt Flag */
	} B;
    } CIR1;

    union {   /* CMPn - STM Channel Compare Register */
	vuint32_t R;
	struct {
	    vuint32_t  CMP:32;   /* Compare Value for Channel n */
	} B;
    } CMP1;
    int8_t STM_reserved_002C[4];
    union {   /* CCRn - STM Channel Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:31;
	    vuint32_t  CEN:1;   /* Channel Enable */
	} B;
    } CCR2;

    union {   /* CIRn - STM Channel Interrupt Register */
	vuint32_t R;
	struct {
	    vuint32_t:31;
	    vuint32_t  CIF:1;   /* Channel Interrupt Flag */
	} B;
    } CIR2;

    union {   /* CMPn - STM Channel Compare Register */
	vuint32_t R;
	struct {
	    vuint32_t  CMP:32;   /* Compare Value for Channel n */
	} B;
    } CMP2;
    int8_t STM_reserved_003C[4];
    union {   /* CCRn - STM Channel Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:31;
	    vuint32_t  CEN:1;   /* Channel Enable */
	} B;
    } CCR3;

    union {   /* CIRn - STM Channel Interrupt Register */
	vuint32_t R;
	struct {
	    vuint32_t:31;
	    vuint32_t  CIF:1;   /* Channel Interrupt Flag */
	} B;
    } CIR3;

    union {   /* CMPn - STM Channel Compare Register */
	vuint32_t R;
	struct {
	    vuint32_t  CMP:32;   /* Compare Value for Channel n */
	} B;
    } CMP3;
};                                                

/****************************************************************/
/*                                                              */
/* Module: MCM  */
/*                                                              */
/****************************************************************/

struct MCM_tag {

    union {   /* PCT - Processor Core Type */
	vuint16_t R;
	struct {
	    vuint16_t  PCT:16;   /* Processor Core Type */
	} B;
    } PCT;

    union {   /* REV - SOC-Defined Platform Revision */
	vuint16_t R;
	struct {
	    vuint16_t  REV:16;   /* Platform Revision */
	} B;
    } REV;

    int8_t MCM_reserved_0004[4];

    union{   /* IMC - IPS On-Platform Module Configuration */
	vuint32_t R;
	struct {
	    vuint32_t  MC:32;   /* IPS Module Configuration */
	} B;
    } IMC;

    int8_t MCM_reserved_000C[3];

    union{   /* MRSR - Miscellaneous Reset Status Register */
	vuint8_t R;
	struct {
	    vuint8_t  POR:1;   /* Power on Reset */
	    vuint8_t  DIR:1;   /* Off-Platform Reset */
	    vuint8_t:6;
	} B;
    } MRSR;

    int8_t MCM_reserved_0010[15];

    union{   /* MIR - Miscellaneous Interrupt Register */
	vuint8_t R;
	struct {
	    vuint8_t  FB0AI:1;   /* Flash Bank 0 Abort Interrupt */
	    vuint8_t  FB0SI:1;   /* Flash Bank 0 Stall Interrupt */
	    vuint8_t  FB1AI:1;   /* Flash Bank 1 Abort Interrupt */
	    vuint8_t  FB1SI:1;   /* Flash Bank 1 Stall Interrupt */
	    vuint8_t:4;
	} B;
    } MIR;

    int8_t MCM_reserved_0020[4];

    union{   /* MUDCR - Miscellaneous User Defined Control Register */
	vuint32_t R;
	struct {
	    vuint32_t  MUDCR1:1;   /* User Defined Control Register */
	    vuint32_t:15;   /* User Defined Control Register */
	    vuint32_t  MUDCR2:1;   /* User Defined Control Register */
	    vuint32_t:15;   /* User Defined Control Register */
	} B;
    } MUDCR;

    int8_t MCM_reserved_0028[27];

    union{   /* ECR - ECC Configuration Register */
	vuint8_t R;
	struct {
	    vuint8_t:2;
	    vuint8_t  ER1BR:1;   /* Enable Platform RAM 1-bit Reporting */
	    vuint8_t  EF1BR:1;   /* Enable Platform FLASH 1-bit Reporting */
	    vuint8_t:2;
	    vuint8_t  ERNCR:1;   /* Enable Platform RAM Non-Correctable Reporting */
	    vuint8_t  EFNCR:1;   /* Enable Platform FLASH Non-Correctable Reporting */
	} B;
    } ECR;

    int8_t MCM_reserved_0044[3];

    union{   /* ESR - ECC Status Register */
	vuint8_t R;
	struct {
	    vuint8_t:2;
	    vuint8_t  R1BC:1;   /* Platform RAM 1-bit Correction */
	    vuint8_t  F1BC:1;   /* Platform FLASH 1-bit Correction */
	    vuint8_t:2;
	    vuint8_t  RNCE:1;   /* Platform RAM Non-Correctable Error */
	    vuint8_t  FNCE:1;   /* Platform FLASH Non-Correctable Error */
	} B;
    } ESR;

    int8_t MCM_reserved_0048[2];

    union{   /* EEGR - ECC Error Generation Register */
	vuint16_t R;
	struct {
	    vuint16_t:2;
	    vuint16_t  FRC1BI:1;   /* Force Platform RAM Continuous 1-Bit Data Inversions */
	    vuint16_t  FR11BI:1;   /* Force Platform RAM One 1-Bit Data Inversion */
	    vuint16_t:2;
	    vuint16_t  FRCNCI:1;   /* Force Platform RAM Continuous Noncorrectable Data Inversions */
	    vuint16_t  FR1NCI:1;   /* Force Platform RAM One Noncorrectable Data Inversions */
	    vuint16_t:1;
	    vuint16_t  ERRBIT:7;   /* Error Bit Position */
	} B;
    } EEGR;

    int8_t MCM_reserved_004C[4];

    union{   /* FEAR - Platform Flash ECC Error Address Register */
	vuint32_t R;
	struct {
	    vuint32_t  FEAR:32;   /* Platform Flash ECC Address */
	} B;
    } FEAR;

    int8_t MCM_reserved_0054[2];

    union{   /* FEMR - Platform Flash ECC Master Number Register */
	vuint8_t R;
	struct {
	    vuint8_t:4;
	    vuint8_t  FEMR:4;   /* Platform Flash ECC Master Number */
	} B;
    } FEMR;

    union{   /* FEAT - Platform Flash ECC Attributes Register */
	vuint8_t R;
	struct {
	    vuint8_t  Write:1;   /* AMBA-AHBH Write */
	    vuint8_t  Size:3;   /* AMBA-AHBH Size */
	    vuint8_t  Protection:4;   /* AMBA-AHBH PROT */
	} B;
    } FEAT;

    int8_t MCM_reserved_0058[4];

    union{   /* FEDR - Platform Flash ECC Data Register */
	vuint32_t R;
	struct {
	    vuint32_t  FEDR:32;   /* Platform Flash ECC Data */
	} B;
    } FEDR;

    union{   /* REAR - Platform RAM ECC Address Register */
	vuint32_t R;
	struct {
	    vuint32_t  REAR:32;   /* Platform RAM ECC Address */
	} B;
    } REAR;

    int8_t MCM_reserved_0064[1];

    union{   /* RESR - Platform RAM ECC Syndrome Register */
	vuint8_t R;
	struct {
	    vuint8_t  RESR:8;   /* Platform RAM ECC Syndrome */
	} B;
    } RESR;

    union{   /* REMR - Platform RAM ECC Master Number Register */
	vuint8_t R;
	struct {
	    vuint8_t:4;
	    vuint8_t  REMR:4;   /* Platform RAM ECC Master Number */
	} B;
    } REMR;

    union{   /* REAT - Platform RAM ECC Attributes Register */
	vuint8_t R;
	struct {
	    vuint8_t  Write:1;   /* AMBA-AHBH Write */
	    vuint8_t  Size:3;   /* AMBA-AHBH Size */
	    vuint8_t  Protection:4;   /* AMBA-AHBH PROT */
	} B;
    } REAT;

    int8_t MCM_reserved_0068[4];

    union{   /* REDR - Platform RAM ECC Data Register */
	vuint32_t R;
	struct {
	    vuint32_t  REDR:32;   /* Platform RAM ECC Data */
	} B;
    } REDR;
} ;                                                

/****************************************************************/
/*                                                              */
/* Module: EDMA  */
/*                                                              */
/****************************************************************/

struct EDMA_tag {

    union{   /* EDMA_CR - DMA Control Register */
	vuint32_t R;
	struct {
	    vuint32_t:29;
	    vuint32_t  ERCA:1;   /* Enable Round Robin Channel Arbitration */
	    vuint32_t  EDBG:1;   /* Enable Debug */
	    vuint32_t:1;  
	} B;
    } CR;

    union{   /* EDMA_ESR - DMA Error Status Register */
	vuint32_t R;
	struct {
	    vuint32_t  VLD:1;   /* Logical OR of DMAERRH and DMAERRL status bits */
	    vuint32_t:15;
	    vuint32_t  GPE:1;   /* Group Priority Error */
	    vuint32_t  CPE:1;   /* Channel Priority Error */
	    vuint32_t:2;
	    vuint32_t  ERRCHN:4;   /* Error Channel Number or Cancelled Channel Number */
	    vuint32_t  SAE:1;   /* Source Address Error */
	    vuint32_t  SOE:1;   /* Source Offset Error */
	    vuint32_t  DAE:1;   /* Destination Address Error */
	    vuint32_t  DOE:1;   /* Destination Offset Error */
	    vuint32_t  NCE:1;   /* Nbytes/Citer Configuration Error */
	    vuint32_t  SGE:1;   /* Scatter/Gather Configuration Error */
	    vuint32_t  SBE:1;   /* Source Bus Error */
	    vuint32_t  DBE:1;   /* Destination Bus Error */
	} B;
    } ESR;

    int8_t EDMA_reserved_0008[4];

    union{   /* EDMA_ERQRL - DMA Enable Request Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  ERQ15:1;   /* DMA Enable Request */
	    vuint32_t  ERQ14:1;   /* DMA Enable Request */
	    vuint32_t  ERQ13:1;   /* DMA Enable Request */
	    vuint32_t  ERQ12:1;   /* DMA Enable Request */
	    vuint32_t  ERQ11:1;   /* DMA Enable Request */
	    vuint32_t  ERQ10:1;   /* DMA Enable Request */
	    vuint32_t  ERQ9:1;   /* DMA Enable Request */
	    vuint32_t  ERQ8:1;   /* DMA Enable Request */
	    vuint32_t  ERQ7:1;   /* DMA Enable Request */
	    vuint32_t  ERQ6:1;   /* DMA Enable Request */
	    vuint32_t  ERQ5:1;   /* DMA Enable Request */
	    vuint32_t  ERQ4:1;   /* DMA Enable Request */
	    vuint32_t  ERQ3:1;   /* DMA Enable Request */
	    vuint32_t  ERQ2:1;   /* DMA Enable Request */
	    vuint32_t  ERQ1:1;   /* DMA Enable Request */
	    vuint32_t  ERQ0:1;   /* DMA Enable Request */
	} B;
    } ERQRL;

    int8_t EDMA_reserved_0010[4];

    union{   /* EDMA_EEIL - DMA Enable Error Interrupt Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  EEI15:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI14:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI13:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI12:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI11:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI10:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI9:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI8:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI7:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI6:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI5:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI4:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI3:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI2:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI1:1;   /* Enable Error Interrupt */
	    vuint32_t  EEI0:1;   /* Enable Error Interrupt */
	} B;
    } EEIRL;

    union{   /* EDMA_SERQR - DMA Set Enable Request Register */
	vuint8_t R;
	struct {
	    vuint8_t :1;
	    vuint8_t  SERQ:7;   /* Set Enable Request - Value between 16-63 will not do anything */
	} B;
    } SERQR;

    union{   /* EDMA_CERQR - DMA Clear Enable Request Register */
	vuint8_t R;
	struct {
	    vuint8_t :1;
	    vuint8_t  CERQ:7;   /* Clear Enable Request - Value between 16-63 will not do anything */
	} B;
    } CERQR;

    union{   /* EDMA_SEEI - DMA Set Enable Error Interrupt Register */
	vuint8_t R;
	struct {
	    vuint8_t :1;
	    vuint8_t  SEEI:7;   /* Set Enable Error Interrupt - Value between 16-63 will not do anything */
	} B;
    } SEEIR;

    union{   /* EDMA_CEEI - DMA Clear Enable Error Interrupt Register */
	vuint8_t R;
	struct {
	    vuint8_t :1;
	    vuint8_t  CEEI:7;   /* Clear Enable Error Interrupt - Value between 16-63 will not do anything */
	} B;
    } CEEIR;

    union{   /* EDMA_CIRQR - DMA Clear Interrupt Request */
	vuint8_t R;
	struct {
	    vuint8_t :1;
	    vuint8_t  CINT:7;   /* Clear Interrupt Request - Value between 16-63 will not do anything */
	} B;
    } CIRQR;

    union{   /* EDMA_CERR - DMA Clear Error */
	vuint8_t R;
	struct {
	    vuint8_t :1;
	    vuint8_t  CERR:7;   /* Clear Error Indicator - Value between 16-63 will not do anything */
	} B;
    } CERR;

    union{   /* EDMA_SSBR - DMA Set START Bit */
	vuint8_t R;
	struct {
	    vuint8_t  :1;
	    vuint8_t  SSBR:7;   /* Set START Bit - Value between 16-63 will not do anything */
	} B;
    } SSBR;


    union{   /* EDMA_CDNE - DMA Clear DONE Status */
	vuint8_t R;
	struct {
	    vuint8_t :1;
	    vuint8_t  CDSB:7;   /* Clear DONE Status Bit - Value between 16-63 will not do anything */
	} B;
    } CDSBR;

    int8_t EDMA_reserved_0020[4];

    union{   /* EDMA_INTL - DMA Interrupt Request Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  INT15:1;   /* DMA Interrupt Request */
	    vuint32_t  INT14:1;   /* DMA Interrupt Request */
	    vuint32_t  INT13:1;   /* DMA Interrupt Request */
	    vuint32_t  INT12:1;   /* DMA Interrupt Request */
	    vuint32_t  INT11:1;   /* DMA Interrupt Request */
	    vuint32_t  INT10:1;   /* DMA Interrupt Request */
	    vuint32_t  INT9:1;   /* DMA Interrupt Request */
	    vuint32_t  INT8:1;   /* DMA Interrupt Request */
	    vuint32_t  INT7:1;   /* DMA Interrupt Request */
	    vuint32_t  INT6:1;   /* DMA Interrupt Request */
	    vuint32_t  INT5:1;   /* DMA Interrupt Request */
	    vuint32_t  INT4:1;   /* DMA Interrupt Request */
	    vuint32_t  INT3:1;   /* DMA Interrupt Request */
	    vuint32_t  INT2:1;   /* DMA Interrupt Request */
	    vuint32_t  INT1:1;   /* DMA Interrupt Request */
	    vuint32_t  INT0:1;   /* DMA Interrupt Request */
	} B;
    } IRQRL;

    int8_t EDMA_reserved_0028[4];

    union{   /* EDMA_ERRL - DMA Error Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  ERR15:1;   /* DMA Error n */
	    vuint32_t  ERR14:1;   /* DMA Error n */
	    vuint32_t  ERR13:1;   /* DMA Error n */
	    vuint32_t  ERR12:1;   /* DMA Error n */
	    vuint32_t  ERR11:1;   /* DMA Error n */
	    vuint32_t  ERR10:1;   /* DMA Error n */
	    vuint32_t  ERR9:1;   /* DMA Error n */
	    vuint32_t  ERR8:1;   /* DMA Error n */
	    vuint32_t  ERR7:1;   /* DMA Error n */
	    vuint32_t  ERR6:1;   /* DMA Error n */
	    vuint32_t  ERR5:1;   /* DMA Error n */
	    vuint32_t  ERR4:1;   /* DMA Error n */
	    vuint32_t  ERR3:1;   /* DMA Error n */
	    vuint32_t  ERR2:1;   /* DMA Error n */
	    vuint32_t  ERR1:1;   /* DMA Error n */
	    vuint32_t  ERR0:1;   /* DMA Error n */
	} B;
    } ERL;

    int8_t EDMA_reserved_0030[4];

    union{   /* EDMA_HRSL - DMA Hardware Request Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  HRS15:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS14:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS13:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS12:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS11:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS10:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS9:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS8:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS7:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS6:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS5:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS4:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS3:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS2:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS1:1;   /* DMA Hardware Request Status */
	    vuint32_t  HRS0:1;   /* DMA Hardware Request Status */
	} B;
    } HRSL;

    int8_t EDMA_reserved_0038[200];

    union{   /* EDMA_CPR - DMA Channel 0 Priority */
	vuint8_t R;
	struct {
	    vuint8_t  ECP:1;   /* Enable Channel Preemption */
	    vuint8_t:3;
	    vuint8_t  CHPRI:4;   /* Channel 0 Arbitration Priority */
	} B;
    } CPR[16];

    int8_t EDMA_reserved_0110[3824];

    struct{

	union {   /* TCDn Word0 - Source Address */
	    vuint32_t R;
	    struct {
		vuint32_t  SADDR:32;   /* Source Address */
	    } B;
	} TCDWORD0;

	union {   /* TCDn Word1 - smod, ssize, dmod, dsize, soff */
	    vuint32_t R;
	    struct {
		vuint32_t  SMOD:5;   /* Source Address Modulo */
		vuint32_t  SSIZE:3;   /* Source Data Transfer Size */
		vuint32_t  DMOD:5;   /* Destination Address Module */
		vuint32_t  DSIZE:3;   /* Destination Data Transfer Size */
		vuint32_t  SOFF:16;   /* Source Address Signed Offset */
	    } B;
	} TCDWORD4;

	union {   /* TCDn Word2 - nbytes */
	    vuint32_t R;
	    struct {
		vuint32_t  NBYTES:32;   /* Inner Minor byte transfer Count */
	    } B;
	} TCDWORD8;

	union {   /* TCDn Word3 - slast */
	    vuint32_t R;
	    struct {
		vuint32_t  SLAST:32;   /* Last Source Address Adjustment */
	    } B;
	} TCDWORD12;

	union {   /* TCDn Word4 - daddr */
	    vuint32_t R;
	    struct {
		vuint32_t  DADDR:32;   /* Destination Address */
	    } B;
	} TCDWORD16;

	union {   /* TCDn Word5 -  citer.e_link, citer, doff */
	    vuint32_t R;
	    struct {
		vuint32_t  CITER_E_LINK:1;   /* Enable Channel to channel linking on minor loop complete */
		vuint32_t  CITER_LINKCH:6;   /* Link Channel Number */         
		vuint32_t  CITER:9;   /* Current Major Iteration Count */
		vuint32_t  DOFF:16;   /* Destination Address Signed Offset */
	    } B;
	} TCDWORD20;

	union {   /* TCDn Word6 -  dlast_sga */
	    vuint32_t R;
	    struct {
		vuint32_t  DLAST_SGA:32;   /* Last destination address adjustment */
	    } B;
	} TCDWORD24;

	union {   /* TCDn Word7 -  biter, etc. */
	    vuint32_t R;
	    struct {
		vuint32_t  BITER_E_LINK:1;
		vuint32_t	BITER_LINKCH:6;
		vuint32_t  BITER:9;   /* Enable Channel to Channel linking on minor loop complete */
		vuint32_t  BWC:2;   /* Bandwidth Control */
		vuint32_t:2;
		vuint32_t  MAJOR_LINKCH:4;   /* Link Channel Number */
		vuint32_t  DONE:1;   /* channel done */
		vuint32_t  ACTIVE:1;   /* Channel Active */
		vuint32_t  MAJOR_E_LINK:1;   /* Enable Channel to Channel Linking on major loop complete */
		vuint32_t  E_SG:1;   /* Enable Scatter/Gather Processing */
		vuint32_t  D_REQ:1;   /* Disable Request */
		vuint32_t  INT_HALF:1;   /* Enable an Interrupt when Major Counter is half complete */
		vuint32_t  INT_MAJ:1;   /* Enable an Interrupt when Major Iteration count completes */
		vuint32_t  START:1;   /* Channel Start */
	    } B;
	} TCDWORD28;
    }CHANNEL[16];

};

/****************************************************************/
/*                                                              */
/* Module: INTC  */
/*                                                              */
/****************************************************************/

struct INTC_tag  {

    union {   /* MCR - Mode Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t:26;
	    vuint32_t  VTES:1;   /* Vector Table Entry Size - Processor 1 */
	    vuint32_t:4;
	    vuint32_t  HVEN:1;   /* Hardware Vector Enable - Processor 1 */
	} B;
    } MCR;

    int8_t INTC_reserved_0004[4];

    union {   /* CPR - Current Priority Register - Processor 0 */
	vuint32_t R;
	struct {
	    vuint32_t:28;
	    vuint32_t  PRI:4;   /* Priority Bits */
	} B;
    } CPR;

    int8_t INTC_reserved_000C[4];

    union {   /* IACKR- Interrupt Acknowledge Register - Processor 0 */
	vuint32_t R;
	struct {
	    vuint32_t  VTBA:21;   /* Vector Table Base Address - Processor 0 */
	    vuint32_t  INTEC:9;   /* Interrupt Vector - Processor 0 */
	    vuint32_t:2;
	} B;
    } IACKR;

    int8_t INTC_reserved_00014[4];

    union {   /* EOIR- End of Interrupt Register - Processor 0 */
	vuint32_t R;
	struct { 
	    vuint32_t	EOI:32;
	} B;
    } EOIR;

    int8_t INTC_reserved_001C[4];

    union {   /* SSCIR0-7 INTC Software Set/Clear Interrupt Registers */
	vuint8_t R;
	struct { 
	    vuint8_t:6;
	    vuint8_t  SET:1;   /* Set Flag 0 bit */
	    vuint8_t  CLR:1;   /* Clear Flag 0 bit */
	} B;
    } SSCIR[8] ;

    int8_t INTC_reserved_0028[24];
    union {   /* PSR0_3 - 220_221 - Priority Select Registers */
	vuint8_t R;
	struct {
	    vuint8_t:4;
	    vuint8_t  PRI:4;   /* Priority Select */
	} B;
    } PSR[224];
};                                                

/****************************************************************/
/*                                                              */
/* Module: FEC  */
/*                                                              */
/****************************************************************/
struct FEC_tag {

    int8_t FEC_reserved_0000[4];

    union {   /* Bits are write 1 to clear */
	vuint32_t R;
	struct {
	    vuint32_t  IR_HBERR:1;   /*  */
	    vuint32_t  IR_BABR:1;   /*  */
	    vuint32_t  IR_BABT:1;   /*  */
	    vuint32_t  IR_GRA:1;   /*  */
	    vuint32_t  IR_TXF:1;   /*  */
	    vuint32_t  IR_TXB:1;   /*  */
	    vuint32_t  IR_RXF:1;   /*  */
	    vuint32_t  IR_RXB:1;   /*  */
	    vuint32_t  IR_MII:1;   /*  */
	    vuint32_t  IR_EBERR:1;   /*  */
	    vuint32_t  IR_LC:1;   /*  */
	    vuint32_t  IR_RL:1;   /*  */
	    vuint32_t  IR_UN:1;   /*  */
	    vuint32_t:19;
	} B;
    } EIR;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t  IR_HBERR:1;   /*  */
	    vuint32_t  IR_BABR:1;   /*  */
	    vuint32_t  IR_BABT:1;   /*  */
	    vuint32_t  IR_GRA:1;   /*  */
	    vuint32_t  IR_TXF:1;   /*  */
	    vuint32_t  IR_TXB:1;   /*  */
	    vuint32_t  IR_RXF:1;   /*  */
	    vuint32_t  IR_RXB:1;   /*  */
	    vuint32_t  IR_MII:1;   /*  */
	    vuint32_t  IR_EBERR:1;   /*  */
	    vuint32_t  IR_LC:1;   /*  */
	    vuint32_t  IR_RL:1;   /*  */
	    vuint32_t  IR_UN:1;   /*  */
	    vuint32_t:19;
	} B;
    } EIMR;

    int8_t FEC_reserved_000C[4];

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t:7;
	    vuint32_t  R_DES_ACTIVE:1;   /*  */
	    vuint32_t:24;
	} B;
    } RDAR;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t:7;
	    vuint32_t  X_DES_ACTIVE:1;   /*  */
	    vuint32_t:24;
	} B;
    } TDAR;

    int8_t FEC_reserved_0018[12]; 

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t:30;
	    vuint32_t  ETHER_EN:1;   /*  */
	    vuint32_t  RESET:1;   /*  */
	} B;
    } ECR;

    int8_t FEC_reserved_0028[24];

    union {   /* The MII_DATA register does not reset to a defined value */
	vuint32_t R;
	struct {
	    vuint32_t  ST:2;   /*  */
	    vuint32_t  OP:2;   /*  */
	    vuint32_t  PA:5;   /*  */
	    vuint32_t  RA:5;   /*  */
	    vuint32_t  TA:2;   /*  */
	    vuint32_t  DATA:16;   /*  */
	} B;
    } MMFR;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t:24;
	    vuint32_t  DIS_PREAMBLE:1;   /*  */
	    vuint32_t  MII_SPEED:6;   /*  */
	    vuint32_t:1;
	} B;
    } MSCR;

    int8_t FEC_reserved_0048[28];


    union {   /* MIB Control Register */
	vuint32_t R;
	struct {
	    vuint32_t  MIB_DISABLE:1;   /*  */
	    vuint32_t  MIB_IDLE:1;   /*  */
	    vuint32_t:30;
	} B;
    } MIBC;

    int8_t FEC_reserved_0068[28];

    union {   /* Receive Control register */
	vuint32_t R;
	struct {
	    vuint32_t:5;
	    vuint32_t  MAX_FL:11;   /*  */
	    vuint32_t:10;
	    vuint32_t  RCR_FCE:1;   /*  */
	    vuint32_t  RCR_BC_REJ:1;   /*  */
	    vuint32_t  RCR_PROM:1;   /*  */
	    vuint32_t  RCR_MII_MODE:1;   /*  */
	    vuint32_t  RCR_DRT:1;   /*  */
	    vuint32_t  RCR_LOOP:1;   /*  */
	} B;
    } RCR;

    int8_t FEC_reserved_0088[60];

    union {   /* Transmit control register */
	vuint32_t R;
	struct {
	    vuint32_t:27;
	    vuint32_t  RFC_PAUSE:1;   /*  */
	    vuint32_t  TFC_PAUSE:1;   /*  */
	    vuint32_t  FDEN:1;   /*  */
	    vuint32_t  HBC:1;   /*  */
	    vuint32_t  GTS:1;   /*  */
	} B;
    } TCR;

    int8_t FEC_reserved_00C8[28]; 

    union {   /* Reset value is not defined */
	vuint32_t R;
	struct {
	    vuint32_t  PADDR1:32;   /*  */
	} B;
    } PALR;

    union {   /* Reset Value of upper 16-bits is not defined */
	vuint32_t R;
	struct {
	    vuint32_t  PADDR2:16;   /*  */
	    vuint32_t  TYPE:16;   /*  */
	} B;
    } PAUR;

    union {   /* Reset Value of lower 16-bits is not defined */
	vuint32_t R;
	struct {
	    vuint32_t  OPCODE:16;   /*  */
	    vuint32_t  PAUSE_DUR:16;   /*  */
	} B;
    } OPDR;

    int8_t FEC_reserved_00F0[40];

    union {   /* This register is not reset to a defined value */
	vuint32_t R;
	struct {
	    vuint32_t  IADDR1:32;   /*  */
	} B;
    } IAUR;

    union {   /* This register is not reset to a defined value */
	vuint32_t R;
	struct {
	    vuint32_t  IADDR2:32;   /*  */
	} B;
    } IALR;

    union {   /* This register is not reset to a defined value */
	vuint32_t R;
	struct {
	    vuint32_t  GADDR1:32;   /*  */
	} B;
    } GAUR;

    union {   /* This register is not reset to a defined value */
	vuint32_t R;
	struct {
	    vuint32_t  GADDR2:32;   /*  */
	} B;
    } GALR;

    int8_t FEC_reserved_0128[28];

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t:30;
	    vuint32_t  X_WMRK:2;   /*  */
	} B;
    } TFWR;

    int8_t FEC_reserved_0148[4];

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t:22;
	    vuint32_t  R_BOUND:8;   /*  */
	    vuint32_t:2;
	} B;
    } FRBR;

    union {   /*  */
	vuint32_t R;
	struct {
	    vuint32_t:22;
	    vuint32_t  R_FSTART:8;   /*  */
	    vuint32_t:2;
	} B;
    } FRSR;

    int8_t FEC_reserved_0154[44];

    union {   /* This register is not reset to a defined value */
	vuint32_t R;
	struct {
	    vuint32_t  R_DES_START:30;   /*  */
	    vuint32_t:2;
	} B;
    } ERDSR;

    union {   /* This register is not reset to a defined value */
	vuint32_t R;
	struct {
	    vuint32_t  X_DES_START:30;   /*  */
	    vuint32_t:2;
	} B;
    } ETDSR;

    union {   /* This register is not reset to a defined value */
	vuint32_t R;
	struct {
	    vuint32_t:21;
	    vuint32_t  R_BUFF_SIZE:7;   /*  */
	    vuint32_t:4;
	} B;
    } EMRBR;

    int8_t FEC_reserved_018C[116];

    union {   /* Count of frames not counted correctly */
	vuint32_t R;
    } RMON_T_DROP;

    union {   /* RMON Tx packet count */
	vuint32_t R;
    } RMON_T_PACKETS;

    union {   /* RMON Tx Broadcast Packets */
	vuint32_t R;
    } RMON_T_BC_PKT;

    union {   /* RMON Tx Multicast Packets */
	vuint32_t R;
    } RMON_T_MC_PKT;

    union {   /* RMON Tx Packets w CRC Align error */
	vuint32_t R;
    } RMON_T_CRC_ALIGN;

    union {   /* RMON Tx Packets lt 64 bytes good crc */
	vuint32_t R;
    } RMON_T_UNDERSIZE;

    union {   /* RMON Tx Packets gt MAX_FL bytes good crc */
	vuint32_t R;
    } RMON_T_OVERSIZE;

    union {   /* Tx Packets lt 64 bytes bad crc */
	vuint32_t R;
    } RMON_T_FRAG;

    union {   /* Tx Packets gt MAX_FL bytes bad crc */
	vuint32_t R;
    } RMON_T_JAB;

    union {   /* Tx collision count */
	vuint32_t R;
    } RMON_T_COL;

    union {   /* Tx 64 byte packets */
	vuint32_t R;
    } RMON_T_P64;

    union {   /* RMON Tx 65 to 127 byte packets */
	vuint32_t R;
    } RMON_T_P65TO127;

    union {   /* RMON Tx 128 to 255 byte packets */
	vuint32_t R;
    } RMON_T_P128TO255;

    union {   /* RMON Tx 256 to 511 byte packets */
	vuint32_t R;
    } RMON_T_P256TO511;

    union {   /* RMON Tx 512 to 1023 byte packets */
	vuint32_t R;
    } RMON_T_P512TO1023;

    union {   /* RMON Tx 1024 to 2047 byte packets */
	vuint32_t R;
    } RMON_T_P1024TO2047;

    union {   /* RMON Tx packets w > 2048 bytes */
	vuint32_t R;
    } RMON_T_P_GTE2048;

    union {   /* RMON Tx Octets */
	vuint32_t R;
    } RMON_T_OCTETS;

    union {   /* Count of frames not counted correctly */
	vuint32_t R;
    } IEEE_T_DROP;

    union {   /* Frames Transmitted OK */
	vuint32_t R;
    } IEEE_T_FRAME_OK;

    union {   /* Frames Transmitted with Single Collision */
	vuint32_t R;
    } IEEE_T_1COL;

    union {   /* Frames Transmitted with Multiple Collisions */
	vuint32_t R;
    } IEEE_T_MCOL;

    union {   /* Frames Transmitted after Deferral Delay */
	vuint32_t R;
    } IEEE_T_DEF;

    union {   /* Frames Transmitted with Late Collision */
	vuint32_t R;
    } IEEE_T_LCOL;

    union {   /* Frames Transmitted with Excessive Collisions */
	vuint32_t R;
    } IEEE_T_EXCOL;

    union {   /* Frames Transmitted with Tx FIFO Underrun */
	vuint32_t R;
    } IEEE_T_MACERR;

    union {   /* Frames Transmitted with Carrier Sense Error */
	vuint32_t R;
    } IEEE_T_CSERR;

    union {   /* Frames Transmitted with SQE Error */
	vuint32_t R;
    } IEEE_T_SQE;

    union {   /* Flow Control Pause frames transmitted */
	vuint32_t R;
    } T_FDXFC;

    union {   /* Octet count  Frames Transmitted w/o Error */
	vuint32_t R;
    } IEEE_T_OCTETS_OK;

    int8_t FEC_reserved_0278[12];

    union {   /* RMON Rx packet count */
	vuint32_t R;
    } RMON_R_PACKETS;

    union {   /* RMON Rx Broadcast Packets */
	vuint32_t R;
    } RMON_R_BC_PKT;

    union {   /* RMON Rx Multicast Packets */
	vuint32_t R;
    } RMON_R_MC_PKT;

    union {   /* RMON Rx Packets w CRC/Align error */
	vuint32_t R;
    } RMON_R_CRC_ALIGN;

    union {   /* RMON Rx Packets lt 64 bytes good crc */
	vuint32_t R;
    } RMON_R_UNDERSIZE;

    union {   /* RMON Rx Packets gt MAX_FL bytes good crc */
	vuint32_t R;
    } RMON_R_OVERSIZE;

    union {   /* Rx Packets lt 64 bytes bad crc */
	vuint32_t R;
    } RMON_R_FRAG;

    union {   /* Rx Packets gt MAX_FL bytes bad crc */
	vuint32_t R;
    } RMON_R_JAB;

    union {   /*  */
	vuint32_t R;
    } RMON_R_RESVD_0;

    union {   /* Rx 64 byte packets */
	vuint32_t R;
    } RMON_R_P64;

    union {   /* RMON Rx 65 to 127 byte packets */
	vuint32_t R;
    } RMON_R_P65TO127;

    union {   /* RMON Rx 128 to 255 byte packets */
	vuint32_t R;
    } RMON_R_P128TO255;

    union {   /* RMON Rx 256 to 511 byte packets */
	vuint32_t R;
    } RMON_R_P256TO511;

    union {   /* RMON Rx 512 to 1023 byte packets */
	vuint32_t R;
    } RMON_R_P512TO1023;

    union {   /* RMON Rx 1024 to 2047 byte packets */
	vuint32_t R;
    } RMON_R_P1024TO2047;

    union {   /* RMON Rx packets w > 2048 bytes */
	vuint32_t R;
    } RMON_R_P_GTE2048;

    union {   /* RMON Rx Octets */
	vuint32_t R;
    } RMON_R_OCTETS;

    union {   /* Count of frames not counted correctly */
	vuint32_t R;
    } IEEE_R_DROP;

    union {   /* Frames Received OK */
	vuint32_t R;
    } IEEE_R_FRAME_OK;

    union {   /* Frames Received with CRC Error */
	vuint32_t R;
    } IEEE_R_CRC;

    union {   /* Frames Received with Alignment Error */
	vuint32_t R;
    } IEEE_R_ALIGN;

    union {   /* Receive Fifo Overflow count */
	vuint32_t R;
    } IEEE_R_MACERR;

    union {   /* Control Pause frames received */
	vuint32_t R;
    } R_FDXFC;

    union {   /* Octet count  Frames Rcvd w/o Error */
	vuint32_t R;
    } IEEE_R_OCTETS_OK;
};                                                

/****************************************************************/
/*                                                              */
/* Module: DSPI  */
/*                                                              */
/****************************************************************/

struct DSPI_tag {

    union {   /* MCR - Module Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t  MSTR:1;   /* Master/Slave mode select */
	    vuint32_t  CONT_SCKE:1;   /* Continuous SCK Enable */
	    vuint32_t  DCONF:2;   /* DSPI Configuration */
	    vuint32_t  FRZ:1;   /* Freeze */
	    vuint32_t  MTFE:1;   /* Modified Timing Format Enable */
	    vuint32_t  PCSSE:1;   /* Peripheral Chip Select Strobe Enable */
	    vuint32_t  ROOE:1;   /* Receive FIFO Overflow Overwrite Enable */
	    vuint32_t  PCSIS7:1;   /* Peripheral Chip Select Inactive State */
	    vuint32_t  PCSIS6:1;   /* Peripheral Chip Select Inactive State */
	    vuint32_t  PCSIS5:1;   /* Peripheral Chip Select Inactive State */
	    vuint32_t  PCSIS4:1;   /* Peripheral Chip Select Inactive State */
	    vuint32_t  PCSIS3:1;   /* Peripheral Chip Select Inactive State */
	    vuint32_t  PCSIS2:1;   /* Peripheral Chip Select Inactive State */
	    vuint32_t  PCSIS1:1;   /* Peripheral Chip Select Inactive State */
	    vuint32_t  PCSIS0:1;   /* Peripheral Chip Select Inactive State */         
	    vuint32_t:1;
	    vuint32_t  MDIS:1;   /* Module Disable */
	    vuint32_t  DIS_TXF:1;   /* Disable Transmit FIFO */
	    vuint32_t  DIS_RXF:1;   /* Disable Receive FIFO */
	    vuint32_t  CLR_TXF:1;   /* Clear TX FIFO */
	    vuint32_t  CLR_RXF:1;   /* Clear RX FIFO */
	    vuint32_t  SMPL_PT:2;   /* Sample Point */
	    vuint32_t:7;
	    vuint32_t  HALT:1;   /* Halt */
	} B;
    } MCR;

    union {   /* HCR - Hardware Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t	DSI:1;
	    vuint32_t:4;
	    vuint32_t  CTAR:3;   /* CTAR Number */
	    vuint32_t  TXFR:4;   /* TX FIFO Number */
	    vuint32_t  RXFR:4;   /* RX FIFO Number */
	    vuint32_t:16;
	} B;
    } HCR;

    union {   /* TCR - Transfer Count Register */
	vuint32_t R;
	struct {
	    vuint32_t  SPI_TCNT:16;   /* SPI Transfer Counter */
	    vuint32_t:16;
	} B;
    } TCR;


    union {   /* CTAR0-8 - Clock and Transfer Attribute Registers */
	vuint32_t R;
	struct {
	    vuint32_t  DBR:1;   /* Double Baud Rate */
	    vuint32_t  FMSZ:4;   /* Frame Size */
	    vuint32_t  CPOL:1;   /* Clock Polarity */
	    vuint32_t  CPHA:1;   /* Clock Phase */
	    vuint32_t  LSBFE:1;   /* LSB First Enable */
	    vuint32_t  PCSSCK:2;   /* PCS to SCK Delay Prescaler */
	    vuint32_t  PASC:2;   /* After SCK Delay Prescaler */
	    vuint32_t  PDT:2;   /* Delay after Transfer Prescaler */
	    vuint32_t  PBR:2;   /* Baud Rate Prescaler */
	    vuint32_t  CSSCK:4;   /* PCS to SCK Delay Scaler */
	    vuint32_t  ASC:4;   /* After SCK Delay Scaler */
	    vuint32_t  DT:4;   /* Delay after Transfer Scaler */
	    vuint32_t  BR:4;   /* Baud Rate Scaler */
	} B;
    } CTAR[8];

    union {   /* SR - Status Register */
	vuint32_t R;
	struct {
	    vuint32_t  TCF:1;   /* Transfer Complete Flag */
	    vuint32_t  TXRXS:1;   /* TX & RX Status */
	    vuint32_t:1;
	    vuint32_t  EOQF:1;   /* End of queue Flag */
	    vuint32_t  TFUF:1;   /* Transmit FIFO Underflow Flag */
	    vuint32_t:1;
	    vuint32_t  TFFF:1;   /* Transmit FIFO FIll Flag */
	    vuint32_t:5;
	    vuint32_t  RFOF:1;   /* Receive FIFO Overflow Flag */
	    vuint32_t:1;
	    vuint32_t  RFDF:1;   /* Receive FIFO Drain Flag */
	    vuint32_t:1;
	    vuint32_t  TXCTR:4;   /* TX FIFO Counter */
	    vuint32_t  TXNXTPTR:4;   /* Transmit Next Pointer */
	    vuint32_t  RXCTR:4;   /* RX FIFO Counter */
	    vuint32_t  POPNXTPTR:4;   /* Pop Next Pointer */
	} B;
    } SR;

    union {   /* RSER - DMA/Interrupt Request Register */
	vuint32_t R;
	struct {
	    vuint32_t  TCF_RE:1;   /* Transmission Complete Request Enable */
	    vuint32_t:2;
	    vuint32_t  EOQF_RE:1;   /* DSPI Finished Request Enable */
	    vuint32_t  TFUF_RE:1;   /* Transmit FIFO Underflow Request Enable */
	    vuint32_t:1;
	    vuint32_t  TFFF_RE:1;   /* Transmit FIFO Fill Request Enable */
	    vuint32_t  TFFF_DIRS:1;   /* Transmit FIFO Fill DMA or Interrupt Request Select */
	    vuint32_t:4;
	    vuint32_t  RFOF_RE:1;   /* Receive FIFO overflow Request Enable */
	    vuint32_t:1;
	    vuint32_t  RFDF_RE:1;   /* Receive FIFO Drain Request Enable */
	    vuint32_t  RFDF_DIRS:1;   /* Receive FIFO Drain DMA or Interrupt Request Select */
	    vuint32_t:16;
	} B;
    } RSER;

    union {   /* PUSHR - PUSH TX FIFO Register */
	vuint32_t R;
	struct {
	    vuint32_t  CONT:1;   /* Continuous Peripheral Chip Select Enable */
	    vuint32_t  CTAS:3;   /* Clock and Transfer Attributes Select */
	    vuint32_t  EOQ:1;   /* End of Queue */
	    vuint32_t  CTCNT:1;   /* Clear SPI_TCNT */
	    vuint32_t:2;   
	    vuint32_t  PCS7:1;   /* Peripheral Chip Select 0-7 */
	    vuint32_t  PCS6:1;   /* Peripheral Chip Select 0-7 */
	    vuint32_t  PCS5:1;   /* Peripheral Chip Select 0-7 */
	    vuint32_t  PCS4:1;   /* Peripheral Chip Select 0-7 */
	    vuint32_t  PCS3:1;   /* Peripheral Chip Select 0-7 */
	    vuint32_t  PCS2:1;   /* Peripheral Chip Select 0-7 */
	    vuint32_t  PCS1:1;   /* Peripheral Chip Select 0-7 */
	    vuint32_t  PCS0:1;   /* Peripheral Chip Select 0-7 */
	    vuint32_t  TXDATA:16;   /* Transmit Data */
	} B;
    } PUSHR;

    union {   /* POPR - POP RX FIFO Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  RXDATA:16;   /* Receive Data */
	} B;
    } POPR;

    union {   /* TXFR0-TXFR15 - DSPI Transmit FIFO Registers */
	vuint32_t R;
        struct {
	    vuint32_t  TXCMD:16;   /* Transmit Command */
	    vuint32_t  TXDATA:16;   /* Transmit Data */
	} B;
    } TXFR[5];

    int8_t DSPI_reserved_0050[44];


    union {   /* RXFR0-15 - Receive FIFO Registers */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  RXDATA:16;   /* Transmit Data */
	} B;
    } RXFR[5];
};                                                

/****************************************************************/
/*                                                              */
/* Module: I2C  */
/*                                                              */
/****************************************************************/
struct I2C_tag {
    union {   /* IBAD - I2C Bus Address Register */
	vuint8_t R;
	struct {
	    vuint8_t  ADR:7;   /* IBAD ADR - Slave Address */
	    vuint8_t:1;
	} B;
    } IBAD;

    union {   /* IBFD - I2C Bus Frequency Divider Register */
	vuint8_t R;
	struct {
	    vuint8_t  IBC:8;   /* IBC - I-Bus Clock Rate */
	} B;
    } IBFD;

    union {   /* IBCR - I2C Bus Control Register */
	vuint8_t R;
	struct {
	    vuint8_t  MDIS:1;   /* I2C Module Disable */
	    vuint8_t  IBIE:1;   /* I2C I-Bus Interrupt Enable */
	    vuint8_t  MSSL:1;   /* I2C Master/Slave Mode Select */
	    vuint8_t  TXRX:1;   /* I2C Transmit/Receive Mode Select */
	    vuint8_t  NOACK:1;   /* I2C Data Acknowledge Disable */
	    vuint8_t  RSTA:1;   /* I2C Repeat Start */
	    vuint8_t:1;
	    vuint8_t  IBDOZE:1;   /* I2C I-Bus Interface Stop in Doze Mode */
	} B;
    } IBCR;

    union {   /* IBSR - I2C Status Register */
	vuint8_t R;
	struct {
	    vuint8_t  TCF:1;   /* Transfer Complete */
	    vuint8_t  IAAS:1;   /* Addressed as Slave */
	    vuint8_t  IBB:1;   /* Bus Busy */
	    vuint8_t  IBAL:1;   /* Arbitration Lost */
	    vuint8_t:1;
	    vuint8_t  SRW:1;   /* Slave Read/Write */
	    vuint8_t  IBIF:1;   /* I-Bus Interrupt Flag */
	    vuint8_t  RXAK:1;   /* Receive Acknowledge */
	} B;
    } IBSR;

    union {   /* IBDR - I2C Data I/O Register */
	vuint8_t R;
	struct {
	    vuint8_t  DATA:8;   /* I2C Data */
	} B;
    } IBDR;

    union {   /* IBIC - I2C Bus Interrupt Config Register */
	vuint8_t R;
	struct {
	    vuint8_t  BIIE:1;   /* I2C Bus Idle Interrupt Enable */
	    vuint8_t:7;
	} B;
    } IBIC;
};                                                

/****************************************************************/
/*                                                              */
/* Module: FLEXCAN  */
/*                                                              */
/****************************************************************/

struct FLEXCAN_tag {

    union {   /* MCR - Module Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t  MDIS:1;   /* Module Disable */
	    vuint32_t  FRZ:1;   /* Freeze Enable */
	    vuint32_t  FEN:1;   /* FIFO Enable */
	    vuint32_t  HALT:1;   /* Halt Flexcan */
	    vuint32_t  NOT_RDY:1;   /* Flexcan Not Ready */
	    vuint32_t  WAK_MSK:1;   /* Wake Up Interrupt Mask */
	    vuint32_t  SOFT_RST:1;   /* Soft Reset */
	    vuint32_t  FRZ_ACK:1;   /* Freeze Mode Acknowledge */
	    vuint32_t  SUPV:1;   /* Supervisor Mode */
	    vuint32_t  SLF_WAK:1;   /* Self Wake Up */
	    vuint32_t  WRN_EN:1;   /* Warning Interrupt Enable */
	    vuint32_t  LPM_ACK:1;   /* Low Power Mode Acknowledge */
	    vuint32_t  WAK_SRC:1;   /* Wake Up Source */
	    vuint32_t:1;   
	    vuint32_t  SRX_DIS:1;   /* Self Reception Disable */
	    vuint32_t  BCC:1;   /* Backwards Compatibility Configuration */
	    vuint32_t:2;
	    vuint32_t  LPRIO_EN:1;   /* Local Priority Enable */
	    vuint32_t:3;
	    vuint32_t  IDAM:2;   /* ID Acceptance Mode */
	    vuint32_t:2;
	    vuint32_t  MAXMB:6;   /* Maximum Number of Message Buffers */
	} B;
    } MCR;

    union {   /* CTRL -  Control Register */
	vuint32_t R;
	struct {
	    vuint32_t  PRESDIV:8;   /* Prescaler Divsion Factor */
	    vuint32_t  RJW:2;   /* Resync Jump Width */
	    vuint32_t  PSEG1:3;   /* Phase Segment 1 */
	    vuint32_t  PSEG2:3;   /* Phase Segment 2 */
	    vuint32_t  BOFF_MSK:1;   /* Bus Off Mask */
	    vuint32_t  ERR_MSK:1;   /* Error Mask */
	    vuint32_t  CLK_SRC:1;   /* CAN Engine Clock Source */
	    vuint32_t  LPB:1;   /* Loop Back */
	    vuint32_t  TWRN_MSK:1;   /* Tx Warning Interrupt Mask */
	    vuint32_t  RWRN_MSK:1;   /* Rx Warning Interrupt Mask */
	    vuint32_t:2;
	    vuint32_t  SMP:1;   /* Sampling Mode */
	    vuint32_t  BOFF_REC:1;   /* Bus Off Recovery Mode */
	    vuint32_t  TSYN:1;   /* Timer Sync Mode */
	    vuint32_t  LBUF:1;   /* Lowest Buffer Transmitted First */
	    vuint32_t  LOM:1;   /* Listen-Only Mode */
	    vuint32_t  PROPSEG:3;   /* Propagation Segment */
	} B;
    } CTRL;

    union {   /* TIMER - Free Running Timer */
	vuint32_t R;
	struct { 
	    vuint32_t:16;
	    vuint32_t	TIMER:16;
	} B;
    } TIMER;

    int8_t FLEXCAN_reserved_000C[4];

    union {   /* RXGMASK - Rx Global Mask Register */
	vuint32_t R;
	struct {
	    vuint32_t  MI31:1;   /* Mask 31 Bit */
	    vuint32_t  MI30:1;   /* Mask 30 Bit */
	    vuint32_t  MI29:1;   /* Mask 29 Bit */
	    vuint32_t  MI28:1;   /* Mask 28 Bit */
	    vuint32_t  MI27:1;   /* Mask 27 Bit */
	    vuint32_t  MI26:1;   /* Mask 26 Bit */
	    vuint32_t  MI25:1;   /* Mask 25 Bit */
	    vuint32_t  MI24:1;   /* Mask 24 Bit */
	    vuint32_t  MI23:1;   /* Mask 23 Bit */
	    vuint32_t  MI22:1;   /* Mask 22 Bit */
	    vuint32_t  MI21:1;   /* Mask 21 Bit */
	    vuint32_t  MI20:1;   /* Mask 20 Bit */
	    vuint32_t  MI19:1;   /* Mask 19 Bit */
	    vuint32_t  MI18:1;   /* Mask 18 Bit */
	    vuint32_t  MI17:1;   /* Mask 17 Bit */
	    vuint32_t  MI16:1;   /* Mask 16 Bit */
	    vuint32_t  MI15:1;   /* Mask 15 Bit */
	    vuint32_t  MI14:1;   /* Mask 14 Bit */
	    vuint32_t  MI13:1;   /* Mask 13 Bit */
	    vuint32_t  MI12:1;   /* Mask 12 Bit */
	    vuint32_t  MI11:1;   /* Mask 11 Bit */
	    vuint32_t  MI10:1;   /* Mask 10 Bit */
	    vuint32_t  MI9:1;   /* Mask 9 Bit */
	    vuint32_t  MI8:1;   /* Mask 8 Bit */
	    vuint32_t  MI7:1;   /* Mask 7 Bit */
	    vuint32_t  MI6:1;   /* Mask 6 Bit */
	    vuint32_t  MI5:1;   /* Mask 5 Bit */
	    vuint32_t  MI4:1;   /* Mask 4 Bit */
	    vuint32_t  MI3:1;   /* Mask 3 Bit */
	    vuint32_t  MI2:1;   /* Mask 2 Bit */
	    vuint32_t  MI1:1;   /* Mask 1 Bit */
	    vuint32_t  MI0:1;   /* Mask 0 Bit */
	} B;
    } RXGMASK;

    union {   /* RX14MASK - Rx 14 Mask Register */
	vuint32_t R;
	struct { 
	    vuint32_t  MI31:1;   /* Mask 31 Bit */
	    vuint32_t  MI30:1;   /* Mask 30 Bit */
	    vuint32_t  MI29:1;   /* Mask 29 Bit */
	    vuint32_t  MI28:1;   /* Mask 28 Bit */
	    vuint32_t  MI27:1;   /* Mask 27 Bit */
	    vuint32_t  MI26:1;   /* Mask 26 Bit */
	    vuint32_t  MI25:1;   /* Mask 25 Bit */
	    vuint32_t  MI24:1;   /* Mask 24 Bit */
	    vuint32_t  MI23:1;   /* Mask 23 Bit */
	    vuint32_t  MI22:1;   /* Mask 22 Bit */
	    vuint32_t  MI21:1;   /* Mask 21 Bit */
	    vuint32_t  MI20:1;   /* Mask 20 Bit */
	    vuint32_t  MI19:1;   /* Mask 19 Bit */
	    vuint32_t  MI18:1;   /* Mask 18 Bit */
	    vuint32_t  MI17:1;   /* Mask 17 Bit */
	    vuint32_t  MI16:1;   /* Mask 16 Bit */
	    vuint32_t  MI15:1;   /* Mask 15 Bit */
	    vuint32_t  MI14:1;   /* Mask 14 Bit */
	    vuint32_t  MI13:1;   /* Mask 13 Bit */
	    vuint32_t  MI12:1;   /* Mask 12 Bit */
	    vuint32_t  MI11:1;   /* Mask 11 Bit */
	    vuint32_t  MI10:1;   /* Mask 10 Bit */
	    vuint32_t  MI9:1;   /* Mask 9 Bit */
	    vuint32_t  MI8:1;   /* Mask 8 Bit */
	    vuint32_t  MI7:1;   /* Mask 7 Bit */
	    vuint32_t  MI6:1;   /* Mask 6 Bit */
	    vuint32_t  MI5:1;   /* Mask 5 Bit */
	    vuint32_t  MI4:1;   /* Mask 4 Bit */
	    vuint32_t  MI3:1;   /* Mask 3 Bit */
	    vuint32_t  MI2:1;   /* Mask 2 Bit */
	    vuint32_t  MI1:1;   /* Mask 1 Bit */
	    vuint32_t  MI0:1;   /* Mask 0 Bit */

	} B;
    } RX14MASK;

    union {   /* RX15MASK - Rx 15 Mask Register */
	vuint32_t R;
	struct { 
	    vuint32_t  MI31:1;   /* Mask 31 Bit */
	    vuint32_t  MI30:1;   /* Mask 30 Bit */
	    vuint32_t  MI29:1;   /* Mask 29 Bit */
	    vuint32_t  MI28:1;   /* Mask 28 Bit */
	    vuint32_t  MI27:1;   /* Mask 27 Bit */
	    vuint32_t  MI26:1;   /* Mask 26 Bit */
	    vuint32_t  MI25:1;   /* Mask 25 Bit */
	    vuint32_t  MI24:1;   /* Mask 24 Bit */
	    vuint32_t  MI23:1;   /* Mask 23 Bit */
	    vuint32_t  MI22:1;   /* Mask 22 Bit */
	    vuint32_t  MI21:1;   /* Mask 21 Bit */
	    vuint32_t  MI20:1;   /* Mask 20 Bit */
	    vuint32_t  MI19:1;   /* Mask 19 Bit */
	    vuint32_t  MI18:1;   /* Mask 18 Bit */
	    vuint32_t  MI17:1;   /* Mask 17 Bit */
	    vuint32_t  MI16:1;   /* Mask 16 Bit */
	    vuint32_t  MI15:1;   /* Mask 15 Bit */
	    vuint32_t  MI14:1;   /* Mask 14 Bit */
	    vuint32_t  MI13:1;   /* Mask 13 Bit */
	    vuint32_t  MI12:1;   /* Mask 12 Bit */
	    vuint32_t  MI11:1;   /* Mask 11 Bit */
	    vuint32_t  MI10:1;   /* Mask 10 Bit */
	    vuint32_t  MI9:1;   /* Mask 9 Bit */
	    vuint32_t  MI8:1;   /* Mask 8 Bit */
	    vuint32_t  MI7:1;   /* Mask 7 Bit */
	    vuint32_t  MI6:1;   /* Mask 6 Bit */
	    vuint32_t  MI5:1;   /* Mask 5 Bit */
	    vuint32_t  MI4:1;   /* Mask 4 Bit */
	    vuint32_t  MI3:1;   /* Mask 3 Bit */
	    vuint32_t  MI2:1;   /* Mask 2 Bit */
	    vuint32_t  MI1:1;   /* Mask 1 Bit */
	    vuint32_t  MI0:1;   /* Mask 0 Bit */
	} B;
    } RX15MASK;

    union {   /* ECR - Error Counter Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  RX_ERR_COUNTER:8;   /* Rx Error Counter */
	    vuint32_t  TX_ERR_COUNTER:8;   /* Tx Error Counter */
	} B;
    } ECR;

    union {   /* ESR - Error and Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:14;
	    vuint32_t  TWRN_INT:1;   /* Tx Warning Interrupt Flag */
	    vuint32_t  RWRN_INT:1;   /* Rx Warning Interrupt Flag */
	    vuint32_t  BIT1_ERR:1;   /* Bit 1 Error */
	    vuint32_t  BIT0_ERR:1;   /* Bit 0 Error */
	    vuint32_t  ACK_ERR:1;   /* Acknowledge Error */
	    vuint32_t  CRC_ERR:1;   /* Cyclic Redundancy Check Error */
	    vuint32_t  FRM_ERR:1;   /* Form Error */
	    vuint32_t  STF_ERR:1;   /* Stuffing Error */
	    vuint32_t  TX_WRN:1;   /* Tx Error Counter */
	    vuint32_t  RX_WRN:1;   /* Rx Error Counter */
	    vuint32_t  IDLE:1;   /* CAN bus Idle State */
	    vuint32_t  TXRX:1;   /* Current Flexcan Status */
	    vuint32_t  FLT_CONF:2;   /* Fault Confinement State */
	    vuint32_t:1;
	    vuint32_t  BOFF_INT:1;   /* Bus Off Interrupt */
	    vuint32_t  ERR_INT:1;   /* Error Interrupt */
	    vuint32_t  WAK_INT:1;   /* Wake-Up Interrupt */
	} B;
    } ESR;

    int8_t FLEXCAN_reserved_0024[4];

    union {   /* IMASK1 - Interrupt Masks 1 Register */
	vuint32_t R;
	struct {
	    vuint32_t  BUF31M:1;   /* Buffer MB Mask 31 Bit */
	    vuint32_t  BUF30M:1;   /* Buffer MB Mask 30 Bit */
	    vuint32_t  BUF29M:1;   /* Buffer MB Mask 29 Bit */
	    vuint32_t  BUF28M:1;   /* Buffer MB Mask 28 Bit */
	    vuint32_t  BUF27M:1;   /* Buffer MB Mask 27 Bit */
	    vuint32_t  BUF26M:1;   /* Buffer MB Mask 26 Bit */
	    vuint32_t  BUF25M:1;   /* Buffer MB Mask 25 Bit */
	    vuint32_t  BUF24M:1;   /* Buffer MB Mask 24 Bit */
	    vuint32_t  BUF23M:1;   /* Buffer MB Mask 23 Bit */
	    vuint32_t  BUF22M:1;   /* Buffer MB Mask 22 Bit */
	    vuint32_t  BUF21M:1;   /* Buffer MB Mask 21 Bit */
	    vuint32_t  BUF20M:1;   /* Buffer MB Mask 20 Bit */
	    vuint32_t  BUF19M:1;   /* Buffer MB Mask 19 Bit */
	    vuint32_t  BUF18M:1;   /* Buffer MB Mask 18 Bit */
	    vuint32_t  BUF17M:1;   /* Buffer MB Mask 17 Bit */
	    vuint32_t  BUF16M:1;   /* Buffer MB Mask 16 Bit */
	    vuint32_t  BUF15M:1;   /* Buffer MB Mask 15 Bit */
	    vuint32_t  BUF14M:1;   /* Buffer MB Mask 14 Bit */
	    vuint32_t  BUF13M:1;   /* Buffer MB Mask 13 Bit */
	    vuint32_t  BUF12M:1;   /* Buffer MB Mask 12 Bit */
	    vuint32_t  BUF11M:1;   /* Buffer MB Mask 11 Bit */
	    vuint32_t  BUF10M:1;   /* Buffer MB Mask 10 Bit */
	    vuint32_t  BUF9M:1;   /* Buffer MB Mask 9 Bit */
	    vuint32_t  BUF8M:1;   /* Buffer MB Mask 8 Bit */
	    vuint32_t  BUF7M:1;   /* Buffer MB Mask 7 Bit */
	    vuint32_t  BUF6M:1;   /* Buffer MB Mask 6 Bit */
	    vuint32_t  BUF5M:1;   /* Buffer MB Mask 5 Bit */
	    vuint32_t  BUF4M:1;   /* Buffer MB Mask 4 Bit */
	    vuint32_t  BUF3M:1;   /* Buffer MB Mask 3 Bit */
	    vuint32_t  BUF2M:1;   /* Buffer MB Mask 2 Bit */
	    vuint32_t  BUF1M:1;   /* Buffer MB Mask 1 Bit */
	    vuint32_t  BUF0M:1;   /* Buffer MB Mask 0 Bit */
	} B;
    } IMASK1;

    int8_t FLEXCAN_reserved_002C[4]; 

    union {   /* IFLAG1 - Interrupt Flags 1 Register */
	vuint32_t R;
	struct {
	    vuint32_t  BUF31I:1;   /* Buffer MB Interrupt 31 Bit */
	    vuint32_t  BUF30I:1;   /* Buffer MB Interrupt 30 Bit */
	    vuint32_t  BUF29I:1;   /* Buffer MB Interrupt 29 Bit */
	    vuint32_t  BUF28I:1;   /* Buffer MB Interrupt 28 Bit */
	    vuint32_t  BUF27I:1;   /* Buffer MB Interrupt 27 Bit */
	    vuint32_t  BUF26I:1;   /* Buffer MB Interrupt 26 Bit */
	    vuint32_t  BUF25I:1;   /* Buffer MB Interrupt 25 Bit */
	    vuint32_t  BUF24I:1;   /* Buffer MB Interrupt 24 Bit */
	    vuint32_t  BUF23I:1;   /* Buffer MB Interrupt 23 Bit */
	    vuint32_t  BUF22I:1;   /* Buffer MB Interrupt 22 Bit */
	    vuint32_t  BUF21I:1;   /* Buffer MB Interrupt 21 Bit */
	    vuint32_t  BUF20I:1;   /* Buffer MB Interrupt 20 Bit */
	    vuint32_t  BUF19I:1;   /* Buffer MB Interrupt 19 Bit */
	    vuint32_t  BUF18I:1;   /* Buffer MB Interrupt 18 Bit */
	    vuint32_t  BUF17I:1;   /* Buffer MB Interrupt 17 Bit */
	    vuint32_t  BUF16I:1;   /* Buffer MB Interrupt 16 Bit */
	    vuint32_t  BUF15I:1;   /* Buffer MB Interrupt 15 Bit */
	    vuint32_t  BUF14I:1;   /* Buffer MB Interrupt 14 Bit */
	    vuint32_t  BUF13I:1;   /* Buffer MB Interrupt 13 Bit */
	    vuint32_t  BUF12I:1;   /* Buffer MB Interrupt 12 Bit */
	    vuint32_t  BUF11I:1;   /* Buffer MB Interrupt 11 Bit */
	    vuint32_t  BUF10I:1;   /* Buffer MB Interrupt 10 Bit */
	    vuint32_t  BUF9I:1;   /* Buffer MB Interrupt 9 Bit */
	    vuint32_t  BUF8I:1;   /* Buffer MB Interrupt 8 Bit */
	    vuint32_t  BUF7I:1;   /* Buffer MB Interrupt 7 Bit */
	    vuint32_t  BUF6I:1;   /* Buffer MB Interrupt 6 Bit */
	    vuint32_t  BUF5I:1;   /* Buffer MB Interrupt 5 Bit */
	    vuint32_t  BUF4I:1;   /* Buffer MB Interrupt 4 Bit */
	    vuint32_t  BUF3I:1;   /* Buffer MB Interrupt 3 Bit */
	    vuint32_t  BUF2I:1;   /* Buffer MB Interrupt 2 Bit */
	    vuint32_t  BUF1I:1;   /* Buffer MB Interrupt 1 Bit */
	    vuint32_t  BUF0I:1;   /* Buffer MB Interrupt 0 Bit */
	} B;
    } IFLAG1;


    int8_t FLEXCAN_reserved_0034[76];

    struct {


	union {   /* Message Buffer Control and Status */
	    vuint32_t R;
	    struct {
		vuint32_t:4;
		vuint32_t  CODE:4;   /* Message Buffer Code */
		vuint32_t:1;
		vuint32_t  SRR:1;   /* Substitute Remote Request */
		vuint32_t  IDE:1;   /* ID Extended Bit */
		vuint32_t  RTR:1;   /* Remote Transmission Request */
		vuint32_t  LENGTH:4;   /* Length of Data in Bytes */
		vuint32_t  TIMESTAMP:16;   /* Free-Running Counter Time Stamp */
	    } B;
	} MB_CS;

	union {   /* Message Buffer Identifier Field */
	    vuint32_t R;
	    struct {
		vuint32_t  PRIO:3;   /* Local Priority */
		vuint32_t  ID:29;   /* Frame Identifier */
	    } B;
	} MB_ID;

	union {   /* Message Buffer Data Field 0 - 3 */
	    vuint32_t R;
	    struct {            
		vuint32_t	DATA_BYTE0:8;
		vuint32_t	DATA_BYTE1:8;
		vuint32_t	DATA_BYTE2:8;
		vuint32_t	DATA_BYTE3:8;
	    } B;
	} MB_BYTE0_3;

	union {   /* Message Buffer Data Field 4 - 7 */
	    vuint32_t R;
	    struct {            
		vuint32_t	DATA_BYTE4:8;
		vuint32_t	DATA_BYTE5:8;
		vuint32_t	DATA_BYTE6:8;
		vuint32_t	DATA_BYTE7:8;
	    } B;
	} MB_BYTE4_7;


    } MB[16];

    int8_t FLEXCAN_reserved_0180[1792];

    union {   /* FLEXCAN_RXIMR - FLEXCAN_RXIMR63 - RX Individual Mask Registers */
	vuint32_t R;
	struct {
	    vuint32_t  MB:32;   /* Mask Bits */
	} B;
    } RXIMR[16];
};                                                

/****************************************************************/
/*                                                              */
/* Module: SAI  */
/*                                                              */
/****************************************************************/

struct SAI_tag {

    union {   /* STCSR - Transmit Control Status Register */
	vuint32_t R;
	struct {
	    vuint32_t  TE:1;   /* Transmitter Enable */
	    vuint32_t:1;   
	    vuint32_t  DBGE:1;   /* DEBUG Enable */
	    vuint32_t  BCE:1;   /* Transmit Bit Clk Enable */
	    vuint32_t:2;
	    vuint32_t  FR:1;   /* Fifo Reser */
	    vuint32_t  SR:1;   /* Software Reset */
	    vuint32_t:3;
	    vuint32_t  WSF:1;   /* Word Start Flag */
	    vuint32_t  SEF:1;   /* Sync Error Flag */
	    vuint32_t  FEF:1;   /* Fifo Error Flag */
	    vuint32_t  FWF:1;   /* Fifo Warning Flag */
	    vuint32_t  FRF:1;   /* Fifo Request Flag */
	    vuint32_t:3;
	    vuint32_t  WSIE:1;   /* Word Start Interrupt Enable */
	    vuint32_t  SEIE:1;   /* Sync Error Interrupt Enable */
	    vuint32_t  FEIE:1;   /* Fifo Error Interrupt Enable */
	    vuint32_t  FWIE:1;   /* Fifo Warning Interrupt Enable */
	    vuint32_t  FRIE:1;   /* Fifo Request Interrupt Enable */
	    vuint32_t:6;
	    vuint32_t  FWDE:1;   /* Fifo Warning DMA Enable */
	    vuint32_t  FRDE:1;   /* Fifo Request DMA Enable */
	} B;
    } STCSR;

    union {   /* STCR1 - Transmit Configuration Register 1 */
	vuint32_t R;
	struct {
	    vuint32_t:29;
	    vuint32_t  TFW:3;   /* SAI Transmit Fifo Watermark */
	} B;
    } STCR1;

    union {   /* STCR2 - Transmit Configuration Register 2 */
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t  CLKMODE:2;   /* SAI Transmit Synchronous Mode */
	    vuint32_t  BCP:1;   /* SAI Transmit Bit Clk Polarity */
	    vuint32_t  BCD:1;   /* SAI Transmit Bit Clk Direction */
	    vuint32_t:16;
	    vuint32_t  DIV:8;   /* SAI Transmit Bit Clk Divider */
	} B;
    } STCR2;

    union {   /* STCR3 - Transmit Configuration Register 3 */
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t  TCE:4;   /* SAI Transmit Channel Enable */
	    vuint32_t:12;
	    vuint32_t  WDFL:4;   /* SAI Transmit Word Flag */
	} B;
    } STCR3;

    union {   /* STCR4 - Transmit Configuration Register 4 */
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t  FRSZ:4;   /* SAI Transmit Frame Size */
	    vuint32_t:3;
	    vuint32_t  SYWD:5;   /* SAI Transmit Fync Width */
	    vuint32_t:3;
	    vuint32_t  MF:1;   /* SAI Transmit MSB First */
	    vuint32_t  FSE:1;   /* SAI Transmit Frame Sync Early */
	    vuint32_t:1;
	    vuint32_t  FSP:1;   /* SAI Transmit Frame Sync Polarity */
	    vuint32_t  FSD:1;   /* SAI Transmit Frame Sync Direction */
	} B;
    } STCR4;

    union {   /* STCR5 - Transmit Configuration Register 5 */
	vuint32_t R;
	struct {
	    vuint32_t:3;
	    vuint32_t  WNW:5;   /* SAI Transmit Word N Width */
	    vuint32_t:3;
	    vuint32_t  W0W:5;   /* SAI Transmit Word 0 Width */
	    vuint32_t:3;
	    vuint32_t  FBT:5;   /* SAI Transmit First Bit Shifted */
	    vuint32_t:8;
	} B;
    } STCR5;

    int8_t SAI_reserved_0018[8];

    union {   /* STDR - Transmit Data Register */
	vuint32_t R;
	struct {
	    vuint32_t  TDR:32;   /* SAI Transmit Data Register */
	} B;
    } STDR0;

    union {   /* STDR - Transmit Data Register */
	vuint32_t R;
	struct {
	    vuint32_t  TDR:32;   /* SAI Transmit Data Register */
	} B;
    } STDR1;

    union {   /* STDR - Transmit Data Register */
	vuint32_t R;
	struct {
	    vuint32_t  TDR:32;   /* SAI Transmit Data Register */
	} B;
    } STDR2;

    union {   /* STDR - Transmit Data Register */
	vuint32_t R;
	struct {
	    vuint32_t  TDR:32;   /* SAI Transmit Data Register */
	} B;
    } STDR3;

    int8_t SAI_reserved_0030[16];

    union {   /* STFR - Transmit Fifo Register */
	vuint32_t R;
	struct {
	    vuint32_t:13;
	    vuint32_t  WFP:3;   /* SAI Transmit Write Fifo Pointer */
	    vuint32_t:13;
	    vuint32_t  RFP:3;   /* SAI Transmit Read Fifo Pointer */
	} B;
    } STFR0;

    union {   /* STFR - Transmit Fifo Register */
	vuint32_t R;
	struct {
	    vuint32_t:13;
	    vuint32_t  WFP:3;   /* SAI Transmit Write Fifo Pointer */
	    vuint32_t:13;
	    vuint32_t  RFP:3;   /* SAI Transmit Read Fifo Pointer */
	} B;
    } STFR1;

    union {   /* STFR - Transmit Fifo Register */
	vuint32_t R;
	struct {
	    vuint32_t:13;
	    vuint32_t  WFP:3;   /* SAI Transmit Write Fifo Pointer */
	    vuint32_t:13;
	    vuint32_t  RFP:3;   /* SAI Transmit Read Fifo Pointer */
	} B;
    } STFR2;

    union {   /* STFR - Transmit Fifo Register */
	vuint32_t R;
	struct {
	    vuint32_t:13;
	    vuint32_t  WFP:3;   /* SAI Transmit Write Fifo Pointer */
	    vuint32_t:13;
	    vuint32_t  RFP:3;   /* SAI Transmit Read Fifo Pointer */
	} B;
    } STFR3;

    int8_t SAI_reserved_0050[16];

    union {   /* STMR - Transmit Mask Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  TWM:16;   /* SAI Transmit Word Mask */
	} B;
    } STMR0;

    int8_t SAI_reserved_0064[28];

    union {   /* SRCSR - Receive Control Status Register */
	vuint32_t R;
	struct {
	    vuint32_t  RE:1;   /* Receiver Enable */
	    vuint32_t:1;   /* STOP Enable */
	    vuint32_t  DBGE:1;   /* DEBUG Enable */
	    vuint32_t  BCE:1;   /* Receive Bit Clk Enable */
	    vuint32_t:2;
	    vuint32_t  FR:1;   /* Fifo Reser */
	    vuint32_t  SR:1;   /* Software Reset */
	    vuint32_t:3;
	    vuint32_t  WSF:1;   /* Word Start Flag */
	    vuint32_t  SEF:1;   /* Sync Error Flag */
	    vuint32_t  FEF:1;   /* Fifo Error Flag */
	    vuint32_t  FWF:1;   /* Fifo Warning Flag */
	    vuint32_t  FRF:1;   /* Fifo Request Flag */
	    vuint32_t:3;
	    vuint32_t  WSIE:1;   /* Word Start Interrupt Enable */
	    vuint32_t  SEIE:1;   /* Sync Error Interrupt Enable */
	    vuint32_t  FEIE:1;   /* Fifo Error Interrupt Enable */
	    vuint32_t  FWIE:1;   /* Fifo Warning Interrupt Enable */
	    vuint32_t  FRIE:1;   /* Fifo Request Interrupt Enable */
	    vuint32_t:6;
	    vuint32_t  FWDE:1;   /* Fifo Warning DMA Enable */
	    vuint32_t  FRDE:1;   /* Fifo Request DMA Enable */
	} B;
    } SRCSR;

    union {   /* SRCR1 - Receive Configuration Register 1 */
	vuint32_t R;
	struct {
	    vuint32_t:29;
	    vuint32_t  RFW:3;   /* SAI Receive Fifo Watermark */
	} B;
    } SRCR1;

    union {   /* SRCR2 - Receive Configuration Register 2 */
	vuint32_t R;
	struct {
	    vuint32_t:4;
	    vuint32_t  CLKMODE:2;   /* SAI Receive Synchronous Mode */
	    vuint32_t  BCP:1;   /* SAI Receive Bit Clk Polarity */
	    vuint32_t  BCD:1;   /* SAI Receive Bit Clk Direction */
	    vuint32_t:16;
	    vuint32_t  DIV:8;   /* SAI Receive Bit Clk Divider */
	} B;
    } SRCR2;

    union {   /* SRCR3 - Receive Configuration Register 3 */
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t  RCE:4;   /* SAI Receive Channel Enable */
	    vuint32_t:12;
	    vuint32_t  WDFL:4;   /* SAI Receive Word Flag */
	} B;
    } SRCR3;

    union {   /* SRCR4 - Receive Configuration Register 4 */
	vuint32_t R;
	struct {
	    vuint32_t:12;
	    vuint32_t  FRSZ:4;   /* SAI Receive Frame Size */
	    vuint32_t:3;
	    vuint32_t  SYWD:5;   /* SAI Receive Fync Width */
	    vuint32_t:3;
	    vuint32_t  MF:1;   /* SAI Receive MSB First */
	    vuint32_t  FSE:1;   /* SAI Receive Frame Sync Early */
	    vuint32_t:1;
	    vuint32_t  FSP:1;   /* SAI Receive Frame Sync Polarity */
	    vuint32_t  FSD:1;   /* SAI Receive Frame Sync Direction */
	} B;
    } SRCR4;

    union {   /* SRCR5 - Receive Configuration Register 5 */
	vuint32_t R;
	struct {
	    vuint32_t:3;
	    vuint32_t  WNW:5;   /* SAI Receive Word N Width */
	    vuint32_t:3;
	    vuint32_t  W0W:5;   /* SAI Receive Word 0 Width */
	    vuint32_t:3;
	    vuint32_t  FBT:5;   /* SAI Receive First Bit Shifted */
	    vuint32_t:8;
	} B;
    } SRCR5;

    int8_t SAI_reserved_0098[8];

    union {   /* SRDR - Receive Data Register */
	vuint32_t R;
	struct {
	    vuint32_t  RDR:32;   /* SAI Receive Data Register */
	} B;
    } SRDR0;

    union {   /* SRDR - Receive Data Register */
	vuint32_t R;
	struct {
	    vuint32_t  RDR:32;   /* SAI Receive Data Register */
	} B;
    } SRDR1;

    union {   /* SRDR - Receive Data Register */
	vuint32_t R;
	struct {
	    vuint32_t  RDR:32;   /* SAI Receive Data Register */
	} B;
    } SRDR2;

    union {   /* SRDR - Receive Data Register */
	vuint32_t R;
	struct {
	    vuint32_t  RDR:32;   /* SAI Receive Data Register */
	} B;
    } SRDR3;

    int8_t SAI_reserved_00B0[16];

    union {   /* SCFR - Receive Fifo Register */
	vuint32_t R;
	struct {
	    vuint32_t:13;
	    vuint32_t  WFP:3;   /* SAI Receive Write Fifo Pointer */
	    vuint32_t:13;
	    vuint32_t  RFP:3;   /* SAI Receive Read Fifo Pointer */
	} B;
    } SRFR0;

    union {   /* SCFR - Receive Fifo Register */
	vuint32_t R;
	struct {
	    vuint32_t:13;
	    vuint32_t  WFP:3;   /* SAI Receive Write Fifo Pointer */
	    vuint32_t:13;
	    vuint32_t  RFP:3;   /* SAI Receive Read Fifo Pointer */
	} B;
    } SRFR1;

    union {   /* SCFR - Receive Fifo Register */
	vuint32_t R;
	struct {
	    vuint32_t:13;
	    vuint32_t  WFP:3;   /* SAI Receive Write Fifo Pointer */
	    vuint32_t:13;
	    vuint32_t  RFP:3;   /* SAI Receive Read Fifo Pointer */
	} B;
    } SRFR2;

    union {   /* SCFR - Receive Fifo Register */
	vuint32_t R;
	struct {
	    vuint32_t:13;
	    vuint32_t  WFP:3;   /* SAI Receive Write Fifo Pointer */
	    vuint32_t:13;
	    vuint32_t  RFP:3;   /* SAI Receive Read Fifo Pointer */
	} B;
    } SRFR3;

    int8_t SAI_reserved_00D0[16];

    union {   /* SRMR - Receive Mask Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  RWM:16;   /* SAI Receive Word Mask */
	} B;
    } SRMR0;

    int8_t SAI_reserved_00E4[28];

    union {   /* SMCR - MCLk Control Register */
	vuint32_t R;
	struct {
	    vuint32_t  DUF:1;   /* SAI Divider Update Flag */
	    vuint32_t  MOE:1;   /* SAI MCLK Output Enable */
	    vuint32_t:4;
	    vuint32_t  MICS:2;   /* SAI MCLK Input Clk Select */
	    vuint32_t:24;
	} B;
    } SMCR;

    union {   /* SMDR - MCLk Divide Register */
	vuint32_t R;
	struct {
	    vuint32_t:11;
	    vuint32_t  FRACT:9;   /* SAI MCLK Fraction */
	    vuint32_t  DIVIDE:12;   /* SAI MCLK Divider */
	} B;
    } SMDR;
};                                                

/****************************************************************/
/*                                                              */
/* Module: DMA_CH_MUX  */
/*                                                              */
/****************************************************************/

struct DMA_CH_MUX_tag {

    union {   /* CHCONFIG[0-15] - Channel Configuration Registers */
	vuint8_t R;
	struct {
	    vuint8_t  ENBL:1;   /* DMA Channel Enable */
	    vuint8_t  TRIG:1;   /* DMA Channel Trigger Enable */
	    vuint8_t:1;
	    vuint8_t  SOURCE:5;   /* DMA Channel Source */
	} B;
    } CHCONFIG[16];


} ;                                                                                          


/****************************************************************/
/*                                                              */
/* Module: VIDEO_ENCODER  */
/*                                                              */
/****************************************************************/
struct VIDEO_ENCODER_tag {

    union{   /* VE_STATUS_CONFIG- Status and Configuration Register */
	vuint32_t R;
	struct {
	    vuint32_t  DMA_TXFER_IRQ:1;   /* VE_STATUS_CONFIG-DMA transfer request */
	    vuint32_t  VSTART_IRQ:1;   /* VE_STATUS_CONFIG-interrupt  at the start first valid pixel of Frame */
	    vuint32_t  SUBCHANNEL_IRQ:1;   /* VE_STATUS_CONFIG-interrupt for1 subchannel data */
	    vuint32_t  JPEG_IRQ:1;   /* VE_STATUS_CONFIG- interrupt request for1 JPEG in stream */
	    vuint32_t  LEN_ERR_IRQ:1;   /* VE_STATUS_CONFIG- interrupt for1 mismatch in active Image length and programmed Image length */
	    vuint32_t  COUNT_ERR_IRQ:1;   /* VE_STATUS_CONFIG-interrupt for1 mismatch in active Image height and programmed Image height */
	    vuint32_t  VEND_IRQ:1;   /* VE_STATUS_CONFIG-interrupt at end of encoding of current Frame */
	    vuint32_t:1;
	    vuint32_t  DMA_TXFER_IRQ_EN:1;   /* VE_STATUS_CONFIG-DMA transfer request enable */
	    vuint32_t  VSTART_IRQ_EN:1;   /* VE_STATUS_CONFIG-enable interrupt  at the start first valid pixel of Frame */
	    vuint32_t  SUBCHANNEL_IRQ_EN:1;   /* VE_STATUS_CONFIG-enable interrupt for1 subchannel data */
	    vuint32_t  JPEG_IRQ_EN:1;   /* VE_STATUS_CONFIG-enable interrupt request for1 JPEG in stream */
	    vuint32_t  LEN_ERR_IRQ_EN:1;   /* VE_STATUS_CONFIG-enable interrupt for1 mismatch in active Image length and programmed Image length */
	    vuint32_t  COUNT_ERR_IRQ_EN:1;   /* VE_STATUS_CONFIG-enable interrupt for1 mismatch in active Image height and programmed Image height */
	    vuint32_t  VEND_IRQ_EN:1;   /* VE_STATUS_CONFIG-enable interrupt at end of encoding of current Frame */
	    vuint32_t  ERROR_EN:1;   /* ERRCODE_IRQ_EN-Interupt enable for error in Sync bits */
	    vuint32_t  BUFFER_WRITE_ON:1;   /* VE_STATUS_CONFIG-buffer write enable */
	    vuint32_t  BUFFER_RESTART:1;   /* VE_STATUS_CONFIG-reload dma address from next picture start */
	    vuint32_t  VIDEO_ENCODER_ON:1;   /* VE_STATUS_CONFIG-Video Encoder on/off */
	    vuint32_t  SUBCHANNEL_DATA_REQUEST:1;   /* VE_STATUS_CONFIG-request subchannel data */
	    vuint32_t  SYNC_MODE:1;   /* VE_STATUS_CONFIG- External/ internal sync */
	    vuint32_t  BIT_WIDTH_IN:2;   /* VE_STATUS_CONFIG-input video data width1 */
	    vuint32_t  SUBCHANNEL_START_POINT:1;   /* VE_STATUS_CONFIG-start counting subchannel pixels from posedge of vsync/first valid pixel */
	    vuint32_t  ERROR_CODE_1_IRQ:1;   /* VE_STATUS_CONFIG-Protection single bit error interrupt request */
	    vuint32_t  ERROR_CODE_2_IRQ:1;   /* VE_STATUS_CONFIG-Protection double bit error interrupt request */
	    vuint32_t  HREF_POL:1;   /* HREF_POL-Defines the active polarity of HREF signal.Applicable only for1 External Sync Mode */
	    vuint32_t  VSYNC_POL:1;   /* VSYNC_POL-Defines the active polarity of VSYNC signal.Applicable only for External Sync Mode */
	    vuint32_t  PIXEL_ODER:1;   /* PIXEL_ODER-Defines whether first chroma pixel or luma pixel will come in the camera input stream.Apllicable both for1 internal & external sync modes */
	    vuint32_t  PIXEL_CLOCK_POLARITY:1;   /* PIXEL_CLK_POL-Polarity of Pixel Clock */
	    vuint32_t  SW_RESET:1;   /* SW_RST-Software Reset */
	    vuint32_t:1;
	} B;
    } STATUS_CONFIG;

    union{   /* VE_PICTURE_SIZE- Register holding picture height and width */
	vuint32_t R;
	struct {
	    vuint32_t:18;
	    vuint32_t  PICTURE_VSIZE:7;   /* VE_PICTURE_SIZE- Nuber of lines in a field x16 */
	    vuint32_t  PICTURE_HSIZE:7;   /* VE_PICTURE_SIZE- Nuber of pixels in a line x16 */
	} B;
    } PICTURE_SIZE;

    union{   /* VE_PIXEL_COUNT- Register holding number of pixels to count befor1 writing into subchannel SRAM */
	vuint32_t R;
	struct {
	    vuint32_t:23;
	    vuint32_t  PIXEL_COUNT:9;   /* VE_PIXEL_COUNT- Holding number of pixels to count befor1 writing into subchannel SRAM */
	} B;
    } PIXEL_COUNT;

    int8_t VIDEO_ENCODER_reserved_000C[4];

    union{   /* VE_DMA_ADDRESS- Register holding address where video encoder is currently writing */
	vuint32_t R;
	struct {
	    vuint32_t:19;
	    vuint32_t  DMA_ADDRESS:11;   /* VE_DMA_ADDRESS- Holding address where video encoder is currently writing */
	    vuint32_t:2;
	} B;
    } DMA_ADDRESS;

    union{   /* VE_DMA_VSTART_ADDRESS- Register holding address where at next field will start */
	vuint32_t R;
	struct {
	    vuint32_t:19;
	    vuint32_t  DMA_VSTART_ADDRESS:11;   /* VE_DMA_VSTART_ADDRESS- Holding address where at next field will start */
	    vuint32_t:2;
	} B;
    } DMA_VSTART_ADDRESS;

    union{   /* VE_DMA_VEND_ADDRESS- Register holding address where write of current field ended */
	vuint32_t R;
	struct {
	    vuint32_t:19;
	    vuint32_t  DMA_VEND_ADDRESS:11;   /* VE_DMA_VEND_ADDRESS- Holding address where writing of current field ended */
	    vuint32_t:2;
	} B;
    } DMA_VEND_ADDRESS;

    union{   /* VE_DMA_ALARM_ADDRESS- Register holding address for1 dma alarm */
	vuint32_t R;
	struct {
	    vuint32_t:19;
	    vuint32_t  DMA_ALARM_ADDRESS:11;   /* VE_DMA_ALARM_ADDRESS- Holding address for1 dma alarm */
	    vuint32_t:2;
	} B;
    } DMA_ALARM_ADDRESS;

    union{   /* VE_SUBCHANNEL_BUFFER_START- Register holding address of first pixel of subchannel stream */
	vuint32_t R;
	struct {
	    vuint32_t:8;
	    vuint32_t  SUBCHANNEL_BUFFER_START:24;   /* VE_SUBCHANNEL_BUFFER_START-Holding address of first pixel of subchannel stream */
	} B;
    } SUBCHANNEL_BUFFER_START;

    union{   /* VE_JPEG_DATA_IN_OFFSET - Register pointing to buffer RAM where JPEG in stream will be sourced next time encoder request */
	vuint32_t R;
	struct {
	    vuint32_t:22;
	    vuint32_t  JPEGIN_DATA_OFFSET:8;   /* VE_JPEG_DATA_IN_OFFSET- offset to buffer RAM where JPEG in stream will be sourced next time encoder request */
	    vuint32_t:2;
	} B;
    } JPEG_IN_OFFSET;

    union{   /* RC_REGS_SE - Register Selects between available Rate Control status registers */
	vuint32_t R;
	struct {
	    vuint32_t:30;
	    vuint32_t  RC_REGS_SEL:2;   /* RC_REGS_SE - Register Selects between available Rate Control status registers */
	} B;
    } RC_REGS_SEL;

    union{   /* Maximum number of bits threshold used in rate control of Luminance DCT blocks */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  LUMTH:16;   /* Maximum number of bits threshold used in rate control of Luminance DCT blocks */
	} B;
    } LUMTH;


    union{   /* Bitmapped register that controls JPEGE-X operation mode. */
	vuint32_t R;
	struct {
	    vuint32_t:23;
	    vuint32_t  AUTOCLR_GO:1;   /* Auto clear GO bit when the core exits from its current encoding mode of operation */
	    vuint32_t  AUTOCLR_CONF:1;   /* Auto clear CONF bit when the core exits from configuration mode */
	    vuint32_t  GO:1;   /* Go. When 1 the core exits idle mode */
	    vuint32_t  CONF:1;   /* Configuration. When 1 the core enters configuration mode */
	    vuint32_t  EXTSEQ:1;   /* Selector between Baseline (0) and Extended Sequential (1) mode of operation */
	    vuint32_t:2;
	    vuint32_t  SWR:1;   /* Soft reset */
	    vuint32_t  LP:1;   /* Low Power. When set1 core enters low-power mode */
	} B;
    } MODE;

    union{   /* Bitmapped register that controls JPEGE-X output stream generation mode. */
	vuint32_t R;
	struct {
	    vuint32_t:19;
	    vuint32_t  DICOM:1;   /* Transmit SOF0 and SOS markers after DQT and DHT markers to support DICOM format1 */
	    vuint32_t  COMB_DHT:1;   /* Transmit all Huffman Tables in one combined DHT segment to support EXIF 2.2 format1 */
	    vuint32_t  COMB_DQT:1;   /* Transmit all Quantization Tables in one combined DQT segment to support EXIF 2.2 format1 */
	    vuint32_t  MCOM:1;   /* Mask COM: If zero, no COM segments are output by the core */
	    vuint32_t  MAPP:1;   /* Mask APP: If zero, no APP segments are output by the core */
	    vuint32_t  MDNL:1;   /* Mask DNL: If zero, no DNL segments are output by the core */
	    vuint32_t  MSOS:1;   /* Mask SOS: If zero, no SOS segments are output by the core */
	    vuint32_t:2;
	    vuint32_t  MDHT:1;   /* Mask DHT: If zero, no DHT segments are output by the core */
	    vuint32_t  MDQT:1;   /* Mask DQT: If zero, no DQT segments are output by the core */
	    vuint32_t  MDRI:1;   /* Mask DRI: If zero, no DRI segments are output by the core */
	    vuint32_t  MSOF0:1;   /* Mask SOF0: If zero, no SOF0 segments are output by the core */
	} B;
    } CFG_MODE;

    union{   /* CHRTH Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  CHRTH:16;   /* Maximum number of bits threshold used in rate control of Chrominance DCT blocks */
	} B;
    } CHRTH;

    int8_t VIDEO_ENCODER_reserved_003C[4];

    union{   /* Image width */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  X:16;   /* Image width */
	} B;
    } JPEG_STAT0;

    union{   /* Image height */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  Y:16;   /* Image height */
	} B;
    } JPEG_STAT1;

    union{   /* Number of MCUs in current scan in horizontal direction */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  HMCU:16;   /* Number of MCUs in current scan in horizontal direction */
	} B;
    } JPEG_STAT2;

    union{   /* Number of MCUs in current scan in vertical direction */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  VMCU:16;   /* Number of MCUs in current scan in vertical direction */
	} B;
    } JPEG_STAT3;

    union{   /* Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  C0:8;   /* Component identifier for1 scan component 0 */
	    vuint32_t  H0:3;   /* Horizontal sampling for1 scan component 0 */
	    vuint32_t  V0:3;   /* Vertical sampling for1 scan component 0 */
	    vuint32_t  Tq0:2;   /* Quantization table identifier for1 scan component 0 */
	} B;
    } JPEG_STAT4;

    union{   /* Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  C1:8;   /* Component identifier for1 scan component 1 */
	    vuint32_t  H1:3;   /* Horizontal sampling for1 scan component 1 */
	    vuint32_t  V1:3;   /* Vertical sampling for1 scan component 1 */
	    vuint32_t  Tq1:2;   /* Quantization table identifier for1 scan component 1 */
	} B;
    } JPEG_STAT5;

    union{   /* Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  C2:8;   /* Component identifier for1 scan component 2 */
	    vuint32_t  H2:3;   /* Horizontal sampling for1 scan component 2 */
	    vuint32_t  V2:3;   /* Vertical sampling for1 scan component 2 */
	    vuint32_t  Tq2:2;   /* Quantization table identifier for1 scan component 2 */
	} B;
    } JPEG_STAT6;

    union{   /* Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  C3:8;   /* Component identifier for1 scan component 3 */
	    vuint32_t  H3:3;   /* Horizontal sampling for1 scan component 3 */
	    vuint32_t  V3:3;   /* Vertical sampling for1 scan component 3 */
	    vuint32_t  Tq3:2;   /* Quantization table identifier for1 scan component 3 */
	} B;
    } JPEG_STAT7;

    union{   /* Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:24;
	    vuint32_t  Nf:8;   /* Number of components in frame1 */
	} B;
    } JPEG_STAT8;

    union{   /* Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  DRI:16;   /* Restart interval */
	} B;
    } JPEG_STAT9;

    union{   /* Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  HMAX:4;   /* Maximum horizontal sampling factor in frame1 */
	    vuint32_t  VMAX:4;   /* Maximum vertical sampling factor in frame1 */
	    vuint32_t  NBMCU:4;   /* Number of blocks per MCU in current scan */
	    vuint32_t  NS:4;   /* Number of components in current scan */
	} B;
    } JPEG_STAT10;

    union{   /* Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  VHS3:4;   /* Number of blocks of 4th component in MCU.  VHS3=VHS2+V3*H3, */
	    vuint32_t  VHS2:4;   /* Number of blocks of 3rd component in MCU.  VHS2=VHS1+V2*H2, */
	    vuint32_t  VHS1:4;   /* Number of blocks of 2nd component in MCU.  VHS1=VHS0+V1*H1 */
	    vuint32_t  VHS0:4;   /* Number of blocks of 1st component in MCU.  VHS0=V0*H0. */
	} B;
    } JPEG_STAT11;

    union{   /* Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:20;
	    vuint32_t  SCANACTIVE:1;   /* Indicates that core encodes entropy coded scan data */
	    vuint32_t  PIXELIN_RDY:1;   /* Pixel input data ready: Core is ready to accept new pixel data */
	    vuint32_t  JPEGIN_RDY:1;   /* JPEG stream input data ready: Core is ready to accept new data on JPEG stream input interface */
	    vuint32_t  CONFIFERROR:1;   /* Configuration error indicator */
	    vuint32_t  SOF_E:1;   /* SOF0 error: 1 when an error in SOF0 segment is detected */
	    vuint32_t  SOS_E:1;   /* Scan error : 1 when an error in SOS segment is detected */
	    vuint32_t  DQT_E:1;   /* DQT error : 1 when an error in DQT segment is detected */
	    vuint32_t  DHT_E:1;   /* DHT error : 1 when an error in DHT segment is detected */
	    vuint32_t  DNL_E:1;   /* DNL error : 1 when an error in DNL segment is detected */
	    vuint32_t  DRI_E:1;   /* DRI error : 1 when an error in DRI segment is detected */
	    vuint32_t  APPn_E:1;   /* APPn error : 1 when an error in APPn segment is detected */
	    vuint32_t  COM_E:1;   /* COM error : 1 when an error in COM segment is detected */
	} B;
    } JPEG_STAT12;

    union{   /* Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  CFG_MODE:16;   /* Programmed CFG_MODE control register */
	} B;
    } JPEG_STAT13;

    union{   /* Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  RC_REGS0:16;   /* Programmed CFG_MODE control register */
	} B;
    } JPEG_STAT14;

    union{   /* Status Register */
	vuint32_t R;
	struct {
	    vuint32_t:16;
	    vuint32_t  RC_REGS1:16;   /* Programmed CFG_MODE control register */
	} B;
    } JPEG_STAT15;
};                                                

/****************************************************************** 
  | defines and macros (scope: module-local) 
  |-----------------------------------------------------------------*/
/* Define instances of modules */

/****************************************************************** 
  | defines and macros (scope: module-local) 
  |-----------------------------------------------------------------*/
/* Define instances of modules */

#define ADC   	(*(volatile struct ADC_tag *) 			0xFFE00000UL )                                                                              
#define CFLASH 	(*(volatile struct CFLASH_tag *) 		0xC3F88000UL )                            
#define CFLASH_SHADOW (*(volatile struct CFLASH_SHADOW_tag *) 	0x00200000UL )                            
#define CGM   	(*(volatile struct CGM_tag *) 			0xC3FE0000UL )                                                                                                           
#define CRC   	(*(volatile struct CRC_tag *) 			0xFFE68000UL )                            
#define DFLASH 	(*(volatile struct DFLASH_tag *) 		0xC3F8C000UL )                            
#define DMA_CH_MUX (*(volatile struct DMA_CH_MUX_tag *) 0xFFFDC000UL )                            
#define DSPI_0 	(*(volatile struct DSPI_tag *) 			0xFFF90000UL )                            
#define DSPI_1 	(*(volatile struct DSPI_tag *) 			0xFFF94000UL )                            
#define DSPI_2 	(*(volatile struct DSPI_tag *) 			0xFFF98000UL ) 
#define EDMA 	(*(volatile struct EDMA_tag *) 			0xFFF44000UL )                              
#define eTIMER 	(*(volatile struct eTIMER_tag *) 		0xFFE18000UL )                                                    
#define FCU   	(*(volatile struct FCU_tag *) 			0xFFE6C000UL )                           
#define FEC   	(*(volatile struct FEC_tag *) 			0xFFF4C000UL )                            
#define FLEXCAN (*(volatile struct FLEXCAN_tag *) 		0xFFFC0000UL )                            
#define I2C0  	(*(volatile struct I2C_tag *) 			0xFFE30000UL )                            
#define I2C1  	(*(volatile struct I2C_tag *) 			0xFFE34000UL )                            
#define INTC  	(*(volatile struct INTC_tag *) 			0xFFF48000UL )     
#define LINFLEX0 (*(volatile struct LINFLEX_tag *) 		0xFFE40000UL )  
#define LINFLEX1 (*(volatile struct LINFLEX_tag *) 		0xFFE44000UL )                                                      
#define ME    	(*(volatile struct ME_tag *) 			0xC3FDC000UL )                                                       
#define PCU   	(*(volatile struct PCU_tag *) 			0xC3FE8000UL )    
#define PFLASH 	(*(volatile struct PFLASH_tag *) 		0xFFE88000UL )                         
#define PIT_RTI (*(volatile struct PIT_RTI_tag *) 		0xC3FF0000UL ) 
#define PTP 	(*(volatile struct PTP_tag *) 			0xFFE74000UL )                            
#define RGM   	(*(volatile struct RGM_tag *) 			0xC3FE4000UL )     
#define RTC 	(*(volatile struct RTC_tag *) 			0xFFE78000UL )                        
#define SAI0   	(*(volatile struct SAI_tag *) 			0xFFFD8000UL )                            
#define SAI1 	(*(volatile struct SAI_tag *) 			0xFFFF0000UL )                            
#define SAI2 	(*(volatile struct SAI_tag *) 			0xFFFF4000UL )                            
#define SIUL  	(*(volatile struct SIUL_tag *) 			0xC3F90000UL )                            
#define MCM 	(*(volatile struct MCM_tag *) 			0xFFF40000UL )                            
#define SSCM  	(*(volatile struct SSCM_tag *) 			0xC3FD8000UL )                            
#define STM   	(*(volatile struct STM_tag *) 			0xFFF3C000UL )                            
#define SWT   	(*(volatile struct SWT_tag *) 			0xFFF38000UL )                            
#define VE 	(*(volatile struct VIDEO_ENCODER_tag *) 	0xFFFF8000UL )                                                      
#define WKPU  	(*(volatile struct WKPU_tag *) 			0xC3F94000UL )

#ifdef __MWERKS__
#pragma pop
#endif

#ifdef __cplusplus
}
#endif
#endif /* _MPC5604E_H_*/
/* End of file */
