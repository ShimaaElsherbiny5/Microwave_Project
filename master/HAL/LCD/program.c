/*
 * program.c
 *
 *  Created on: Jul 28, 2024
 *      Author: shimaa
 */
//includes
#include"interface.h"
#include"config.h"
#include"C:\Users\shimaa\Desktop\microwave_project\code\master\MCAL\DIO\interface.h"
#include<util/delay.h>
//implementation
void LCD_INIT(struct lcd_config *lcd_con)
{
DIO_M_SET_PIN_DIRECTION(lcd_con->LCD_EN_PORT,lcd_con->LCD_EN_PIN,OUTPUT);
DIO_M_SET_PIN_DIRECTION(lcd_con->LCD_RS_PORT,lcd_con->LCD_RS_PIN,OUTPUT);
DIO_M_SET_PIN_DIRECTION(lcd_con->LCD_RW_PORT,lcd_con->LCD_RW_PIN,OUTPUT);
DIO_M_SET_PORT_DIRECTION(lcd_con->LCD_DATA_PORT,OUTPUT_PORT);

_delay_ms(30);

LCD_SEND_COMM(lcd_con,0x38);//0x38 fun_set
_delay_us(39);

LCD_SEND_COMM(lcd_con,DISPLAY_ON_OFF);
_delay_us(39);

LCD_CLEAR_DIS(lcd_con);
_delay_ms(2);

LCD_SEND_COMM(lcd_con,ENTRY_MODE_SET);




}

void LCD_SEND_COMM(struct lcd_config *lcd_con,u8 COMM)
{
   DIO_M_SET_PIN_VALUE(lcd_con->LCD_RS_PORT,lcd_con->LCD_RS_PIN,LOW);
   DIO_M_SET_PIN_VALUE(lcd_con->LCD_RW_PORT,lcd_con->LCD_RW_PIN,LOW);
   DIO_M_SET_PORT_VALUE(lcd_con->LCD_DATA_PORT,COMM);
   DIO_M_SET_PIN_VALUE(lcd_con->LCD_EN_PORT,lcd_con->LCD_EN_PIN,HIGH);
   	_delay_ms(2);
   	DIO_M_SET_PIN_VALUE(lcd_con->LCD_EN_PORT,lcd_con->LCD_EN_PIN,LOW);
}

void LCD_WRITE_CHAR(struct lcd_config *lcd_con,u8 DATA)
{
	DIO_M_SET_PIN_VALUE(lcd_con->LCD_RS_PORT,lcd_con->LCD_RS_PIN,HIGH);
	DIO_M_SET_PIN_VALUE(lcd_con->LCD_RW_PORT,lcd_con->LCD_RW_PIN,LOW);
	DIO_M_SET_PORT_VALUE(lcd_con->LCD_DATA_PORT,DATA);
	DIO_M_SET_PIN_VALUE(lcd_con->LCD_EN_PORT,lcd_con->LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_M_SET_PIN_VALUE(lcd_con->LCD_EN_PORT,lcd_con->LCD_EN_PIN,LOW);
}

void LCD_WRITE_STRING(struct lcd_config *lcd_con,u8 *DATA)
{
	for(u8 index=0;DATA[index] !='\0';index++){
		LCD_WRITE_CHAR(lcd_con,DATA[index]);
	}

}
void LCD_CLEAR_DIS(struct lcd_config *lcd_con)
{
	LCD_SEND_COMM(lcd_con,CLEAR_DIS);
}

void LCD_RETYRN_HOME(struct lcd_config *lcd_con)
{
	LCD_SEND_COMM(lcd_con,0x02);
}
u8 LCD_u8_convert_num_to_char(u16 input)
{
return(input+0x30);
}

void convert_s32_to_string(u16 value,u8 *str)
{
	memset((u8 *)str,'\0',4);
	sprintf(str,"%d",value);
}
