/*
 * main.c
 *
 *  Created on: Jul 24, 2024
 *      Author: shimaa
 */

     //     **********************************************************  Master  ********************************************************************       //


    //     **********************************************************  Includes  ********************************************************************       //

#include"../HAL/LCD/interface.h"
#include"../HAL/LED/interface.h"
#include"../HAL/BUZZER/interface.h"
#include"../LIB/STD_TYPE.H"
#include"../SERVICE/SER_interface.h"

#include <util/delay.h>
#include<stdio.h>


int main()
{

    //     ********************************************************  Configuration  ******************************************************************       //

	/*---LCD Configuration----*/

	struct lcd_config LCD;
			LCD.LCD_DATA_PORT=LCD_PORTA;
			LCD.LCD_RS_PORT=LCD_PORTB;
			LCD.LCD_RW_PORT=LCD_PORTB;
			LCD.LCD_EN_PORT=LCD_PORTB;

			LCD.LCD_RS_PIN=LCD_pin_5;
			LCD.LCD_RW_PIN=LCD_pin_6;
			LCD.LCD_EN_PIN=LCD_pin_7;

    //     **********************************************************  Variables  *******************************************************************       //

u8 Rec_command=0;

u8 Welcome[]="Welcome";
u8 Enter_Time[]="Enter Time";
u8 Enter_Temperature[]="EnterTemperature";
u8 Check_Door_And_Weight[]="CheckDoor&Weight";
u8 Heating[]="Heating";
u8 Cancelled[]="Cancelled";
u8 Done[]="Done";
u8 Dangerous[]="Dangerous";


   //     *******************************************************  Initializations  ****************************************************************       //

/*---LCD Initialization----*/
LCD_INIT(&LCD);

/*---Receive Initialization----*/
RECEIVE_INIT();

/*---Motor Initialization----*/
MOTOR_INIT(PORTD,PIN_5);

/*---Buzzer Initialization----*/
BUZZER_H_INIT(BUZZER_PORTD,BUZZER_pin_6);

/*---LEDs Initialization----*/
LED_H_INIT_1LED(LED_PORTD,LED_pin_2); //Heater led
LED_H_INIT_1LED(LED_PORTD,LED_pin_3); //Light led
LED_H_INIT_1LED(LED_PORTD,LED_pin_4); //Warning led


   //     **********************************************************  Program  ********************************************************************       //

while(1)
{
	Receive_command_from_slave(&Rec_command);

	 //     **********************************************************  States  ********************************************************************       //

    /*--- Welcome State ----*/
	if(Rec_command=='W')
	{
		LED_H_TURN_ON_OR_OFF(LED_PORTD,LED_pin_4,LED_OFF);  //Warning off
		LCD_CLEAR_DIS(&LCD);
		LCD_WRITE_STRING(&LCD,Welcome);
		_delay_ms(2000);
		LCD_CLEAR_DIS(&LCD);
		LCD_WRITE_STRING(&LCD,Enter_Time);
	}

    /*--- Enter Temperature State ----*/
	else if(Rec_command=='M')
	{
		LCD_CLEAR_DIS(&LCD);
		LCD_WRITE_STRING(&LCD,Enter_Temperature);
	}

    /*--- Heating State ----*/
	else if(Rec_command=='K')
	{
		LCD_CLEAR_DIS(&LCD);
		LCD_WRITE_STRING(&LCD,Heating);
		LED_H_TURN_ON_OR_OFF(LED_PORTD,LED_pin_3,LED_ON);  //Light on
		LED_H_TURN_ON_OR_OFF(LED_PORTD,LED_pin_2,LED_ON);  //Heater on
		MAKE_MOTOR_ON(PORTD,PIN_5);
	}

    /*--- Error in Door Or Weight State ----*/
	else if(Rec_command=='E')
	{
		LCD_CLEAR_DIS(&LCD);
		LCD_WRITE_STRING(&LCD,Check_Door_And_Weight);
	}

    /*--- Warning State ----*/
	else if(Rec_command=='R')
	{
		LCD_CLEAR_DIS(&LCD);
		LED_H_TURN_ON_OR_OFF(LED_PORTD,LED_pin_4,LED_ON);  //Warning on
		_delay_ms(1000);
		LED_H_TURN_ON_OR_OFF(LED_PORTD,LED_pin_4,LED_OFF);  //Warning off
	}

    /*--- Cancel State ----*/
	else if(Rec_command=='C')
	{
		LCD_CLEAR_DIS(&LCD);
		LCD_WRITE_STRING(&LCD,Cancelled);
		MAKE_MOTOR_OFF(PORTD,PIN_5);
		LED_H_TURN_ON_OR_OFF(LED_PORTD,LED_pin_2,LED_OFF);  //Heater off
		LED_H_TURN_ON_OR_OFF(LED_PORTD,LED_pin_3,LED_OFF);  //Light off
		_delay_ms(1000);
	}

    /*--- Finish State ----*/
	else if(Rec_command=='F')
	{
		MAKE_MOTOR_OFF(PORTD,PIN_5);
		LED_H_TURN_ON_OR_OFF(LED_PORTD,LED_pin_2,LED_OFF);  //Heater off
		LED_H_TURN_ON_OR_OFF(LED_PORTD,LED_pin_3,LED_OFF);  //Light off
		BUZZER_H_BEEP_ONCE(BUZZER_PORTD,BUZZER_pin_6);
		LCD_CLEAR_DIS(&LCD);
		LCD_WRITE_STRING(&LCD,Done);
		_delay_ms(2000);
		LCD_CLEAR_DIS(&LCD);
	}

    /*--- Dangerous State ----*/
	else if(Rec_command=='A')
	{
		LCD_CLEAR_DIS(&LCD);
		LCD_WRITE_STRING(&LCD,Dangerous);
		MAKE_MOTOR_OFF(PORTD,PIN_5);
		LED_H_TURN_ON_OR_OFF(LED_PORTD,LED_pin_2,LED_OFF);  //Heater off
		LED_H_TURN_ON_OR_OFF(LED_PORTD,LED_pin_3,LED_OFF);  //Light off
		LED_H_TURN_ON_OR_OFF(LED_PORTD,LED_pin_4,LED_ON);  //Warning on
		BUZZER_H_BEEP_TRIPLE(BUZZER_PORTD,BUZZER_pin_6);

	}

}


}

