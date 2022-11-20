/*
 * Led.c
 *
 *  Created on: Nov 10, 2022
 *      Author: Ahmed Gamal
 */
#include "Led.h"
#include <avr/io.h>
#include <util/delay.h>
Led_ErrorType led_on_first(void)
{
	Led_ErrorType status =green_on ();
	return status;

}

Led_ErrorType led_init(void)
{
	DDRA|= (1) | (1<<1) | (1<<2);
	DDRB |= ( (1) | (1<<1) | (1<<2));
	return LED_OK;

}

Led_ErrorType change_color ()
{
  if (color==green)
	{
		  color = yellow;
		  color_previous=green;
		 // yellow_on ();

	}
	else if (color==yellow)
	{
		   if (color_previous==red)
		   {
			   color = green;
			   color_previous=yellow;
			  // green_on();
		   } else if (color_previous==green)
		   {
			   color = red;
			   color_previous=yellow;
			   //red_on();
		   }

	}else if (color==red)
	{
		color = yellow;
		color_previous=red;
		 //yellow_on ();

	}
  return LED_OK;

}
Led_ErrorType yellow_on (void)
{
	Led_ErrorType status = LED_OK;

	//car colors
	if (GPIO_writePin(PORTA_ID, PIN0_ID, Low)==GPIO_ERROR)
		status=LED_ERROR;
	if(GPIO_writePin(PORTA_ID, PIN2_ID, Low)==GPIO_ERROR)
		status=LED_ERROR;
	//passenger
	if(GPIO_writePin(PORTB_ID, PIN0_ID, Low)==GPIO_ERROR)
		status=LED_ERROR;
	if (GPIO_writePin(PORTB_ID, PIN2_ID, Low)==GPIO_ERROR)
		status=LED_ERROR;
	if(GPIO_writePin(PORTA_ID, PIN1_ID, High)==GPIO_ERROR)
		status=LED_ERROR;
	if (curr_mode==pedestrianmode)
	{
		//car colors
	 GPIO_writePin(PORTB_ID, PIN1_ID, High);
	}
	return status;


}
Led_ErrorType red_on (void)
{

	Led_ErrorType status = LED_OK;
	//car colors
	if (GPIO_writePin(PORTA_ID, PIN1_ID, Low)==GPIO_ERROR)
		status=LED_ERROR;
	if (GPIO_writePin(PORTA_ID, PIN2_ID, High)==GPIO_ERROR)
		status=LED_ERROR;

	if (curr_mode==pedestrianmode)
	{
		//car colors
	 GPIO_writePin(PORTB_ID, PIN1_ID, Low);

	 GPIO_writePin(PORTB_ID, PIN0_ID, High);
	}
	curr_mode=normalmode;
	return status;

}
Led_ErrorType green_on (void)
{
	Led_ErrorType status = LED_OK;
	if (GPIO_writePin(10, PIN1_ID, Low) == GPIO_ERROR)
		status=LED_ERROR;
	if (GPIO_writePin(PORTA_ID, PIN0_ID, High)==GPIO_ERROR)
		status=LED_ERROR;
	if (curr_mode==pedestrianmode)
		{
			//car colors
		 GPIO_writePin(PORTB_ID, PIN1_ID, Low);

		 GPIO_writePin(PORTB_ID, PIN2_ID, High);

		}
	return status;

}

