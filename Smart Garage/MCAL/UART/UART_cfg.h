/*
 * UART_cfg.h
 *
 *  Created on: Sep 21, 2022
 *      Author: mostafa_ebrahim
 */

#ifndef MCAL_UART_UART_CFG_H_
#define MCAL_UART_UART_CFG_H_

#define UART_TX_PORT PORTD_ID
#define UART_TX_PIN PIN1_ID

#define UART_RX_PORT PORTD_ID
#define UART_RX_PIN PIN0_ID

/*Options of STOP_BIT:
 * 1-UART_ONE_STOP_BIT
 * 2-UART_TWO_STOP_BIT
 *
 * */
#define UART_STOP_BIT_SELECT ONE_STOP_BIT

/*options of modes:
 * 1-UART_ASYNC_MODE
 * 2-UART_SYNC_MODE
 * */
#define UART_SET_MODE UAERT_ASYNC_MODE

/*options of Party mode Options:
 * 1-UART_DISABLED_PARITY
 * 2-UART_ODD_PARITY
 * 3-UART_EVEN_PARITY
 * */
#define UART_PARITY_MODE UART_DISABLED_PARITY

/*options of character size:
 * 1-UART_5_BITS
 * 2-UART_6_BITS
 * 3-UART_7_BITS
 * 4-UART_8_BITS
 * 5-UART_9_BITS
 * */
#define UART_CHAR_FRAME_SIZE UART_8_BITS

/*Clock parity options:
*UART_CLK_PARITY_RISING_TX_FALIING_RX 0
*UART_CLK_PARITY_FALIING_TX_RISING_RX 1
**/
#define UART_CLK_PARITY UART_CLK_PARITY_RISING_TX_FALIING_RX

/*options of UART INT:
 * 1-UART_INT_DISABLE
 * 2-UART_INT_ENABLE
 * */
#define UART_TXC_INT_STATE UART_INT_DISABLE
#define UART_RXC_INT_STATE UART_INT_DISABLE
#define UDRT_DRE_INT_STATE UART_INT_DISABLE
#endif /* MCAL_UART_UART_CFG_H_ */
