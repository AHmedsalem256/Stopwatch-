/*
 * main.c
 *
 *  Created on: Mar 8, 2023
 *      Author: Ahmed Salem Mohamed 
 */

#include"DIO_interface.h"
#include"EXIT0.h"
#include"TIMERinterface.h"
#include"LCDINTERFACE.h"
#include<avr/io.h>
#include<avr/delay.h>

void GIE_ENABLE();
void IS_R();
void EX_IT0();
void EX_IT1();
void EX_IT2();

extern u8 ovcount;
u8 counter = 0 ;


void main()
{
	GIE_ENABLE();

	LCD_VidIntialize();


	/* Timer1 test */

	DIO_VidSetPinDirection(0,0,1);

	/* Setting PD2 AS INT0 input  */

	DIO_VidSetPinDirection(3,2,1);
	DIO_VidSetPinValue(3,2,1);

	/* Setting PD3 AS INT1 input  */

	DIO_VidSetPinDirection(3,3,1);
	DIO_VidSetPinValue(3,3,1);

	/* Setting PB2 AS INT2 input with pull up resistor  */

	DIO_VidSetPinDirection(1,2,1);
	DIO_VidSetPinValue(1,2,1);

	Call_back_EXIT0(EX_IT0);
	Call_back_EXIT1(EX_IT1);
	Call_back_EXIT2(EX_IT2);

	Exit0_init();
	Exit1_init();
	Exit2_init();

	set_call_back_ctc1(IS_R);

	Timer1_init();

	while(1)
	{
		LCD_VidGOTOPOS(0,0);
		LCD_VidSendNum(counter);
		_delay_ms(100);
	}

}

void GIE_ENABLE()
{
	SREG |= 1 << 7;
}

void IS_R()
{
	ovcount ++;

		if(ovcount == 122)
		{
			counter ++;

			DIO_TogglePinValue(0,0);
			ovcount = 0;

		}
}

void EX_IT0()
{
	Timer1_Stop();
}

void EX_IT1()
{
	Timer1_init();
}
void EX_IT2()
{
	counter= 0;
}

