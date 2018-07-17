/*
 * bsp.h
 *
 *  Created on: Sep 9, 2016
 *      Author: jason
 */

#ifndef BSP_H_
#define BSP_H_
#define BUS_CLK 75000000UL //test spy
#define FREE_TIMER PIT_RTI.CH[0].CVAL.R
#define FREE_TIMER_MAX (BUS_CLK / 1000)

//delay_ns can not be usd to delay more than half of system tick(5ms)
#define delay_ns(last_timer, ns) do{\
		while((last_timer - FREE_TIMER)%FREE_TIMER_MAX < (ns*(BUS_CLK/1000000))/(1000uL)){;} \
	}while(0);
void Delay (int rep);

extern int time_tick;
void initModes (void);
void DisableWatchdog (void);
void BSP_TmrTickISR (void);
void BSP_SysTickInit (void);


#include "gpio.h"


#define OS_ENTER_CRITICAL()
#define OS_EXIT_CRITICAL()
typedef int CPU_SR;

#endif /* BSP_H_ */
