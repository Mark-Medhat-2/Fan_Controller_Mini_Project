/*
 * Fan_Controller.c
 *
 *  Created on: Oct 12, 2021
 *      Author: marcm
 */

#include "lcd.h"
#include "lm35_sensor.h"
#include "Motor_driver.h"
#include <avr/io.h>
uint8 Temp_value;
int main(void){

	LCD_init();
	LM35_init( INTERNAL , Prescaler_8);
	LCD_displayString("FAN is");
	LCD_displayStringRowColumn(1,0,"Temp =");
	DcMotor_Init();
	while(1){
		Temp_value=	LM35_getTemperature();
			if (Temp_value<30){
				LCD_displayStringRowColumn(0,7,"OFF");
			}
			else if (Temp_value>30){
				LCD_displayStringRowColumn(0,7,"ON ");
			}
			LCD_moveCursor(1,7);
			LCD_intgerToString(Temp_value);
			if(Temp_value<=99){
				LCD_displayStringRowColumn(1,9," ");
			}
			if(Temp_value<=9){
				LCD_displayStringRowColumn(1,8," ");
				}
			if(Temp_value<30){
				DcMotor_Rotate(STOP, 0);
			}
			if (Temp_value>30 && Temp_value<60){
				DcMotor_Rotate(CW, 25);
			}
			if (Temp_value>60 && Temp_value<90){
				DcMotor_Rotate(CW, 50);
			}
			if (Temp_value>90 && Temp_value<120){
				DcMotor_Rotate(CW, 75);
				}
			if (Temp_value>120){
				DcMotor_Rotate(CW, 100);
				}
	}
}
