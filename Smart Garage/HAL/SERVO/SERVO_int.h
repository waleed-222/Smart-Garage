/*
 * SERVO_int.h
 *
 *  Created on: Nov 26, 2022
 *      Author: hp
 */

#ifndef HAL_SERVO_SERVO_INT_H_
#define HAL_SERVO_SERVO_INT_H_

#define RIGHT 180
#define LEFT 0
#define CENTER 90

void SERVO_vInit(void);
void SERVO_vRotate180_Back(void);
void SERVO0_vAngle(u8 A_u8Angle);
void SERVO1_vAngle(u8 A_u8Angle);

#endif /* HAL_SERVO_SERVO_INT_H_ */
