/*
 * bsp.c
 *
 *  Created on: Sep 9, 2016
 *      Author: jason
 */

#include "MPC5604E.h"
#include "IntcInterrupts.h"
#include "bsp.h"
int time_tick = 0;
//note  delay(500) is 65.2us
void
Delay (int rep)
{
    volatile int32_t cnt = 0;

    while (cnt < rep)
    {
        cnt++;
    }
}

void
DisableWatchdog ()
{

    SWT.SR.R = 0x0000c520;      /* Write keys to clear soft lock bit */
    SWT.SR.R = 0x0000d928;
    SWT.MCR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}

void
BSP_TmrTickISR (void)
{
    PIT_RTI.CH[0].TFLG.B.TIF = 0x01;
	time_tick++;
}
void
BSP_SysTickInit (void)
{
    INTC_InstallINTCInterruptHandler (BSP_TmrTickISR, 59, 15);

    PIT_RTI.PITMCR.B.MDIS = 0x00;
    PIT_RTI.PITMCR.B.FRZ = 0x01;
    PIT_RTI.CH[0].CVAL.B.TVL = 0x00000000UL;
    PIT_RTI.CH[0].LDVAL.B.TSV = FREE_TIMER_MAX; // bus clock is 60mhz
    PIT_RTI.CH[0].TFLG.B.TIF = 0x01;
    PIT_RTI.CH[0].TCTRL.B.TIE = 0x01;
    PIT_RTI.CH[0].TCTRL.B.TEN = 0x01;
}

void
initModes (void)
{
    ME.MER.R = 0x0000001D;      //  Enable DRUN, RUN0, SAFE, RESET modes                 
    ME.RUN_PC[0].R = 0x000000FE;    // Enable all peripherals in all modes


    // Configure IDF=4, ODF=10, NDIV=64 - this is 40Mhz
    CGM.FMPLL_CR.R = 0x12400000;

    CGM.FMPLL_CR.B.NDIV = 48;
  //CGM.FMPLL_CR.B.IDF = 4;
    CGM.FMPLL_CR.B.IDF = 3; //set FMPLL_CLK_ to 120*4/3=160mhz
    CGM.FMPLL_CR.B.ODF = 0;     //set FMPLL_CLK_ to 120mhz
    CGM.FMPLL_CR.B.EN_PLL_SW = 0;

    CGM.PLL_CLK_DIV.R = 0;      //no div for pll
    CGM.SYSTEM_CLK_DIV.R = 1;   //system clk is 60mhz
    CGM.RTC_CLK_DIV.R = 0;      //rtc is 60mhz

    /*CGM.OCDS_SC.B.SELCTL = 1;// clock out div from xoc
       CGM.OCDS_SC.B.SELDIV = 0;// clock out 25mhz
       SIUL.PCR[36].B.PA = 1; // clk_out
       CGM.OC_EN.R = 1;//enable clock out+ */


    // Configure run mode
    ME.RUN[0].R = 0x001F0074;   // External 25mhz OSC, PLL on, SYSClk PLL

    // Switch to PLL
    ME.MCTL.R = 0x40005AF0;     // Mode & Key 
    ME.MCTL.R = 0x4000A50F;     // Mode & Key inverted 
    while (ME.GS.B.S_MTRANS == 1)
    {
    };                          // Wait for mode entry to complete 
    while (ME.GS.B.S_CURRENT_MODE != 4)
    {
    };                          // Verify RUN0 is the current mode 
}

