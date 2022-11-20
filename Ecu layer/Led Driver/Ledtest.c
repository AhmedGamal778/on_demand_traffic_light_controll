/*
 * Ledtest.c
 *
 *  Created on: Nov 17, 2022
 *      Author: Ahmed Gamal
 */
#include "Ledtest.h"
void Ledtest(void)
{
//	Led_ErrorType status =yellow_on ();
//	if (status == LED_OK)
//		GPIO_writePin(2, 0, 1);
//	else
//		 GPIO_writePin(2, 1, 1);
	Led_ErrorType status =green_on ();
	if (status == LED_OK)
		GPIO_writePin(2, 0, 1);
	else
		 GPIO_writePin(2, 1, 1);

}

