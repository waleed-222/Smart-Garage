/*
 * LDR_int.h
 *
 *  Created on: Sep 12, 2022
 *      Author: mostafa_ebrahim
 */

#ifndef HAL_LDR_LDR_INT_H_
#define HAL_LDR_LDR_INT_H_

/*Pin options*/
typedef enum
{
	LDR_PIN0,
	LDR_PIN1,
	LDR_PIN2,
	LDR_PIN3,
	LDR_PIN4,
	LDR_PIN5,
	LDR_PIN6,
	LDR_PIN7,
}LDR_Pins;

void LDR_vInt();
u16 LDR_u16GetLDR_Res(u8 A_u8PinNum);

#endif /* HAL_LDR_LDR_INT_H_ */
