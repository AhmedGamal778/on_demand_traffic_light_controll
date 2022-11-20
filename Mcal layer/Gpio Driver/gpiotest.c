/*
 * gpiotest.c
 *
 *  Created on: Nov 17, 2022
 *      Author: Ahmed Gamal
 */
#include"gpiotest.h"
void gpiotest (void)
{
//	GPIO_ErrorType status = GPIO_setupPinDirection(20, 0, 0);
//	if (status == GPIO_OK)
//		GPIO_writePin(2, 0, 1);
//	else
//		 GPIO_writePin(2, 1, 1);

	GPIO_ErrorType status = GPIO_writePin(2, 0, 0);
	if (status == GPIO_OK)
		GPIO_writePin(2, 0, 1);
	else
		 GPIO_writePin(2, 1, 1);

}



