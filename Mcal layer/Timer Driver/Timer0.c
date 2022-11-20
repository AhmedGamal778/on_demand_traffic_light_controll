
#include "Timer0.h"

#include <avr/io.h>
#include <avr/interrupt.h>
static volatile void (*g_callBackPtr)(void) = NULL_PTR;
 volatile char ticks ;
volatile char flag=0;
extern char color;
extern char curr_mode;


ISR(TIMER0_COMP_vect)
{
	ticks++;
	if (ticks%19==0)
	{

		if (g_callBackPtr != NULL_PTR)
		{
			flag=1;
			(*g_callBackPtr)();
		}
	}
	if (ticks%2==0)
		if(color==01)
		{
			TOGGLE_BIT(PORTA,1);
			if (curr_mode == 1 )
				TOGGLE_BIT(PORTB,1);
		}
}

//void Timer0_setCallBack(void (*a_ptr)(void)) {
//	g_callBackPtr = a_ptr;
//}


Timer_ErrorType Timer0_init(void (*a_ptr)(void)) {
	if (a_ptr == 0)
			return TIMER_ERROR;
		g_callBackPtr = a_ptr;

		TCNT0 = 0;    // Set Timer initial value
		OCR0 = 255; // Set Compare Value
		/* Configure timer0 control register
		 * 1. Non PWM mode FOC0=1
		 * 2. CTC Mode WGM01=1 & WGM00=0
		 * 3. No need for OC0 in this example so COM00=0 & COM01=0
		 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
		 */
		TCCR0 = (1 << FOC0) | (1 << WGM01) | (1<<CS02) | (1<<CS00);
		TIMSK |= (1 << OCIE0); // Enable Timer0 Compare Interrupt
		return TIMER_OK;
}




