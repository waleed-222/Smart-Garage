/*
 * LED_prg.c
 *
 *  Created on: Aug 16, 2022
 *      Author: hp
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_int.h"
#include "LED_cfg.h"
#include"LED_int.h"


void LED_vInt(u8 A_u8LedId)
{
	switch(A_u8LedId)
		{
		 case LED0_ID:DIO_vPinDir(LED0_PORT,LED0_ID,DIR_OUTPUT);break;
		 case LED1_ID:DIO_vPinDir(LED1_PORT,LED1_ID,DIR_OUTPUT);break;
		 case LED2_ID:DIO_vPinDir(LED2_PORT,LED2_ID,DIR_OUTPUT);break;
		 case LED3_ID:DIO_vPinDir(LED3_PORT,LED3_ID,DIR_OUTPUT);break;
		 case LED4_ID:DIO_vPinDir(LED4_PORT,LED4_ID,DIR_OUTPUT);break;
		 case LED5_ID:DIO_vPinDir(LED5_PORT,LED5_ID,DIR_OUTPUT);break;
		 case LED6_ID:DIO_vPinDir(LED6_PORT,LED6_ID,DIR_OUTPUT);break;
		 case LED7_ID:DIO_vPinDir(LED7_PORT,LED7_ID,DIR_OUTPUT);break;

		}

}




void LED_vTurnOn(u8 A_u8LedId)
{
	switch(A_u8LedId)
	{
	case LED0_ID:DIO_vSetPinVal(LED0_PORT,LED0_ID,VAL_HIGH);break;
	case LED1_ID:DIO_vSetPinVal(LED1_PORT,LED1_ID,VAL_HIGH);break;
	case LED2_ID:DIO_vSetPinVal(LED2_PORT,LED2_ID,VAL_HIGH);break;
	case LED3_ID:DIO_vSetPinVal(LED3_PORT,LED3_ID,VAL_HIGH);break;
	case LED4_ID:DIO_vSetPinVal(LED4_PORT,LED4_ID,VAL_HIGH);break;
	case LED5_ID:DIO_vSetPinVal(LED5_PORT,LED5_ID,VAL_HIGH);break;
	case LED6_ID:DIO_vSetPinVal(LED6_PORT,LED6_ID,VAL_HIGH);break;
	case LED7_ID:DIO_vSetPinVal(LED7_PORT,LED7_ID,VAL_HIGH);break;

	}

}

void LED_vTurnOff(u8 A_u8LedId)
{
	switch(A_u8LedId)
		{
		case LED0_ID:DIO_vSetPinVal(LED0_PORT,LED0_ID,VAL_LOW);break;
		case LED1_ID:DIO_vSetPinVal(LED1_PORT,LED1_ID,VAL_LOW);break;
		case LED2_ID:DIO_vSetPinVal(LED2_PORT,LED2_ID,VAL_LOW);break;
		case LED3_ID:DIO_vSetPinVal(LED3_PORT,LED3_ID,VAL_LOW);break;
		case LED4_ID:DIO_vSetPinVal(LED4_PORT,LED4_ID,VAL_LOW);break;
		case LED5_ID:DIO_vSetPinVal(LED5_PORT,LED5_ID,VAL_LOW);break;
		case LED6_ID:DIO_vSetPinVal(LED6_PORT,LED6_ID,VAL_LOW);break;
		case LED7_ID:DIO_vSetPinVal(LED7_PORT,LED7_ID,VAL_LOW);break;

		}

}

void LED_vPortDir(u8 A_u8Val)
{
	DIO_vPortDir(LEDS_PORT,A_u8Val);
}
void LED_vSetPortVal(u8 A_u8Val)
{
	DIO_vSetPortVal(LEDS_PORT,A_u8Val);

}
void LED_vToggelPinVal(u8 A_u8PortId,u8 A_u8LedId)
{
	DIO_vToggelPinVal( A_u8PortId, A_u8LedId);
}


