/*
 * interface.h
 *
 *  Created on: Aug 8, 2024
 *      Author: shimaa
 */

#ifndef MCAL_UART_INTERFACE_H_
#define MCAL_UART_INTERFACE_H_

//prototype
void UART_INIT();
void UART_TRANSMIT(u8 U8DATA);
void UART_RECEIVE(u8 *U8DATA);
void UART_TRANSMIT_STRING(u8 *U8DATA);


#endif /* MCAL_UART_INTERFACE_H_ */
