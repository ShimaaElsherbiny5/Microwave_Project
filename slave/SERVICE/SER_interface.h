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

#define TempThreshold 35

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

void keypad_read_time(u8 *minutes,u8 *seconds);


void keypad_read_temperature(u8 *temp);


void WEIGHT_INIT(u8 U8PORT ,u8 U8PIN);


void read_weight_value(u8 U8PORT ,u8 U8PIN,u8 *U8VALUE);

  //     ************************************************  Software interface Declaration UART **********************************************************       //

void TRANSMIT_INIT();


void send_command_to_master(u8 command);





#endif /* SERVICE_SER_INTERFACE_H_ */
