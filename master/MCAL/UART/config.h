/*
 * config.h
 *
 *  Created on: Aug 8, 2024
 *      Author: shimaa
 */

#ifndef MCAL_UART_CONFIG_H_
#define MCAL_UART_CONFIG_H_

#define UART_STOP_1BIT    0
#define UART_STOP_2BIT    1

#define UART_STOP_BIT   UART_STOP_1BIT


#define UART_ASYNCH  0
#define UART_SYNCH  1

#define UART_MODE_SELECT   UART_ASYNCH

#define UART_PARITY_MODE_DISABLE 0
#define UART_PARITY_MODE_EVEN    2
#define UART_PARITY_MODE_ODD     3

#define UART_PARITY_MODE   UART_PARITY_MODE_EVEN

#define UART_CHAR_SIZE_8BIT_UCSZ0_UCSZ1 3
#define UART_CHAR_SIZE_8BIT_UCSZ2       0

#define UART_CHAR_SIZE_9BIT_UCSZ0_UCSZ1 3
#define UART_CHAR_SIZE_9BIT_UCSZ2       1

#define UART_CHAR_SIZE_7BIT_UCSZ0_UCSZ1 2
#define UART_CHAR_SIZE_7BIT_UCSZ2       0





#endif /* MCAL_UART_CONFIG_H_ */
