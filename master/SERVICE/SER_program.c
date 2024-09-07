/*
 * SER_program.c
 *
 *  Created on: Aug 19, 2024
 *      Author: shimaa
 */


     //     **********************************************************  Master  ********************************************************************       //


    //     **********************************************************  Includes  ********************************************************************       //

#include"../LIB/STD_TYPE.H"
#include"../MCAL/DIO/interface.h"
#include"../MCAL/UART/interface.h"
#include"SER_interface.h"
#include <util/delay.h>

  //     **************************************************  APP Functions Implementation  ************************************************************       //

void MOTOR_INIT(u8 U8PORT ,u8 U8PIN)
{
	DIO_M_SET_PIN_DIRECTION(U8PORT ,U8PIN,OUTPUT);
}

void MAKE_MOTOR_ON(u8 U8PORT ,u8 U8PIN)
{
	DIO_M_SET_PIN_VALUE(U8PORT ,U8PIN ,HIGH);
}

void MAKE_MOTOR_OFF(u8 U8PORT ,u8 U8PIN)
{
	DIO_M_SET_PIN_VALUE(U8PORT ,U8PIN ,LOW);
}

  //     ************************************************  UART Functions Implementation **********************************************************       //

void RECEIVE_INIT()
{
	UART_INIT();
}

void Receive_command_from_slave(u8* command)
{
	UART_RECEIVE(command);
	_delay_us(100);

}


