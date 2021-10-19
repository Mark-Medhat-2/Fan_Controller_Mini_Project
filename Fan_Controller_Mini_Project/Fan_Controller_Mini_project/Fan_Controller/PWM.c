/*
 * PWM.c
 *
 *  Created on: Oct 15, 2021
 *      Author: marcm
 */

#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the IO Ports Registers */
#include "gpio.h"
#include "PWM.h"
void PWM_Timer0_Start(uint8 duty_cycle){
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);/*set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.*/
	TCNT0 = 0;			/*Set Timer Initial value*/
	OCR0  = duty_cycle*255/100;    /* Set Compare Value*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
