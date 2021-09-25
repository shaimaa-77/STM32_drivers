/**********************************************************************************************************/
/* Author  : Shaimaa Mahmoud  */
/* Data    : 15/8/2020        */
/* Version : 01               */
/*********************************************************************************************************/

#ifndef RCC_CONGIH_H
#define RCC_CONGIH_H


/* options of clock types :
   * HSE_CRYSTAL
   *HSE_RC
   *HSI
   *PLL
   */
#define  RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL

/* Options:    
               * RCC_PLL_IN_HSI_DIV_2
               * RCC_PLL_IN_HSE_DIV_2
			   * RCC_PLL_IN_HSE      */
/* Note: Select value only if you have PLL as input clock source */

#if RCC_CLOCK_TYPE == RCC_PLL

	#define RCC_PLL_INPUT	 RCC_PLL_IN_HSE

#endif

/* PLL Options:  */

/* Note: Select value only if you have PLL as input clock source */

#if RCC_CLOCK_TYPE == RCC_PLL

	#define RCC_PLL_MUL_VAL   PLL_MUL_BY_9
	
#endif

/* Options:    MRCC_ENABLE_CS
               MRCC_DISABLE_CS      */

#define RCC_CS_SYS   RCC_DISABLE_CS



#endif
#endif