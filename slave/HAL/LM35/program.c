/*
 * program.c
 *
 *  Created on: Aug 6, 2024
 *      Author: shimaa
 */


//include
#include "C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"
#include"interface.h"
#include"C:\Users\shimaa\Documents\projectEM\MCAL\ADC\interface.h"
#include"C:\Users\shimaa\Desktop\microwave_project\code\slave\MCAL\DIO\interface.h"
//implementation
u16 LM35_GET_TEMPERATURE(u8 U8PIN)
{
	u16 temp_value=0;
	DIO_M_SET_PIN_DIRECTION(LM35_PORTA,U8PIN,INPUT);
	ADC_INITI();
  ADC_START_CONVERTION(U8PIN,&temp_value);
	temp_value=(temp_value/2.0)-1;
	return temp_value;

}
