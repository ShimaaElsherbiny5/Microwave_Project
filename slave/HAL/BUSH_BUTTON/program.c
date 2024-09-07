/*
 * program.c
 *
 *  Created on: Jul 27, 2024
 *      Author: shimaa
 */

//includes
#include "C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"
#include"interface.h"
#include "C:\Users\shimaa\Desktop\microwave_project\code\slave\MCAL\DIO\interface.h"

//implementation
void BUSH_BUTTON_H_INIT(u8 U8PORT,u8 U8PIN)
{
	DIO_M_SET_PIN_DIRECTION(U8PORT,U8PIN,INPUT);
}

void BUSH_BUTTON_H_GET_VALUE(u8 U8PORT,u8 U8PIN,u8 *U8VALUE)
{
	DIO_M_GET_PIN_VALUE(U8PORT,U8PIN,U8VALUE);
}

void BUSH_BUTTON_H_PULL_UP(u8 U8PORT,u8 U8PIN)
{
	DIO_M_SET_PIN_VALUE(U8PORT,U8PIN,BUSH_BUTTON_HIGH);
}
