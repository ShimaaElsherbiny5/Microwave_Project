/*
 * program.c
 *
 *  Created on: Aug 1, 2024
 *      Author: shimaa
 */
//includes
#include "C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"
#include "C:\Users\shimaa\Documents\projectEM\LIB\BIT_MATH.h"
#include"interface.h"
#include "C:\Users\shimaa\Desktop\microwave_project\code\slave\MCAL\DIO\interface.h"
#include<util/delay.h>
//implementation

void SSD_INITI(u8 U8PORT,u8 U8PINSELLECTION)
{
	if(U8PINSELLECTION==SSD_LOWER_PIN)
	{
		for(u8 pin_count=SSD_pin_0;pin_count<=SSD_pin_3;pin_count++){
			DIO_M_SET_PIN_DIRECTION(U8PORT,pin_count,OUTPUT);
		}

	}
	else{
		for(u8 pin_count=SSD_pin_4;pin_count<=SSD_pin_7;pin_count++){
					DIO_M_SET_PIN_DIRECTION(U8PORT,pin_count,OUTPUT);
				}
	}
}
void SSD_WRITE_NUM(u8 U8PORT,u8 U8PINSELLECTION,u8 U8NUMBER)
{
	u8 VALUE=0;
	if(U8PINSELLECTION==SSD_LOWER_PIN)
		{
			for(u8 pin_count=SSD_pin_0;pin_count<=SSD_pin_3;pin_count++){
				VALUE=GET_BIT(U8NUMBER,pin_count);
				DIO_M_SET_PIN_VALUE(U8PORT,pin_count,VALUE);
			}

		}
		else{
			for(u8 pin_count=SSD_pin_4;pin_count<=SSD_pin_7;pin_count++){
				VALUE=GET_BIT(U8NUMBER,pin_count);
				DIO_M_SET_PIN_VALUE(U8PORT,pin_count,VALUE);
					}
		}

}
void SSD_WRITE_FORWARD_NUM(u8 U8PORT,u8 U8PINSELLECTION,u8 U8NUMBER)
{
	for(u8 FORWARD_COUNTER=0;FORWARD_COUNTER<=U8NUMBER;FORWARD_COUNTER++){
		SSD_WRITE_NUM(U8PORT,U8PINSELLECTION,FORWARD_COUNTER);
		_delay_ms(2000);
	}

}
void SSD_WRITE_REVERSE_NUM(u8 U8PORT,u8 U8PINSELLECTION,u8 U8NUMBER)
{
	for(u8 FORWARD_COUNTER=U8NUMBER;FORWARD_COUNTER>=0;FORWARD_COUNTER--){
			SSD_WRITE_NUM(U8PORT,U8PINSELLECTION,FORWARD_COUNTER);
			_delay_ms(2000);
		}

}
