/*
 * LDR_prg.c
 *
 *  Created on: Sep 12, 2022
 *      Author: mostafa_ebrahim
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/ADC/ADC_int.h"
#include"LDR_pri.h"
#include "LDR_cfg.h"
#include "LDR_int.h"

void LDR_vInt()
{
	ADC_vInt();
}
u16 LDR_u16GetLDR_Res(u8 A_u8PinNum)
{
	u16 L_u16Vout=ADC_u16GetDigValSync(A_u8PinNum);
	u16 L_u16LDR_Res= LDR_RES(L_u16Vout);
	return L_u16LDR_Res;
}
