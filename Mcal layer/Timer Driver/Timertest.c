/*
 * Timertest.c
 *
 *  Created on: Nov 17, 2022
 *      Author: Ahmed Gamal
 */
#include "Timertest.h"
#include "../../Ecu layer/Led Driver/Led.h"

void TimerTest ()
{
	Timer_ErrorType status =Timer0_init(0);
	if (status == TIMER_OK)
		 GPIO_writePin(2, 0, 1);
	else
		 GPIO_writePin(2, 1, 1);


}


