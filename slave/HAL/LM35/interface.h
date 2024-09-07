/*
 * interface.h
 *
 *  Created on: Aug 6, 2024
 *      Author: shimaa
 */

#ifndef HAL_LM35_INTERFACE_H_
#define HAL_LM35_INTERFACE_H_

//include
#include "C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"
#include"C:\Users\shimaa\Documents\projectEM\LIB\BIT_MATH.h"
#include"C:\Users\shimaa\Documents\projectEM\MCAL\DIO\interface.h"
#include"C:\Users\shimaa\Documents\projectEM\MCAL\ADC\interface.h"
//macros
#define LM35_pin_0   0
#define LM35_pin_1   1
#define LM35_pin_2   2
#define LM35_pin_3   3
#define LM35_pin_4   4
#define LM35_pin_5   5
#define LM35_pin_6   6
#define LM35_pin_7   7

#define LM35_PORTA   0

//prototype
u16 LM35_GET_TEMPERATURE(u8 U8PIN);


#endif /* HAL_LM35_INTERFACE_H_ */
