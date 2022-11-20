/*
 * external interrupt.h
 *
 *  Created on: Nov 10, 2022
 *      Author: Ahmed Gamal
 */

#ifndef MCAL_LAYER_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_
#define MCAL_LAYER_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_
typedef enum{
	INT_OK,
	INT_ERROR
} INT_ErrorType;

INT_ErrorType enable_int0 (void (*a_ptr)(void));
//INT_ErrorType int0_setCallBack(void (*a_ptr)(void));




#endif /* MCAL_LAYER_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_ */
