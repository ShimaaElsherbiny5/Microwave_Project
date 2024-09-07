/*
 * program.c
 *
 *  Created on: Aug 4, 2024
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

void ADC_INITI()
{
	*ADC_ADMUX|=(ADC_VILTAGE_REFRANCE<<ADC_ADMUX_REFS0);
	*ADC_ADCSRA|=ADC_PRESCALER;
	CLEAR_BIT(*ADC_ADMUX,ADC_ADMUX_ADLAR);
	SET_BIT(*ADC_ADCSRA,ADC_ADCSRA_ADEN);

}

void ADC_START_CONVERTION(u8 U8CHANNEL ,u16 *VALUE)
{
	if(U8CHANNEL<=ADC_CHANNEL7)
	{
		*ADC_ADMUX|=U8CHANNEL;
		SET_BIT(*ADC_ADCSRA,ADC_ADCSRA_ADSC);
		while(GET_BIT(*ADC_ADCSRA,ADC_ADCSRA_ADSC));
		*VALUE=*ADC_ADCL+(GET_BIT(*ADC_ADCH,0)*256)+(GET_BIT(*ADC_ADCH,1)*512);


	}

}
