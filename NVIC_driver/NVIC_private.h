/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 24/8/2020                */
/* version  : v01                      */
/****************************************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/***** the basic address is 0xE000E100 ***/
#define NVIC_ISER0                                *((u32 *) 0xE000E100)
#define NVIC_ISER1                                *((u32 *) 0xE000E104)

#define NVIC_ICER0                                *((u32 *) 0xE000E180)
#define NVIC_ICER1                                *((u32 *) 0xE000E184)

#define NVIC_ISPR0                                *((u32 *) 0xE000E200)
#define NVIC_ISPR1                                *((u32 *) 0xE000E204)

#define NVIC_ICPR0                                *((u32 *) 0xE000E280)
#define NVIC_ICPR1                                *((u32 *) 0xE000E284)

#define NVIC_IABR0                                *((volatile u32 *) 0xE000E300)
#define NVIC_IABR1                                *((volatile u32 *) 0xE000E304)

#define NVIC_IPR                                   ((volatile u8  *) 0xE000E400)  

#define NVIC_GROUP4_SUB0                           0xFA050300
#define NVIC_GROUP3_SUB1                           0xFA050400
#define NVIC_GROUP2_SUB2                           0xFA050500
#define NVIC_GROUP1_SUB3                           0xFA050600
#define NVIC_GROUP0_SUB4                           0xFA050700

#define SCB_AIRCR                                 *((volatile u32 *) 0xE000ED0C)



#endif