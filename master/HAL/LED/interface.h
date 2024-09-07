/*
 * interface.h
 *
 *  Created on: Jul 27, 2024
 *      Author: shimaa
 */

#ifndef HAL_LED_INTERFACE_H_
#define HAL_LED_INTERFACE_H_

#include "C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"

//macros
#define LED_pin_0   0
#define LED_pin_1   1
#define LED_pin_2   2
#define LED_pin_3   3
#define LED_pin_4   4
#define LED_pin_5   5
#define LED_pin_6   6
#define LED_pin_7   7

#define LED_PORTA   0
#define LED_PORTB   1
#define LED_PORTC   2
#define LED_PORTD   3

#define LED_ON   1
#define LED_OFF  0

//prototypes
void LED_H_INIT_1LED(u8 U8PORT,u8 U8PIN);
void LED_H_INIT_8LED(u8 U8PORT);
void LED_H_TURN_ON_OR_OFF(u8 U8PORT,u8 U8PIN,u8 U8STATE);
void LED_H_BLINK_LED(u8 U8PORT,u8 U8PIN);
void LED_H_TURN_ON_OR_OFF_8LEDS(u8 U8PORT,u8 U8STATE);
void LED_H_BLINK_8LEDS(u8 U8PORT);



#endif /* HAL_LED_INTERFACE_H_ */
