/*
 * interface.h
 *
 *  Created on: Jul 28, 2024
 *      Author: shimaa
 */

#ifndef HAL_LCD_INTERFACE_H_
#define HAL_LCD_INTERFACE_H_
//include
#include "C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"
#include"C:\Users\shimaa\Documents\projectEM\LIB\BIT_MATH.h"
#include"privet.h"
//macros
#define LCD_pin_0   0
#define LCD_pin_1   1
#define LCD_pin_2   2
#define LCD_pin_3   3
#define LCD_pin_4   4
#define LCD_pin_5   5
#define LCD_pin_6   6
#define LCD_pin_7   7

#define LCD_PORTA   0
#define LCD_PORTB   1
#define LCD_PORTC   2
#define LCD_PORTD   3

//preprocessor directive
struct lcd_config
{
	u8 LCD_RS_PIN;
	u8 LCD_RW_PIN;
	u8 LCD_EN_PIN;

	u8 LCD_RS_PORT;
	u8 LCD_RW_PORT;
	u8 LCD_EN_PORT;

	u8 LCD_DATA_PORT;
};
//prototype
void LCD_INIT(struct lcd_config *lcd_con);
void LCD_SEND_COMM(struct lcd_config *lcd_con,u8 COMM);
void LCD_WRITE_CHAR(struct lcd_config *lcd_con,u8 DATA);
void LCD_WRITE_STRING(struct lcd_config *lcd_con,u8 *DATA);
void LCD_CLEAR_DIS(struct lcd_config *lcd_con);
void LCD_RETYRN_HOME(struct lcd_config *lcd_con);
u8 LCD_u8_convert_num_to_char(u16 input);
void convert_s32_to_string(u16 value,u8 *str);

#endif /* HAL_LCD_INTERFACE_H_ */
