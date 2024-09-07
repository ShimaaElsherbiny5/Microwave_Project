/*
 * SER_prgram.c
 *
 *  Created on: Aug 19, 2024
 *      Author: shimaa
 */


     //     **********************************************************  Slave  ********************************************************************       //


    //     **********************************************************  Includes  ********************************************************************       //

#include"../LIB/STD_TYPE.H"
#include"../MCAL/DIO/interface.h"
#include"../MCAL/UART/interface.h"
#include"SER_interface.h"
#include <util/delay.h>

  //     **************************************************  APP Functions Implementation  ************************************************************       //

void keypad_read_time(u8 *minutes,u8 *seconds)
{
	u8 key=0xff;
	u8 operation=0;
	u8 enter=1;

	while(enter)
	{
		KEYPAD_H_GET_BUTTON(&key);
		if(key!='+' && key!='-' && key!='*' && key!=0xfd && key!='c' && key!=0xff && key!='=')
		{
			if(operation == 0)
			{
				*minutes=(*minutes*10)+key;
				key=0xff;
			}
			else
			{
				*seconds=(*seconds*10)+key;
				key=0xff;
			}
		}
		else if(key!=0xff && key!='c' &&key!='=')
		{
			operation=key;
			key=0xff;
		}
		else if(key!=0xff && key!='c')
		{
			enter=0;
		}
		else if(key!=0xff)
		{
			*minutes=0;
			*seconds=0;
			key=0xff;
		}
	}
}

void keypad_read_temperature(u8 *temp)
{
	u8 key=0xff;
	u8 enter=1;

	while(enter)
	{
		KEYPAD_H_GET_BUTTON(&key);
		if(key!='+' && key!='-' && key!='*' && key!=0xfd && key!='c' && key!=0xff && key!='=')
		{
			*temp=(*temp*10)+key;
			key=0xff;
		}
		else if(key!=0xff && key!='c')
		{
			enter=0;
		}
		else if(key!=0xff)
		{
			*temp=0;
			key=0xff;
		}
	}
}

void WEIGHT_INIT(u8 U8PORT ,u8 U8PIN)
{
	DIO_M_SET_PIN_DIRECTION(U8PORT ,U8PIN,INPUT);
}

void read_weight_value(u8 U8PORT ,u8 U8PIN,u8 *U8VALUE)
{
	DIO_M_GET_PIN_VALUE(U8PORT , U8PIN,U8VALUE);
}


  //     ************************************************  UART Functions Implementation **********************************************************       //

void TRANSMIT_INIT()
{
	UART_INIT();
}

void send_command_to_master(u8 command)
{

	UART_TRANSMIT(command);
	_delay_us(100);

}
