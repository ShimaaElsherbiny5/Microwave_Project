/*
 * privet.h
 *
 *  Created on: Jul 24, 2024
 *      Author: shimaa
 */

#ifndef MCAL_DIO_PRIVET_H_
#define MCAL_DIO_PRIVET_H_


#define DIO_PORTA  (volatile u8*)0X3B
#define DIO_DDRA   (volatile u8*)0X3A
#define DIO_PINA   (volatile u8*)0X39

#define DIO_PORTB  (volatile u8*)0X38
#define DIO_DDRB  (volatile u8*)0X37
#define DIO_PINB   (volatile u8*)0X36

#define DIO_PORTC  (volatile u8*)0X35
#define DIO_DDRC   (volatile u8*)0X34
#define DIO_PINC   (volatile u8*)0X33

#define DIO_PORTD  (volatile u8*)0X32
#define DIO_DDRD   (volatile u8*)0X31
#define DIO_PIND   (volatile u8*)0X30




#endif /* MCAL_DIO_PRIVET_H_ */
