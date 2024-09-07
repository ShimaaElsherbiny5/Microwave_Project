/*
 * interface.h
 *
 *  Created on: Aug 4, 2024
 *      Author: shimaa
 */

#ifndef MCAL_ADC_INTERFACE_H_
#define MCAL_ADC_INTERFACE_H_

#define ADC_CHANNEL0  0
#define ADC_CHANNEL1  1
#define ADC_CHANNEL2  2
#define ADC_CHANNEL3  3
#define ADC_CHANNEL4  4
#define ADC_CHANNEL5  5
#define ADC_CHANNEL6  6
#define ADC_CHANNEL7  7

//prototype
void ADC_INITI();
void ADC_START_CONVERTION(u8 U8CHANNEL ,u16 *VALUE);



#endif /* MCAL_ADC_INTERFACE_H_ */
