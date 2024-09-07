/*
 * interface.h
 *
 *  Created on: Jul 27, 2024
 *      Author: shimaa
 */

#ifndef HAL_BUSH_BUTTON_INTERFACE_H_
#define HAL_BUSH_BUTTON_INTERFACE_H_

#include "C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"

//macros
#define BUSH_BUTTON_pin_0   0
#define BUSH_BUTTON_pin_1   1
#define BUSH_BUTTON_pin_2   2
#define BUSH_BUTTON_pin_3   3
#define BUSH_BUTTON_pin_4   4
#define BUSH_BUTTON_pin_5   5
#define BUSH_BUTTON_pin_6   6
#define BUSH_BUTTON_pin_7   7

#define BUSH_BUTTON_PORTA   0
#define BUSH_BUTTON_PORTB   1
#define BUSH_BUTTON_PORTC   2
#define BUSH_BUTTON_PORTD   3

#define BUSH_BUTTON_HIGH  1
#define BUSH_BUTTON_LOW   0



//prototypes
void BUSH_BUTTON_H_INIT(u8 U8PORT,u8 U8PIN);
void BUSH_BUTTON_H_GET_VALUE(u8 U8PORT,u8 U8PIN,u8 *U8VALUE);
void BUSH_BUTTON_H_PULL_UP(u8 U8PORT,u8 U8PIN);


#endif /* HAL_BUSH_BUTTON_INTERFACE_H_ */
