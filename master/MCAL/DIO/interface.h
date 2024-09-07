/*
 * interface.h
 *
 *  Created on: Jul 24, 2024
 *      Author: shimaa
 */

#ifndef MCAL_DIO_INTERFACE_H_
#define MCAL_DIO_INTERFACE_H_

//includes
#include"C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"
//preprocessor directive
#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

#define DIO_PPORTA 0
#define DIO_PPORTB 1
#define DIO_PPORTC 2
#define DIO_PPORTD 3

#define OUTPUT 1
#define INPUT  0

#define OUTPUT_PORT 0xff
#define INPUT_PORT  0x00

#define HIGH 1
#define LOW  0

#define HIGH_PORT 0xff
#define LOW_PORT  0x00
//prototypes
//for PINS
void DIO_M_SET_PIN_DIRECTION(u8 U8PORT ,u8 U8PIN,u8 U8DIRECTION);
void DIO_M_SET_PIN_VALUE(u8 U8PORT ,u8 U8PIN,u8 U8VALUE);
void DIO_M_GET_PIN_VALUE(u8 U8PORT ,u8 U8PIN,u8 *U8VALUE);

//for PORTS
void DIO_M_SET_PORT_DIRECTION(u8 U8PORT ,u8 U8DIRECTION);
void DIO_M_SET_PORT_VALUE(u8 U8PORT ,u8 U8VALUE);
void DIO_M_GET_PORT_VALUE(u8 U8PORT ,u8 *U8VALUE);



#endif /* MCAL_DIO_INTERFACE_H_ */
