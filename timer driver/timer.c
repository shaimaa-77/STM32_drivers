/*
 * TIMER_DRIVER.c
 *
 * Created: 5/18/2020 4:25:38 PM
 *  Author: المتميز
 */ 
#include "congh.h"
#include "TIMER_DRIVER.h"

  TIMER0_configuration      TIMER0 ={0};
       

void TIMER0_INIT()
{
	unsigned char TCCR0_TEMP=0;
	unsigned char TIMSK_TEMP=0;
	unsigned char SFIOR_TEMP=0;
	
	switch(TIMER0.WAVE_GEN)
	{
	    case NORNAL_MODE :
		break;
		case CTC_MODE:
		TCCR0_TEMP |=(1<<WGM01);
		break;
		case PWM_PHASE_CORRECT_MODE :
		TCCR0_TEMP |=((1<<WGM00)|(1<<FOC0));
		break;
		case FAST_PWM_MODE :
		TCCR0_TEMP |=((1<<WGM00)|(1<<WGM01)|(1<<FOC0));
		break;
		default:
		break;
	}
	switch(TIMER0.CLOCK_SELECT)
	{
		case NO_CLOCK_SOURCE :
		break;
		case NO_PRESCALER :
		TCCR0_TEMP |=(1<<CS00);
		break;
		case PRESCALER_8 :
		TCCR0_TEMP |=(1<<CS01);
		break;
		case PRESCALER_64 :
		TCCR0_TEMP |=((1<<CS01)|(1<<CS00));
		break;
		case PRESCALER_256 :
		TCCR0_TEMP |=(1<<CS02);
		break;
		case PRESCALER_1024 :
		TCCR0_TEMP |=((1<<CS00)|(1<<CS02));
		break;
		case EXTERNAL_ON_FALLING_EDGE :
		TCCR0_TEMP |=((1<<CS01)|(1<<CS02));
		break;
		case EXTERNAL_ON_RISING_EDGE :
		TCCR0_TEMP |=((1<<CS00)|(1<<CS01)|(1<<CS02));
		break;
		default:
		break;
	}
	switch(TIMER0.INTERRUPT_ENABLE)
	{
		case INTERRUPT_DISABLE :
		break;
		case OVERFLOW_INTERRUPT_ENABLE :
		TIMSK_TEMP |=(1<<TOIE0);
		break;
		case COMPAREMATCH_INTERRUPT_ENABLE :
		TIMSK_TEMP |=(1<<OCIE0);
		break;
		default:
		break;
	}
	switch(TIMER0.RESET)
	{
		case NON_RESIT :
		break;
		case RESIT :
		SFIOR_TEMP |=(1<<PSR10);
		break;
		default:
		break;
	}
	switch(TIMER0.COMAPARE_MATCH_OUTPUT)
	{
		
		case OC0_DISCONNECTED :
		break;
		case OC0_TOGGLE :
		TCCR0_TEMP |=(1<<COM00);
		break;
		case OC0_CLEAR :
		TCCR0_TEMP |=(1<<COM01);
		break;
		case OC0_SET :
		TCCR0_TEMP |=((1<<COM00)|(1<<COM01));
		break;
		default:
		break;
	}
	switch(TIMER0.COMAPARE_MATCH_OUTPUT_FAST_PWM)
	{
		case OC0_DISCONNECTED_FAST :
		break;
		case CLEAR_OC0_ON_COMPARE_SET_OC0_ON_BUTTOM :
		TCCR0_TEMP |=(1<<COM01);
		break;
		case SET_OC0_ON_COMPARE_CLEAR_OC0_ON_BUTTOM :
		TCCR0_TEMP |=((1<<COM00)|(1<<COM01));
		break;
		default:
		break;
	}
	switch(TIMER0.COMAPARE_MATCH_OUTPUT_PHASECORRECT_PWM)
	{
		case OC0_DISCONNECTED_PHASE :
		break;
		case CLEAR_OC0_ON_COMPARE_UPCOUNTING_SET_OC0_ON_DWONCOUNTING :
		TCCR0_TEMP |=(1<<COM01);
		break;
		case SET_OC0_ON_COMPARE_UPCOUNTING_CLEAR_OC0_ON_DWONCOUNTING :
		TCCR0_TEMP |=((1<<COM00)|(1<<COM01));
		break;
		default:
		break;
	}
	TCCR0=TCCR0_TEMP;
	TIMSK=TIMSK_TEMP;
	SFIOR=SFIOR_TEMP;
	
	
}	
void CREAT_DELAY_BY_TIMER0(unsigned short time0)
{
	TCNT0=time0;
	while((TIFR  & (1<<TOV0))==0);
	TCCR0=0;
	TIFR  |=(1<<TOV0);
}
void CREAT_TIME_COMPARE(unsigned short time0,unsigned short ocr0)
{
	TCNT0=time0;
	OCR0 = ocr0;
	while((TIFR & (1<<OCF0))==0);
	TCCR0=0;
	TIFR |= (1<<OCF0);
	
}	
void CREAT_PHASE_PWM(unsigned short ocr0)
{
	OCR0 = ocr0;
	while((TIFR & (1<<OCF0))==0);
	TCCR0=0;
	TIFR |= (1<<OCF0);
	
}
void CREAT_FAST_PWM(unsigned short ocr0)
{
	OCR0 = ocr0;
	while((TIFR & (1<<OCF0))==0);
	TCCR0=0;
	TIFR |= (1<<OCF0);
	
}	 
