#include"external_interrupt.h"
#include <avr/io.h>
#include <avr/interrupt.h>

extern char curr_mode;
extern char color;
extern char flag;
extern char ticks;


static volatile void (*g_callBackPtr)(void) = 0;

ISR(INT0_vect)
{
	curr_mode=1;
	//green
	if (color == 10)
	{
		(*g_callBackPtr)();
	}
	// red
	if (color == 00)
	{
		TCNT0 = 0;
		ticks=0;
	}
	flag=1;
}

INT_ErrorType enable_int0 (void (*a_ptr)(void))
{

	//enable rising edge
	MCUCR|= (1<<ISC00) | (1<<ISC01);
	//enable int0
	GICR |= (1<<INTF0);
	if (a_ptr == 0)
			return INT_ERROR;
	g_callBackPtr = a_ptr;
	return INT_OK;
}
//INT_ErrorType int0_setCallBack()
//{
//
//}

