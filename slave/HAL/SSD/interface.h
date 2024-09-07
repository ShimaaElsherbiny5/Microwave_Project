/*
 * interface.h
 *
 *  Created on: Aug 1, 2024
 *      Author: shimaa
 */

#ifndef HAL_SSD_INTERFACE_H_
#define HAL_SSD_INTERFACE_H_

//include
#include "C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"
#include"C:\Users\shimaa\Documents\projectEM\LIB\BIT_MATH.h"
//macros
#define SSD_pin_0   0
#define SSD_pin_1   1
#define SSD_pin_2   2
#define SSD_pin_3   3
#define SSD_pin_4   4
#define SSD_pin_5   5
#define SSD_pin_6   6
#define SSD_pin_7   7

#define SSD_PORTA   0
#define SSD_PORTB   1
#define SSD_PORTC   2
#define SSD_PORTD   3

#define SSD_UPPER_PIN 0xf0
#define SSD_LOWER_PIN 0x0f

#define SSD_UPPER_0   0
#define SSD_UPPER_1   0x10
#define SSD_UPPER_2   0x20
#define SSD_UPPER_3   0x30
#define SSD_UPPER_4   0x40
#define SSD_UPPER_5   0x50
#define SSD_UPPER_6   0x60
#define SSD_UPPER_7   0x70
#define SSD_UPPER_8   0x80
#define SSD_UPPER_9   0x90


//prototype
void SSD_INITI(u8 U8PORT,u8 U8PINSELLECTION);
void SSD_WRITE_NUM(u8 U8PORT,u8 U8PINSELLECTION,u8 U8NUMBER);
void SSD_WRITE_FORWARD_NUM(u8 U8PORT,u8 U8PINSELLECTION,u8 U8NUMBER);
void SSD_WRITE_REVERSE_NUM(u8 U8PORT,u8 U8PINSELLECTION,u8 U8NUMBER);


#endif /* HAL_SSD_INTERFACE_H_ */
