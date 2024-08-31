/*
 * 7_SEGMENT_cfg.h
 *
 *  Created on: Aug 17, 2022
 *      Author: hp
 */

#ifndef HAL_SSD_SSD_CFG_H_
#define HAL_SSD_SSD_CFG_H_

/*Common Modes*/
/*Options:
 *         COMMON_ANODE -  COMMON_CATHODE
 */
#define SSD0_MODE COMMON_ANODE
#define SSD1_MODE COMMON_ANODE

/*Connection*/
#define SSD0_DATA_PORT  PORTB_ID
#define SSD0_ENPORT  PORTA_ID
#define SSD0_ENPIN   PIN0_ID

#define SSD1_DATA_PORT  PORTA_ID
#define SSD1_ENPORT  PORTA_ID
#define SSD1_ENPIN   PIN1_ID









#endif /* HAL_SSD_SSD_CFG_H_ */
