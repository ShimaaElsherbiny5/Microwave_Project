/*
 * program.c
 *
 *  Created on: Aug 8, 2024
 *      Author: shimaa
 */

//includes
#include"C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"
#include"C:\Users\shimaa\Documents\projectEM\LIB\BIT_MATH.h"
#include"privet.h"
#include"config.h"
#include"interface.h"
#include<util/delay.h>
//implementation
void UART_INIT()
{

	SET_BIT(*UART_UCSRC,UART_UCSRC_URSEL);
	//MODE SELECT
	*UART_UCSRC|=(UART_MODE_SELECT<<UART_UCSRC_UMSEL);
	//PARITY MODE
	*UART_UCSRC|=(UART_PARITY_MODE<<UART_UCSRC_UPM0);
	//STOP BIT
	*UART_UCSRC|=(UART_STOP_BIT<<UART_UCSRC_USBS);
	//CHARACTER SIZE
	*UART_UCSRC|=(UART_CHAR_SIZE_8BIT_UCSZ0_UCSZ1<<UART_UCSRC_UCSZ0);
	*UART_UCSRB|=(UART_CHAR_SIZE_8BIT_UCSZ2<<UART_UCSRB_UCSZ2);

	*UART_UBRRL=51;

	SET_BIT(*UART_UCSRB,UART_UCSRB_RXEN);
	SET_BIT(*UART_UCSRB,UART_UCSRB_TXEN);

}

void UART_TRANSMIT(u8 U8DATA)
{

	while(GET_BIT(*UART_UCSRA,UART_UCSRA_UDRE)==0);
	*UART_UDR=U8DATA;
}

void UART_RECEIVE(u8 *U8DATA)
{

	while(GET_BIT(*UART_UCSRA,UART_UCSRA_RXC)==0);
	*U8DATA=*UART_UDR;
}

void UART_TRANSMIT_STRING(u8 *U8DATA)
{
u8 data_count=0;
	for(data_count=0;U8DATA[data_count]!='\0';data_count++)
	{
		UART_TRANSMIT(U8DATA[data_count]);
	}

}
