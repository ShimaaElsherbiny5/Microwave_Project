/*
 * main.c
 *
 *  Created on: Jul 24, 2024
 *      Author: shimaa
 */
     //     **********************************************************  Slave  ********************************************************************       //


    //     **********************************************************  Includes  ********************************************************************       //

#include"../HAL/KEY_PAD/interface.h"
#include"../HAL/LM35/interface.h"
#include"../HAL/BUSH_BUTTON/interface.h"
#include"../HAL/SSD/interface.h"
#include"../LIB/STD_TYPE.H"
#include"../SERVICE/SER_interface.h"

#include <util/delay.h>
#include<stdio.h>


u8 upper_numbers[]={0,0b00010000,0b00100000,0b00110000,0b01000000,0b01010000,0b01100000,0b01110000,0b10000000,0b10010000};

int main()
{

    //     **********************************************************  Variables  *******************************************************************       //

		u8 T_command=0;

		u8 minutes=0;
		u8 seconds=0;
		u8 min_first_digit=0;
		u8 sec_first_digit=0;
		u8 sec_second_digit=0;
		u16 Total_seconds=0;
		u8 Target_Temp=0;
		u8 current_Temp=0;
		u8 start_check=1;
		u8 cancel_check=1;
		u8 door_check=1;
		u8 weight_check=0;

		u8 current_state=0;
		u8 flag=0;

	//     *******************************************************  Initializations  ****************************************************************       //

		/*---Keypad Initialization----*/
		KEYPAD_H_INIT();

		/*---Transmit Initialization----*/
		TRANSMIT_INIT();

		/*---7_Segments Initialization----*/
		SSD_INITI(SSD_PORTA,SSD_LOWER_PIN);  //min_first_digit
		SSD_INITI(SSD_PORTC,SSD_LOWER_PIN);  //sec_first_digit
		SSD_INITI(SSD_PORTC,SSD_UPPER_PIN);  //sec_second_digit

		/*---Weight Initialization----*/
        WEIGHT_INIT(PORTD,PIN_6);

        /*---Bush_Buttons Initialization----*/
        BUSH_BUTTON_H_INIT(BUSH_BUTTON_PORTD,BUSH_BUTTON_pin_3);  //start_button
        BUSH_BUTTON_H_INIT(BUSH_BUTTON_PORTD,BUSH_BUTTON_pin_4);  //cancel_button
        BUSH_BUTTON_H_INIT(BUSH_BUTTON_PORTD,BUSH_BUTTON_pin_2);  //door_button
        BUSH_BUTTON_H_PULL_UP(BUSH_BUTTON_PORTD,BUSH_BUTTON_pin_3); //start_button
        BUSH_BUTTON_H_PULL_UP(BUSH_BUTTON_PORTD,BUSH_BUTTON_pin_4); //cancel_button
        BUSH_BUTTON_H_PULL_UP(BUSH_BUTTON_PORTD,BUSH_BUTTON_pin_2); //door_button


     //     **********************************************************  Program  ********************************************************************       //

		while(1)
		{

	 //     **********************************************************  States  ********************************************************************       //

	        /*--- Welcome State ----*/
			if(current_state==0)
			{
				BUSH_BUTTON_H_GET_VALUE(BUSH_BUTTON_PORTD,BUSH_BUTTON_pin_3,&start_check);

				if(!start_check)
				{
					T_command='W';
					current_state=1;  //Enter Time State
				}
			}

	        /*--- Enter Time State ----*/
			else if(current_state==1)
			{
     			keypad_read_time(&minutes,&seconds);

				min_first_digit = minutes % 10;
				sec_first_digit = seconds % 10;
				sec_second_digit = seconds / 10;

				SSD_WRITE_NUM(SSD_PORTA,SSD_LOWER_PIN,min_first_digit);
				for(u8 check_num=0;check_num<=9;check_num++)
				{
					if(sec_second_digit==check_num)
					{
						SSD_WRITE_NUM(SSD_PORTC,SSD_UPPER_PIN,upper_numbers[check_num]);
					}
				}
				SSD_WRITE_NUM(SSD_PORTC,SSD_LOWER_PIN,sec_first_digit);

				Total_seconds = (minutes*60) + seconds;

				if(Total_seconds)
				{
					T_command='M';
					current_state=2;  //Enter Temperature State

					BUSH_BUTTON_H_GET_VALUE(BUSH_BUTTON_PORTD,BUSH_BUTTON_pin_4,&cancel_check);

					if(!cancel_check)
					{
						T_command='C';
						current_state=6;  //Cancel State
					}
				}
			}

	        /*--- Enter Temperature State ----*/
			else if(current_state==2)
			{
				keypad_read_temperature(&Target_Temp);

				if(Target_Temp)
				{
					current_state=3;  //Check Door & Weight state

					BUSH_BUTTON_H_GET_VALUE(BUSH_BUTTON_PORTD,BUSH_BUTTON_pin_4,&cancel_check);

					if(!cancel_check)
					{
						T_command='C';
						current_state=6;  //Cancel State
					}
				}
			}

	        /*--- Check Door & Weight State ----*/
			else if(current_state==3)
			{
				BUSH_BUTTON_H_GET_VALUE(BUSH_BUTTON_PORTD,BUSH_BUTTON_pin_2,&door_check);
				read_weight_value(PORTD,PIN_6,&weight_check);

				if(door_check==0 && weight_check==1)
				{
					T_command='K';
					current_state=4;  //Heating State
				}
				else
				{
					T_command='E';
					current_state=3;  //Check Door & Weight state

					BUSH_BUTTON_H_GET_VALUE(BUSH_BUTTON_PORTD,BUSH_BUTTON_pin_4,&cancel_check);

					if(!cancel_check)
					{
						T_command='C';
						current_state=6;  //Cancel State
					}
				}
			}

	        /*--- Heating State ----*/
			else if(current_state==4)
			{
				while(Total_seconds > 0)
				{
					current_Temp=LM35_GET_TEMPERATURE(LM35_pin_5);

					if(current_Temp > Target_Temp)
					{
						T_command='A';
						current_state=8;  //Dangerous State
						flag=1;
						break;
					}

					BUSH_BUTTON_H_GET_VALUE(BUSH_BUTTON_PORTD,BUSH_BUTTON_pin_4,&cancel_check);

					if(!cancel_check)
					{
						T_command='C';
						current_state=6;  //Cancel State
						flag=1;
						break;
					}

					minutes = Total_seconds / 60;
					seconds = Total_seconds % 60;

					min_first_digit = minutes % 10;
					sec_first_digit = seconds % 10;
					sec_second_digit = seconds / 10;

					SSD_WRITE_NUM(SSD_PORTA,SSD_LOWER_PIN,min_first_digit);
					for(u8 check_num=0;check_num<=9;check_num++)
					{
						if(sec_second_digit==check_num)
						{
							SSD_WRITE_NUM(SSD_PORTC,SSD_UPPER_PIN,upper_numbers[check_num]);
						}
					}
					SSD_WRITE_NUM(SSD_PORTC,SSD_LOWER_PIN,sec_first_digit);

					_delay_ms(1000);
					Total_seconds--;
				}

				if(!flag)
				{
					T_command='F';
					current_state=7;  //Finish State
				}

			}

	        /*--- Warning State ----*/
			else if(current_state==5)
			{
				current_Temp=LM35_GET_TEMPERATURE(LM35_pin_5);

				if(current_Temp >= TempThreshold)
				{
					T_command='R';
				    current_state=5;  //Warning State
				}
				else
				{
					T_command=0;
					current_state=0;  //Welcome State
				}

			}

	        /*--- Cancel State ----*/
			else if(current_state==6)
			{
				flag=0;
				Total_seconds=0;
				minutes =0;
				seconds =0;
				min_first_digit = minutes % 10;
				sec_first_digit = seconds % 10;
				sec_second_digit = seconds / 10;
				Target_Temp=0;

				SSD_WRITE_NUM(SSD_PORTA,SSD_LOWER_PIN,min_first_digit);
				for(u8 check_num=0;check_num<=9;check_num++)
				{
					if(sec_second_digit==check_num)
					{
						SSD_WRITE_NUM(SSD_PORTC,SSD_UPPER_PIN,upper_numbers[check_num]);
					}
				}
				SSD_WRITE_NUM(SSD_PORTC,SSD_LOWER_PIN,sec_first_digit);

				current_state=0;  //Welcome State
			}

	        /*--- Finish State ----*/
			else if(current_state==7)
			{
				Total_seconds=0;
				minutes =0;
				seconds =0;
				min_first_digit = minutes % 10;
				sec_first_digit = seconds % 10;
				sec_second_digit = seconds / 10;
				Target_Temp=0;

				SSD_WRITE_NUM(SSD_PORTA,SSD_LOWER_PIN,min_first_digit);
				for(u8 check_num=0;check_num<=9;check_num++)
				{
					if(sec_second_digit==check_num)
					{
						SSD_WRITE_NUM(SSD_PORTC,SSD_UPPER_PIN,upper_numbers[check_num]);
					}
				}
				SSD_WRITE_NUM(SSD_PORTC,SSD_LOWER_PIN,sec_first_digit);


				current_Temp=LM35_GET_TEMPERATURE(LM35_pin_5);

				if(current_Temp >= TempThreshold)
				{
				  T_command='R';
				  current_state=5;  //Warning State
				}
				else
				{
					T_command=0;
					current_state=0;  //Welcome State
				}
			}

	        /*--- Alarm State ----*/
			else if(current_state==8)
			{
				flag=0;
				Total_seconds=0;
				minutes =0;
				seconds =0;
				min_first_digit = minutes % 10;
				sec_first_digit = seconds % 10;
				sec_second_digit = seconds / 10;
				Target_Temp=0;

				SSD_WRITE_NUM(SSD_PORTA,SSD_LOWER_PIN,min_first_digit);
				for(u8 check_num=0;check_num<=9;check_num++)
				{
					if(sec_second_digit==check_num)
					{
						SSD_WRITE_NUM(SSD_PORTC,SSD_UPPER_PIN,upper_numbers[check_num]);
					}
				}
				SSD_WRITE_NUM(SSD_PORTC,SSD_LOWER_PIN,sec_first_digit);

				current_Temp=LM35_GET_TEMPERATURE(LM35_pin_5);

				if(current_Temp >= TempThreshold)
				{
					T_command='R';
				  current_state=5;  //warning State
				}
				else
				{
					T_command=0;
					current_state=0;  //Welcome State
				}

			}

			send_command_to_master(T_command);

		}


}
