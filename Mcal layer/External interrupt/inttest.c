/*
 * inttest.c
 *
 *  Created on: Nov 17, 2022
 *      Author: Ahmed Gamal
 */
#include "../../Ecu layer/Led Driver/Led.h"
#include"inttest.h"
void inttest (void)
{
	INT_ErrorType status = enable_int0(0);
	if (status == INT_OK)
		 GPIO_writePin(2, 0, 1);
	else
		 GPIO_writePin(2, 1, 1);
}

