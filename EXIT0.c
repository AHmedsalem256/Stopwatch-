
/*
 * Author : Ahmed Salem
 *
 * Date : 11/3/2023
 *
 * File :  driver code for external interupt
 *
 *  */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include<avr/io.h>

#define NULL 0



/* Selecting ADDRESS function  for call back function  */


void (*EXIT_CALLBACK_0)(void) = NULL;
void (*EXIT_CALLBACK_1)(void) = NULL;
void (*EXIT_CALLBACK_2)(void) = NULL;


void Exit0_init()
{
	/* GIE */

	SREG |= 1 << 7;

	/* MCUCR */

	MCUCR |= 1 << 1;

	/* GICR register */

	GICR |= 1 << 6;


}

void Exit1_init()
{
	/* GIE */

	SREG |= 1 << 7;

	/* MCUCR */

	MCUCR |= 1 << 3;

	/* GICR register */

	GICR |= 1 << 7;


}

void Exit2_init()
{
	/* GIE */

	SREG |= 1 << 7;

	/* MCUCSR >>  */

	CLR_BIT(MCUCSR,6);

	/* GICR register */

	GICR |= 1 << 5;


}



void Call_back_EXIT0( void (*ptr)(void))
{
	if(ptr != 0)
	{
		EXIT_CALLBACK_0  = ptr;
	}

}

void Call_back_EXIT1( void (*ptr)(void))
{
	if(ptr != 0)
	{
		EXIT_CALLBACK_1  = ptr;
	}

}
void Call_back_EXIT2( void (*ptr)(void))
{
	if(ptr != 0)
	{
		EXIT_CALLBACK_2  = ptr;
	}

}

void __vector_1(void) __attribute__((signal));



void __vector_1 (void)
{

	EXIT_CALLBACK_0();

}



void __vector_2(void) __attribute__((signal));



void __vector_2 (void)
{
	EXIT_CALLBACK_1();
}

void __vector_3(void) __attribute__((signal));



void __vector_3 (void)
{
	EXIT_CALLBACK_2();
}








