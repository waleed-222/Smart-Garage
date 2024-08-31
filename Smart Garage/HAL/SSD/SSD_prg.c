/*
 * 7_SEGMENT_prg.c
 *
 *  Created on: Aug 17, 2022
 *      Author: hp
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SSD_pri.h"
#include "SSD_cfg.h"
#include "SSD_int.h"



void SSD_vINT(u8 A_u8SsdId)
{
	switch(A_u8SsdId)
	{
	  case SSD0_ID:
		  {        DIO_vPortDir(SSD0_DATA_PORT,PORT_HIGH);
	              // DIO_vPinDir(SSD0_ENPORT,SSD0_ENPIN,DIR_OUTPUT);
	              // SSD_vTurnOff(SSD0_ENPIN);
		  }
	               break;

	  case SSD1_ID:
		  {
                  // DIO_vPinDir(SSD1_ENPORT,SSD1_ENPIN,DIR_OUTPUT);
                   DIO_vPinDir(SSD1_DATA_PORT,PIN0_ID,DIR_OUTPUT);
                   DIO_vPinDir(SSD1_DATA_PORT,PIN1_ID,DIR_OUTPUT);
                   DIO_vPinDir(SSD1_DATA_PORT,PIN2_ID,DIR_OUTPUT);
                   DIO_vPinDir(SSD1_DATA_PORT,PIN3_ID,DIR_OUTPUT);
                   DIO_vPinDir(SSD1_DATA_PORT,PIN4_ID,DIR_OUTPUT);
                   DIO_vPinDir(SSD1_DATA_PORT,PIN5_ID,DIR_OUTPUT);
                  // DIO_vPinDir(SSD0_DATA_PORT,PIN7_ID,DIR_OUTPUT);
                  // DIO_vPinDir(SSD1_DATA_PORT,PIN6_ID,DIR_OUTPUT);
                   //SSD_vTurnOff(SSD1_ENPIN);

		  }
                   break;
	}
}
void SSD_vTurnOn(u8 A_u8SsdId)
{
	switch(A_u8SsdId)

{
  case SSD0_ID:
	  {

#if SSD0_MODE==COMMON_CATHODE
		  DIO_vSetPinVal(SSD0_ENPORT,SSD0_ENPIN,VAL_LOW);
#else
		  DIO_vSetPinVal(SSD0_ENPORT,SSD0_ENPIN,VAL_HIGH);
#endif
	  }
	  break;
  case SSD1_ID:
	  {
#if SSD0_MODE==COMMON_CATHODE
		  DIO_vSetPinVal(SSD1_ENPORT,SSD1_ENPIN,VAL_LOW);
#else
		  DIO_vSetPinVal(SSD1_ENPORT,SSD1_ENPIN,VAL_HIGH);
#endif

       }
	  break;

 }
}
void SSD_vTurnOff(u8 A_u8SsdId)
{
	switch(A_u8SsdId)

{
  case SSD0_ID:
	  {

#if SSD0_MODE==COMMON_CATHODE
		  DIO_vSetPinVal(SSD0_ENPORT,SSD0_ENPIN,VAL_HIGH);
#else
		  DIO_vSetPinVal(SSD0_ENPORT,SSD0_ENPIN,VAL_LOW);
#endif
	  }
	  break;
  case SSD1_ID:
	  {
#if SSD0_MODE==COMMON_CATHODE
		  DIO_vSetPinVal(SSD1_ENPORT,SSD1_ENPIN,VAL_HIGH);
#else
		  DIO_vSetPinVal(SSD1_ENPORT,SSD1_ENPIN,VAL_LOW);
#endif

       }
	  break;
}
}
void SSD_vDisplayNum(u8 A_u8SsdId,u8 A_u8Num)
{
	static u8 L_u8SsdDecToSgArr[10]=
	{
			0b00111111,  /*0*/
			0b00000110,  /*1*/
			0b01011011,  /*2*/
			0b01001111,  /*3*/
			0b01100110,  /*4*/
			0b01101101,  /*5*/
			0b01111101,  /*6*/
			0b00000111,  /*7*/
			0b01111111,  /*8*/
			0b01101111   /*9*/


	};
	switch(A_u8SsdId)

	{
	  case SSD0_ID:
		  {

	#if SSD0_MODE==COMMON_CATHODE
			  DIO_vSetPortVal(SSD0_DATA_PORT,L_u8SsdDecToSgArr[A_u8Num]);
			  #else
			  DIO_vSetPortVal(SSD0_DATA_PORT,~(L_u8SsdDecToSgArr[A_u8Num]));

	#endif
		  }
		  break;
	  case SSD1_ID:
		  {


#if SSD1_MODE==COMMON_CATHODE
			  DIO_vSetPortVal(SSD1_DATA_PORT,L_u8SsdDecToSgArr[A_u8Num]);
			  #else
			  DIO_vSetPortVal(SSD1_DATA_PORT,~(L_u8SsdDecToSgArr[A_u8Num]));



	#endif

	       }
		  break;
	}

}

void SSD_vDisplaySigmentBorder(u8 A_u8SsdId,u8 A_u8Num)
{
	static u8 L_u8SsdDecToSgArrDigt[]=
	{
			1, /*A0*/
			2, /*B0*/
			4, /*C0*/
			8, /*D0*/
			8, /*D1*/
		    16, /*E1*/
		    32, /*F1*/
		    1, /*A1*/


	};
	switch(A_u8SsdId)

	{
	  case SSD0_ID:
		  {

	#if SSD0_MODE==COMMON_CATHODE
			  DIO_vSetPortVal(SSD0_DATA_PORT,L_u8SsdDecToSgArrDigt[A_u8Num]);
			  #else
			  DIO_vSetPortVal(SSD0_DATA_PORT,~(L_u8SsdDecToSgArrDigt[A_u8Num]));

	#endif
		  }
		  break;
	  case SSD1_ID:
		  {


#if SSD1_MODE==COMMON_CATHODE
			  DIO_vSetPortVal(SSD1_DATA_PORT,L_u8SsdDecToSgArrDigt[A_u8Num]);
			  #else
			  DIO_vSetPortVal(SSD1_DATA_PORT,~(L_u8SsdDecToSgArrDigt[A_u8Num]));



	#endif

	       }
		  break;
	}

}


void SSD1_vDisplayNum(u8 A_u8Num)
{
	static u8 L_u8SsdDecToSgArr[10]=
	{
			0b00111111,  /*0*/
			0b00000110,  /*1*/
			0b00011011,  /*2*/
			0b00001111,  /*3*/
			0b00100110,  /*4*/
			0b00101101,  /*5*/
			0b00111101,  /*6*/
			0b00000111,  /*7*/
			0b00111111,  /*8*/
			0b00101111   /*9*/


	};
	static u8 L_u8SsdDEcToSgArr1[10]=
	{
			1,
			1,
			0,
			0,
			0,
			0,
			0,
			1,
			0,
			0
	};


#if SSD1_MODE==COMMON_CATHODE
			  DIO_vSetPortVal(SSD1_DATA_PORT,L_u8SsdDecToSgArr[A_u8Num]);
			  DIO_vSetPinVal(PORTB_ID,PIN7_ID,L_u8SsdDEcToSgArr1[A_u8Num]);
			  #else
			  DIO_vSetPortVal(SSD1_DATA_PORT,~(L_u8SsdDecToSgArr[A_u8Num]));
			  DIO_vSetPinVal(PORTB_ID,PIN7_ID,L_u8SsdDEcToSgArr1[A_u8Num]);



	#endif




}

