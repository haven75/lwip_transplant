/*
 * bsp.c
 *
 *  Created on: Sep 9, 2016
 *      Author: jason
 */

#include "MPC5604E.h"
#include "debug.h"
#include "gpio.h"
#include "IntcInterrupts.h"



#define SIUL_EIRQ_PA0                  ((uint32_t)0x00000001)
#define SIUL_EIRQ_PA1                  ((uint32_t)0x00000002)
#define SIUL_EIRQ_PA2                  ((uint32_t)0x00000004)
#define SIUL_EIRQ_PA3                  ((uint32_t)0x00000008)
#define SIUL_EIRQ_PA4                  ((uint32_t)0x00000010)
#define SIUL_EIRQ_PA5                  ((uint32_t)0x00000020)
#define SIUL_EIRQ_PA6                  ((uint32_t)0x00000040)
#define SIUL_EIRQ_PA7                  ((uint32_t)0x00000080)
#define SIUL_EIRQ_PA8                  ((uint32_t)0x00000100)
#define SIUL_EIRQ_PA9                  ((uint32_t)0x00000200)
#define SIUL_EIRQ_PA10                 ((uint32_t)0x00000400)
#define SIUL_EIRQ_PA12                 ((uint32_t)0x00000800)
#define SIUL_EIRQ_PA13                 ((uint32_t)0x00001000)
#define SIUL_EIRQ_PA14                 ((uint32_t)0x00002000)
#define SIUL_EIRQ_PA15                 ((uint32_t)0x00040000)
#define SIUL_EIRQ_PB3                  ((uint32_t)0x00004000)
#define SIUL_EIRQ_PC1                  ((uint32_t)0x00008000)
#define SIUL_EIRQ_PC2                  ((uint32_t)0x00010000)
#define SIUL_EIRQ_PC3                  ((uint32_t)0x00020000)
#define SIUL_EIRQ_PC4                  ((uint32_t)0x00080000)
#define SIUL_EIRQ_PC5                  ((uint32_t)0x00100000)
#define SIUL_EIRQ_PC6                  ((uint32_t)0x00200000)
#define SIUL_EIRQ_PC8                  ((uint32_t)0x00400000)
#define SIUL_EIRQ_PC9                  ((uint32_t)0x00800000)
#define SIUL_EIRQ_PC10                 ((uint32_t)0x01000000)
#define SIUL_EIRQ_PC12                 ((uint32_t)0x02000000)
#define SIUL_EIRQ_PC13                 ((uint32_t)0x04000000)
#define SIUL_EIRQ_PC14                 ((uint32_t)0x08000000)
#define SIUL_EIRQ_PD9                  ((uint32_t)0x10000000)
#define SIUL_EIRQ_PD13                 ((uint32_t)0x20000000)
#define SIUL_EIRQ_PD14                 ((uint32_t)0x40000000)
#define SIUL_EIRQ_PE2                  ((uint32_t)0x80000000)



static void
gpio_isr_disable (void)
{
    SIUL.IRER.R = 0;
}

static void
gpio_isr_enable (void)
{
    SIUL.IRER.R = SIUL_EIRQ_PC2;
}

static void
gpio_isr (void)
{
    static uint32_t cnt = 0;
    cnt++;
    if (SIUL.ISR.R & SIUL_EIRQ_PC2)
    {
        SIUL.ISR.R = SIUL_EIRQ_PC2;
    }
    else
    {
        pr_info_const ("Unknow gpio interrupt.\n");
    }
}

#define DEBUG_PIN_LED_INDEX 18
#define DEBUG_PIN_1_INDEX 12
#define DEBUG_PIN_2_INDEX 13
#define BUTTON_PIN_INDEX 36
void
initGpio (void)
{
    // pins for Ethernet
    SIUL.PCR[27].R = 0x707;     /* Set to FEC_MDIO  */
    SIUL.PCR[26].R = 0x604;     /* Set to FEC_MDC   */
    SIUL.PCR[25].R = 0x604;     /* Set to FEC_TX_EN  */
    SIUL.PCR[21].R = 0x604;     /* Set to FEC_TXD[0] */
    SIUL.PCR[22].R = 0x604;     /* Set to FEC_TXD[1] */
    SIUL.PCR[23].R = 0x604;     /* Set to FEC_TXD[2] */
    SIUL.PCR[24].R = 0x604;     /* Set to FEC_TXD[3] */
    SIUL.PCR[28].R = 0x106;     /* Set to FEC_TX_CLK */
    SIUL.PCR[33].R = 0x106;     /* Set to FEC_RX_CLK */
    SIUL.PCR[20].R = 0x106;     /* Set to FEC_RX_DV  */
    SIUL.PCR[29].R = 0x106;     /* Set to FEC_RXD[0] */
    SIUL.PCR[30].R = 0x106;     /* Set to FEC_RXD[1] */
    SIUL.PCR[31].R = 0x106;     /* Set to FEC_RXD[2] */
    SIUL.PCR[32].R = 0x106;     /* Set to FEC_RXD[3] */

    // debug gpios
    SIUL.PCR[DEBUG_PIN_LED_INDEX].R = 0x0207;   // output debug pin
    DEBUG_LEN_OFF;
    SIUL.PCR[DEBUG_PIN_1_INDEX].R = 0x0207; // output debug pin
    SIUL.PCR[DEBUG_PIN_2_INDEX].R = 0x0207; // output debug pin
    SIUL.PCR[BUTTON_PIN_INDEX].R = 0x0107;  // input button pin
}


#define DEBUG_PIN_LED_SEL SIUL.GPDO[DEBUG_PIN_LED_INDEX].B.PDO
#define DEBUG_PIN_1_SEL SIUL.GPDO[DEBUG_PIN_1_INDEX].B.PDO
#define DEBUG_PIN_2_SEL SIUL.GPDO[DEBUG_PIN_2_INDEX].B.PDO
void
debug_pin_ext (int index, int op)   //0 set to 0, 1 set to 1, 2 mean 0 to 1 or 1 to 0
{
    if (index == DEBUG_PIN_LED)
    {
        if (1 == op)
            DEBUG_PIN_LED_SEL = 1;
        else if (0 == op)
            DEBUG_PIN_LED_SEL = 0;
        else
            DEBUG_PIN_LED_SEL = !DEBUG_PIN_LED_SEL;
    }
    else if (index == DEBUG_PIN_OUT1)
    {
        if (1 == op)
            DEBUG_PIN_1_SEL = 1;
        else if (0 == op)
            DEBUG_PIN_1_SEL = 0;
        else
            DEBUG_PIN_1_SEL = !DEBUG_PIN_1_SEL;
    }
    else if (index == DEBUG_PIN_OUT2)
    {
        if (1 == op)
            DEBUG_PIN_2_SEL = 1;
        else if (0 == op)
            DEBUG_PIN_2_SEL = 0;
        else
            DEBUG_PIN_2_SEL = !DEBUG_PIN_2_SEL;

    }
}

#define BUTTON_PIN_STATE SIUL.GPDI[BUTTON_PIN_INDEX].B.PDI
#define BUTTON_PIN_PRESS (0)
int
debug_buttom_press (void)
{
    return BUTTON_PIN_STATE == BUTTON_PIN_PRESS;
}
