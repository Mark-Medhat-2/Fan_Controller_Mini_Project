 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "lm35_sensor.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
void LM35_init(ADC_ReferenceVolatge  ref,ADC_Prescaler pre){
	ADC_ConfigType Config;
	Config.ref_volt =ref;
	Config.prescaler=pre;
	ADC_ConfigType *ptr= &Config ;
	ADC_init(ptr);
}

uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_HALF_VCC_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

