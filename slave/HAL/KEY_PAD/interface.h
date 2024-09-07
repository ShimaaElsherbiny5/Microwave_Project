/*
 * interface.h
 *
 *  Created on: Jul 30, 2024
 *      Author: shimaa
 */

#ifndef HAL_KEY_PAD_INTERFACE_H_
#define HAL_KEY_PAD_INTERFACE_H_

#include "C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"

//macros
#define KEY_PAD_row_0   0
#define KEY_PAD_row_1   1
#define KEY_PAD_row_2   2
#define KEY_PAD_row_3   3

#define KEY_PAD_column_0   4
#define KEY_PAD_column_1   5
#define KEY_PAD_column_2   6
#define KEY_PAD_column_3   7

#define KEY_PAD_PORTA   0
#define KEY_PAD_PORTB   1
#define KEY_PAD_PORTC   2
#define KEY_PAD_PORTD   3

#define KEY_PAD_pressed  0
#define KEY_PAD_not_pressed 1

#define KET_PAD_ROW_NUM 4
#define KET_PAD_COLUMN_NUM 4

//prototypes

void KEYPAD_H_INIT();
void KEYPAD_H_GET_BUTTON(u8 *U8CHAR);

#endif /* HAL_KEY_PAD_INTERFACE_H_ */
