/*
 * program.c
 *
 *  Created on: Jul 27, 2024
 *      Author: shimaa
 */

//includes
#include "C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"
#include"interface.h"
#include "C:\Users\shimaa\Desktop\microwave_project\code\master\MCAL\DIO\interface.h"
#include<util/delay.h>

//implementation

void LED_H_INIT_1LED(u8 U8PORT,u8 U8PIN)
{
DIO_M_SET_PIN_DIRECTION(U8PORT,U8PIN,OUTPUT);
}

void LED_H_INIT_8LED(u8 U8PORT)
{
	DIO_M_SET_PORT_DIRECTION(U8PORT,OUTPUT_PORT);

}

void LED_H_TURN_ON_OR_OFF(u8 U8PORT,u8 U8PIN,u8 U8STATE)
{
	DIO_M_SET_PIN_VALUE(U8PORT,U8PIN,U8STATE);

}

void LED_H_BLINK_LED(u8 U8PORT,u8 U8PIN)
{
	DIO_M_SET_PIN_VALUE(U8PORT,U8PIN,HIGH);
	_delay_ms(1000);
	DIO_M_SET_PIN_VALUE(U8PORT,U8PIN,LOW);
	_delay_ms(1000);
}

void LED_H_TURN_ON_OR_OFF_8LEDS(u8 U8PORT,u8 U8STATE)
{
	DIO_M_SET_PORT_VALUE(U8PORT,U8STATE);
}

void LED_H_BLINK_8LEDS(u8 U8PORT)
{
	DIO_M_SET_PORT_VALUE(U8PORT,HIGH_PORT);
	_delay_ms(1000);
	DIO_M_SET_PORT_VALUE(U8PORT,LOW_PORT);
	_delay_ms(1000);
}
