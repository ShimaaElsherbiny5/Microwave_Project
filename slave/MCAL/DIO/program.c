/*
 * program.c
 *
 *  Created on: Jul 24, 2024
 *      Author: shimaa
 */

//include
#include"C:\Users\shimaa\Documents\projectEM\LIB\STD_TYPE.h"
#include"C:\Users\shimaa\Documents\projectEM\LIB\BIT_MATH.h"
#include"interface.h"
#include"privet.h"


u8 *PORTS_ARR[4]={DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD};
u8 *DDRS_ARR[4]={DIO_DDRA,DIO_DDRB,DIO_DDRC,DIO_DDRD};
u8 *PINS_ARR[4]={DIO_PINA,DIO_PINB,DIO_PINC,DIO_PIND};

//implementation
//for PINS
//set pin direction
void DIO_M_SET_PIN_DIRECTION(u8 U8PORT ,u8 U8PIN,u8 U8DIRECTION){
if(U8PIN<=DIO_PIN_7 && U8PORT<=DIO_PPORTD){
	if(U8DIRECTION==OUTPUT){
		SET_BIT(*DDRS_ARR[U8PORT],U8PIN);
	}
	else{
		CLEAR_BIT(*DDRS_ARR[U8PORT],U8PIN);
	}

}
}
//set pin value
void DIO_M_SET_PIN_VALUE(u8 U8PORT ,u8 U8PIN,u8 U8VALUE){
	if(U8PIN<=DIO_PIN_7 && U8PORT<=DIO_PPORTD){
		if(U8VALUE==HIGH){
			SET_BIT(*PORTS_ARR[U8PORT],U8PIN);
		}
		else{
			CLEAR_BIT(*PORTS_ARR[U8PORT],U8PIN);
		}

	}
}
//get pin value
void DIO_M_GET_PIN_VALUE(u8 U8PORT ,u8 U8PIN,u8 *U8VALUE){
	if(U8PIN<=DIO_PIN_7 && U8PORT<=DIO_PPORTD){
			*U8VALUE=GET_BIT(*PINS_ARR[U8PORT],U8PIN);

		}
}

//for PORTS
//set port direction
void DIO_M_SET_PORT_DIRECTION(u8 U8PORT ,u8 U8DIRECTION){
	if( U8PORT<=DIO_PPORTD){

			*DDRS_ARR[U8PORT]=U8DIRECTION;


	}
}
//set port value
void DIO_M_SET_PORT_VALUE(u8 U8PORT ,u8 U8VALUE){
	if( U8PORT<=DIO_PPORTD){

				*PORTS_ARR[U8PORT]=U8VALUE;


		}
}
//get port value
void DIO_M_GET_PORT_VALUE(u8 U8PORT ,u8 *U8VALUE){
	if( U8PORT<=DIO_PPORTD){

		*U8VALUE=*PINS_ARR[U8PORT];
			}
}

