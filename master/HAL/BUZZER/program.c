/*
 * program.c
 *
 *  Created on: Jul 28, 2024
 *      Author: shimaa
 */

//includes
#include "C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"
#include"interface.h"
#include "C:\Users\shimaa\Desktop\microwave_project\code\master\MCAL\DIO\interface.h"
#include<util/delay.h>

//implementation
void BUZZER_H_INIT(u8 U8PORT,u8 U8PIN)
{
	DIO_M_SET_PIN_DIRECTION(U8PORT,U8PIN,OUTPUT);
}
void BUZZER_H_TURN_ON(u8 U8PORT,u8 U8PIN)
{
	DIO_M_SET_PIN_VALUE(U8PORT,U8PIN,BUZZER_ON);
}
void BUZZER_H_TURN_OFF(u8 U8PORT,u8 U8PIN)
{
	DIO_M_SET_PIN_VALUE(U8PORT,U8PIN,BUZZER_OFF);

}
void BUZZER_H_BEEP_ONCE(u8 U8PORT,u8 U8PIN)
{
	BUZZER_H_TURN_ON(U8PORT,U8PIN);
	_delay_ms(1000);
	BUZZER_H_TURN_OFF(U8PORT,U8PIN);

}
void BUZZER_H_BEEP_TWICE(u8 U8PORT,u8 U8PIN)
{
	BUZZER_H_BEEP_ONCE(U8PORT,U8PIN);
	_delay_ms(1000);
	BUZZER_H_BEEP_ONCE(U8PORT,U8PIN);

}
void BUZZER_H_BEEP_TRIPLE(u8 U8PORT,u8 U8PIN)
{
	BUZZER_H_BEEP_TWICE(U8PORT,U8PIN);
	_delay_ms(1000);
	BUZZER_H_BEEP_ONCE(U8PORT,U8PIN);
}

