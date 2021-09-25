/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 24/8/2020                */
/* version  : v01                      */
/****************************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt           (u8 );
void MNVIC_voidDisableInterrupt          (u8 );
void MNVIC_voidEnableInterruptPending    (u8 );
void MNVIC_voidDisableInterruptPending   (u8 );
 u8  MNVIC_u8GetActiveFlag               (u8 );
void MNVIC_voidInit                      (void);
void NVIC_voidSetPriority                (u8 copy_u8preipheralIdx , u8 copy_u8Piriorty);
 


#endif