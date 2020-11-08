/**********************************************************************************************************/
/* Author  : Shaimaa Mahmoud  */
/* Data    : 15/8/2020        */
/* Version : 01               */
/*********************************************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H_H

#define RCC_AHP       0
#define RCC_APB1      1
#define RCC_APB2      2

void RCC_voidEnableClock(u8 ,u8 );
void RCC_voidDisenableClock(u8 ,u8 );
void RCC_voidInitSysClock(void);

#endif
