#include"application.h"
#include "../Mcal layer/Timer Driver/Timer0.h"
#include "../Mcal layer/External interrupt/External_interrupt.h"
extern char flag;

void app_start(void)
{
	led_init();
	enable_int0(change_color);
	Timer0_init(change_color);
   // Timer0_setCallBack(change_color);
   //  int0_setCallBack(change_color);
	SREG |=(1<<7);
	color =green;
	led_on_first();
	while(1)
		{
			if (flag==1)
			{
				if (color == red)
					red_on ();
				else if (color == yellow)
					yellow_on();
				else if (color == green)
					green_on ();
				flag=0;
			}

		};

		//color first
}
