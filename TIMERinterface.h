
#ifndef TIMERINTERFACE_H
#define TIMERINTERFACE_H


void Timer1_init();

void Timer1_Stop();

void Timer0_init();

void __vector_11(void) __attribute__((signal));

void __vector_7(void) __attribute__((signal));

void SET_CALL_BACK_OVF( void (*ptr)(void));

void set_call_back_ctc1(void (*ptr)(void));


#endif
