/*
 * privet.h
 *
 *  Created on: Aug 4, 2024
 *      Author: shimaa
 */

#ifndef MCAL_ADC_PRIVET_H_
#define MCAL_ADC_PRIVET_H_

#define ADC_ADMUX    ((volatile u8*)0X27)
#define ADC_ADCSRA   ((volatile u8*)0X26)
#define ADC_ADCH     ((volatile u8*)0X25)
#define ADC_ADCL     ((volatile u8*)0X24)
#define ADC_SFIOR    ((volatile u8*)0X50)

#define ADC_ADMUX_MUXO   0
#define ADC_ADMUX_MUX1   1
#define ADC_ADMUX_MUX2   2
#define ADC_ADMUX_MUX3   3
#define ADC_ADMUX_MUX4   4
#define ADC_ADMUX_ADLAR  5
#define ADC_ADMUX_REFS0  6
#define ADC_ADMUX_REFS1  7

#define ADC_ADCSRA_ADPS0   0
#define ADC_ADCSRA_ADPS1   1
#define ADC_ADCSRA_ADPS2   2
#define ADC_ADCSRA_ADSC    6
#define ADC_ADCSRA_ADEN    7

#define ADC_PRESCALER_2   1
#define ADC_PRESCALER_4   2
#define ADC_PRESCALER_8   3
#define ADC_PRESCALER_16  4
#define ADC_PRESCALER_32  5
#define ADC_PRESCALER_64  6
#define ADC_PRESCALER_128 7

#define ADC_LAR_BIT   8

#define ADC_VREF_AREF   0
#define ADC_VREF_AVCC   1
#define ADC_VREF_2_56V  3





#endif /* MCAL_ADC_PRIVET_H_ */
