/*
 * SER_interface.h
 *
 *  Created on: Aug 19, 2024
 *      Author: shimaa
 */

#ifndef SERVICE_SER_INTERFACE_H_
#define SERVICE_SER_INTERFACE_H_

   //     **********************************************************  APP SERVICE  ********************************************************************       //

//     **********************************************************  Macros Declaration  ********************************************************************     //


   //     **********************************************************  DIO SERVICE  ********************************************************************       //

//     **********************************************************  Macros Declaration  ********************************************************************     //

		/*---Ports----*/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

		/*---Ports----*/
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

  //     **************************************************  Software interface Declaration  ************************************************************       //

void MOTOR_INIT(u8 U8PORT ,u8 U8PIN);


void MAKE_MOTOR_ON(u8 U8PORT ,u8 U8PIN);


void MAKE_MOTOR_OFF(u8 U8PORT ,u8 U8PIN);

  //     ************************************************  Software interface Declaration UART **********************************************************       //

void RECEIVE_INIT();


void Receive_command_from_slave(u8* command);




#endif /* SERVICE_SER_INTERFACE_H_ */
