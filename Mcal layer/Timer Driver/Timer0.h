

#ifndef TIMER0_H_
#define TIMER0_H_
#include "../../std_types.h"
#include "../../common_macros.h"


typedef enum{
	TIMER_OK,
	TIMER_ERROR
} Timer_ErrorType;
Timer_ErrorType Timer0_init(void (*a_ptr)(void));

//void Timer0_setCallBack(void (*a_ptr)(void));

#endif /* TIMER0_H_ */
