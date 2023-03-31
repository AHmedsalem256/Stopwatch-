

/*



@brief : Code for Timer1 for AVR

*/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include<avr/io.h>

u8 ovcount = 0;

/* Setting ADDDRESS func */

void (* timer1_ctc)(void);



void Timer1_init()
{
	/* TIMER1 */

	TCCR1A |= 1 << 5 | 1 << 7 ;
	TCCR1B |= 1 << 3 | 1 << 0;

	SREG |= 1 << 7;

	TIMSK |= 1 << 4;


	TCNT1 = 0 ;
	OCR1A = 50953 ;


}



void Timer1_Stop()
{
	TCCR1A =0 ;
	TCCR1B = 0;
	TIMSK = 0;
	TCNT1 = 0 ;
	OCR1A = 0 ;
}


/* Setting up Call back functions  */

void (*call_back_Ovf)(void) = 0;


void SET_CALL_BACK_OVF( void (*ptr)(void))
{
	call_back_Ovf = ptr;

}


void set_call_back_ctc1(void (*ptr)(void))
{
	timer1_ctc = ptr;
}




void Timer0_init()
{

	TCCR0 |= 1 << 2;
	TIMSK |= 1 << 0;

	TCNT0 = 0 ;



}

void __vector_7(void) __attribute__((signal));

void __vector_7(void)
{
	timer1_ctc();
}


void __vector_11(void) __attribute__((signal));

void __vector_11(void)
{

	ovcount ++;

		if(ovcount == 122)
		{
			DIO_TogglePinValue(0,0);
			ovcount = 0;

		}
}







