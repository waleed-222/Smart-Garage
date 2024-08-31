/*
 * 7_SEGMENT_int.h
 *
 *  Created on: Aug 17, 2022
 *      Author: hp
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

#define SSD0_ID 0
#define SSD1_ID 1




void SSD_vINT(u8 A_u8SsdId);
void SSD_vTurnOn(u8 A_u8SsdId);
void SSD_vTurnOff(u8 A_u8SsdId);
void SSD_vDisplayNum(u8 A_u8SsdId,u8 A_u8Num);
void SSD_vDisplaySigmentBorder(u8 A_u8SsdId,u8 A_u8Num);
void SSD1_vDisplayNum(u8 A_u8Num);



#endif /* HAL_SSD_SSD_INT_H_ */
