/*
 * TIMER_DRIVER.h
 *
 * Created: 5/18/2020 4:25:59 PM
 *  Author: المتميز
 */ 


#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_

typedef enum 
             {
				NORNAL_MODE,
				PWM_PHASE_CORRECT_MODE,
				CTC_MODE,
				FAST_PWM_MODE 
				 }TIMER0_WAVE_GEN;
typedef enum    
             {
				 NO_CLOCK_SOURCE,
				 NO_PRESCALER,
				 PRESCALER_8,
				 PRESCALER_64,
				 PRESCALER_256,
				 PRESCALER_1024,
				 EXTERNAL_ON_FALLING_EDGE,
			     EXTERNAL_ON_RISING_EDGE
				 }TIMER0_CLOCK_SELECT;
typedef enum 
            {
				INTERRUPT_DISABLE,
				OVERFLOW_INTERRUPT_ENABLE,
				COMPAREMATCH_INTERRUPT_ENABLE
				}TIMER0_INTERRUPT_ENABLE;
typedef  enum  
             {
				 NON_RESIT,
				 RESIT
				 }RESIT_PRESCALER;
typedef enum 
           {
			   OC0_DISCONNECTED,
			   OC0_TOGGLE,
			    OC0_CLEAR,
			   OC0_SET
			   }TIMER0_COMAPARE_MATCH_OUTPUT;
 typedef enum 
           {
			   OC0_DISCONNECTED_FAST,
			   CLEAR_OC0_ON_COMPARE_SET_OC0_ON_BUTTOM, 
			   SET_OC0_ON_COMPARE_CLEAR_OC0_ON_BUTTOM 
			   }TIMER0_COMAPARE_MATCH_OUTPUT_FAST_PWM;
 typedef enum
             {
				  OC0_DISCONNECTED_PHASE,
				  CLEAR_OC0_ON_COMPARE_UPCOUNTING_SET_OC0_ON_DWONCOUNTING,
				  SET_OC0_ON_COMPARE_UPCOUNTING_CLEAR_OC0_ON_DWONCOUNTING 
				 }TIMER0_COMAPARE_MATCH_OUTPUT_PHASECORRECT_PWM;
typedef struct 
               {
				   TIMER0_WAVE_GEN                                                                            WAVE_GEN;
				   TIMER0_CLOCK_SELECT                                                                        CLOCK_SELECT;
				   TIMER0_INTERRUPT_ENABLE                                                                    INTERRUPT_ENABLE;
				   RESIT_PRESCALER                                                                            RESET;
				   TIMER0_COMAPARE_MATCH_OUTPUT                                                               COMAPARE_MATCH_OUTPUT;
				   TIMER0_COMAPARE_MATCH_OUTPUT_FAST_PWM                                                      COMAPARE_MATCH_OUTPUT_FAST_PWM;
				   TIMER0_COMAPARE_MATCH_OUTPUT_PHASECORRECT_PWM                                              COMAPARE_MATCH_OUTPUT_PHASECORRECT_PWM;
				   }TIMER0_configuration;			
void TIMER0_INIT();
void CREAT_DELAY_BY_TIMER0(unsigned short );
void CREAT_TIME_COMPARE(unsigned short ,unsigned short );
void CREAT_PHASE_PWM(unsigned short );
void CREAT_FAST_PWM(unsigned short );
			   	 			   			   				 
#endif /* TIMER_DRIVER_H_ */