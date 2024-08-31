/*
 * BUTTON_prg.c
 *
 *  Created on: Aug 16, 2022
 *      Author: hp
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_int.h"

#include "BTN_pri.h"
#include"BTN_cfg.h"
#include"BTN_int.h"

void BTN_vInt(u8 A_u8BtnId)
{
	switch(A_u8BtnId)
	{
	case BTN0_ID:DIO_vPinDir(BTN0_PORT,BTN0_ID,DIR_INPUT);break;
	case BTN1_ID:DIO_vPinDir(BTN1_PORT,BTN1_ID,DIR_INPUT);break;
	case BTN2_ID:DIO_vPinDir(BTN2_PORT,BTN2_ID,DIR_INPUT);break;
	case BTN3_ID:DIO_vPinDir(BTN3_PORT,BTN3_ID,DIR_INPUT);break;
	case BTN4_ID:DIO_vPinDir(BTN4_PORT,BTN4_ID,DIR_INPUT);break;
	case BTN5_ID:DIO_vPinDir(BTN5_PORT,BTN5_ID,DIR_INPUT);break;
	case BTN6_ID:DIO_vPinDir(BTN6_PORT,BTN6_ID,DIR_INPUT);break;
	case BTN7_ID:DIO_vPinDir(BTN7_PORT,BTN7_ID,DIR_INPUT);break;
	}
#if(BTN_PULLING==INTERNAL_PULLUP)
	switch(A_u8BtnId)
		{
		case BTN0_ID:DIO_vSetPinVal(BTN0_PORT,BTN0_ID,DIR_OUTPUT);break;
		case BTN1_ID:DIO_vSetPinVal(BTN1_PORT,BTN1_ID,DIR_OUTPUT);break;
		case BTN2_ID:DIO_vSetPinVal(BTN2_PORT,BTN2_ID,DIR_OUTPUT);break;
		case BTN3_ID:DIO_vSetPinVal(BTN3_PORT,BTN3_ID,DIR_OUTPUT);break;
		case BTN4_ID:DIO_vSetPinVal(BTN4_PORT,BTN4_ID,DIR_OUTPUT);break;
		case BTN5_ID:DIO_vSetPinVal(BTN5_PORT,BTN5_ID,DIR_OUTPUT);break;
		case BTN6_ID:DIO_vSetPinVal(BTN6_PORT,BTN6_ID,DIR_OUTPUT);break;
		case BTN7_ID:DIO_vSetPinVal(BTN7_PORT,BTN7_ID,DIR_OUTPUT);break;
		}
#endif
}
u8 BTN_u8GetState(u8 A_u8BtnId)
{u8 L_u8BtnState;
u8 L_u8ResState;
	switch(A_u8BtnId)
		{
		case BTN0_ID:L_u8BtnState=DIO_u8GetPinVal(BTN0_PORT,BTN0_ID);break;
		case BTN1_ID:L_u8BtnState=DIO_u8GetPinVal(BTN1_PORT,BTN1_ID);break;
		case BTN2_ID:L_u8BtnState=DIO_u8GetPinVal(BTN2_PORT,BTN2_ID);break;
		case BTN3_ID:L_u8BtnState=DIO_u8GetPinVal(BTN3_PORT,BTN3_ID);break;
		case BTN4_ID:L_u8BtnState=DIO_u8GetPinVal(BTN4_PORT,BTN4_ID);break;
		case BTN5_ID:L_u8BtnState=DIO_u8GetPinVal(BTN5_PORT,BTN5_ID);break;
		case BTN6_ID:L_u8BtnState=DIO_u8GetPinVal(BTN6_PORT,BTN6_ID);break;
		case BTN7_ID:L_u8BtnState=DIO_u8GetPinVal(BTN7_PORT,BTN7_ID);break;
		}
if(L_u8BtnState==0)
	L_u8ResState=BTN_ON;
else
	L_u8ResState=BTN_OFF;
	return L_u8ResState;

}
