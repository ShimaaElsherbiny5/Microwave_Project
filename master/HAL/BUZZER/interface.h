/*
 * interface.h
 *
 *  Created on: Jul 28, 2024
 *      Author: shimaa
 */

#ifndef HAL_BUZZER_INTERFACE_H_
#define HAL_BUZZER_INTERFACE_H_

#include "C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"

//macros
#define BUZZER_pin_0   0
#define BUZZER_pin_1   1
#define BUZZER_pin_2   2
#define BUZZER_pin_3   3
#define BUZZER_pin_4   4
#define BUZZER_pin_5   5
#define BUZZER_pin_6   6
#define BUZZER_pin_7   7

#define BUZZER_PORTA   0
#define BUZZER_PORTB   1
#define BUZZER_PORTC   2
#define BUZZER_PORTD   3

#define BUZZER_ON   1
#define BUZZER_OFF  0

//prototypes
void BUZZER_H_INIT(u8 U8PORT,u8 U8PIN);
void BUZZER_H_TURN_ON(u8 U8PORT,u8 U8PIN);
void BUZZER_H_TURN_OFF(u8 U8PORT,u8 U8PIN);
void BUZZER_H_BEEP_ONCE(u8 U8PORT,u8 U8PIN);
void BUZZER_H_BEEP_TWICE(u8 U8PORT,u8 U8PIN);
void BUZZER_H_BEEP_TRIPLE(u8 U8PORT,u8 U8PIN);


#endif /* HAL_BUZZER_INTERFACE_H_ */
