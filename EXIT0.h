

#ifndef EXIT0_H_
#define EXIT0_H_

void Exit0_init();
void Exit1_init();
void Exit2_init();

void Call_back_EXIT0( void (*ptr)(void));

void Call_back_EXIT1( void (*ptr)(void));

void Call_back_EXIT2( void (*ptr)(void));

void __vector_1(void) __attribute__((signal));;
void __vector_2(void) __attribute__((signal));;
void __vector_3(void) __attribute__((signal));;


#endif
