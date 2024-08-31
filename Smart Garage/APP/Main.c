#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/EXI/EXI_int.h"
#include "../MCAL/UART/UART_int.h"

#include "../HAL/LED/LED_int.h"
#include "../HAL/LDR/LDR_int.h"
#include "../HAL/SSD/SSD_int.h"
#include "../HAL/SERVO/SERVO_int.h"
#include "../HAL/BTN/BTN_int.h"
#include "../HAL/LCD/LCD_int.h"
#include <util/delay.h>




s8 G_s8Counts0 =0;
s8 G_s8Counts1 =0;


int main(void)
{


	UART_vInit();
	SERVO_vInit();
	SSD_vINT(SSD1_ID);
	SSD_vINT(SSD0_ID);
	LDR_vInt();




	LED_vInt(LED2_ID);
	LED_vInt(LED3_ID);
	LED_vInt(LED4_ID);
	LED_vInt(LED6_ID);
	SSD_vDisplayNum(SSD0_ID,G_s8Counts0);
	SSD1_vDisplayNum(G_s8Counts1);


	while(1)
	{
		/*
		if(G_s8Counts0!=9&&G_s8Counts1!=9)
		{
			Green LED indicate there is space in garage
			LED_vTurnOn(LED1_ID);
		}
		else
		{
			Red LED indicate full garage
			LED_vTurnOn(LED2_ID);
		}
		 */
		//if(50>LDR_u16GetLDR_Res(LDR_PIN0))
		//if(BTN_u8GetState(BTN6_ID)==1)
		//UART_vSend_String((u8*)"hello");
		//LCD_vDispNum(LDR_u16GetLDR_Res(LDR_PIN6));

		if(200<LDR_u16GetLDR_Res(LDR_PIN6))/*kimt LDR*/
		//if(1)
		{
			u8 L_u8Reply0;
			if(G_s8Counts0!=9||G_s8Counts1!=9)
			{
				UART_vSend_String((u8*)"I");


				L_u8Reply0=UART_u8GetData();



				if(L_u8Reply0=='y'||L_u8Reply0=='Y')
				{
					/*LED indicate car enter*/
					LED_vTurnOn(LED2_ID);//green1
					LED_vTurnOn(LED6_ID);//red2
					/*open gate*/
					SERVO0_vAngle(LEFT);
					_delay_ms(4000);
					/*close gate*/
					SERVO0_vAngle(RIGHT);
					LED_vTurnOff(LED2_ID);//green1
					LED_vTurnOff(LED6_ID);//red2
					G_s8Counts0++;
					//_delay_ms(500);
					if(G_s8Counts0==10)
					{
						G_s8Counts0=0;
						G_s8Counts1 ++;
					}
				}
			}

		}


		else if(200<LDR_u16GetLDR_Res(LDR_PIN7))/*Kimt LDR*/
		{
			u8 L_u8Reply1;
			if(G_s8Counts0>0||G_s8Counts1>0)
			{
				UART_vSend_String((u8*)"O");

				L_u8Reply1=UART_u8GetData();

				if(L_u8Reply1=='y'||L_u8Reply1=='Y')
				{
					/*LED indicate car exist*/
					LED_vTurnOn(LED3_ID);//green2
					LED_vTurnOn(LED4_ID);//red1
					/*open gate*/
					SERVO0_vAngle(LEFT);
					_delay_ms(2000);
					LED_vTurnOff(LED3_ID);//green2
					LED_vTurnOff(LED4_ID);//red1
					/*close gate*/
					SERVO0_vAngle(RIGHT);
					G_s8Counts0--;
					if(G_s8Counts0<0)
					{
						G_s8Counts0=9;
						G_s8Counts1--;
					}
				}
			}

		}
		LCD_vDispNum(LDR_u16GetLDR_Res(LDR_PIN7));



		SSD_vDisplayNum(SSD0_ID,G_s8Counts0);
		SSD1_vDisplayNum(G_s8Counts1);
	}
	return 0;
}

