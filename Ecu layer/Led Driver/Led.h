/*
 * Led.h
 *
 *  Created on: Nov 10, 2022
 *      Author: Ahmed Gamal
 */

#ifndef ECU_LAYER_LED_DRIVER_LED_H_
#define ECU_LAYER_LED_DRIVER_LED_H_
#include "../../common_macros.h"
#include "../../Mcal layer/Gpio Driver/gpio.h"
#ifndef High
#define High 1
#endif

#ifndef Low
#define Low 0
#endif

#define red 00
#define yellow 01
#define green 10

typedef enum  { normalmode , pedestrianmode} mode;
typedef enum{
	LED_OK,
	LED_ERROR
}Led_ErrorType;

volatile char color;
volatile char curr_mode;
static volatile char color_previous;

Led_ErrorType led_init(void);
Led_ErrorType led_on_first(void);
Led_ErrorType change_color (void);
Led_ErrorType green_on (void);
Led_ErrorType yellow_on (void);
Led_ErrorType red_on (void);


#endif /* ECU_LAYER_LED_DRIVER_LED_H_ */
