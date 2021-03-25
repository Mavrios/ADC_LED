/*
 * main.c
 *
 *  Created on: Jan 29, 2021
 *      Author: Kishk
 *
 */

#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATHS.h"
#include "util/delay.h"
#include "../MCAL/01-DIO/DIO_interface.h"
#include "../MCAL/04- ADC/ADC_interface.h"
#include "../HAL/04- CLCD/CLCD_interface.h"



int main(void) {
	ADC_voidInit();
	u16 LOC_u16Result =0;
	DIO_enumSetPinDirection(DIO_PORTB_PIN0,DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTB_PIN1,DIO_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTB_PIN2,DIO_OUTPUT);

	while (1) {
		LOC_u16Result = ((u32)ADC_u16GETChannelResult(ADC_ADC0_PORTA_PIN0)*5000)/1023;
		if(LOC_u16Result >= 0 && LOC_u16Result < 1500 ){
			DIO_enumSetPinValue(DIO_PORTB_PIN0 , DIO_HIGH);
			DIO_enumSetPinValue(DIO_PORTB_PIN1 , DIO_LOW);
			DIO_enumSetPinValue(DIO_PORTB_PIN2 , DIO_LOW);
		}
		else if(LOC_u16Result >= 1500 && LOC_u16Result < 3000 ){
			DIO_enumSetPinValue(DIO_PORTB_PIN0 , DIO_LOW);
			DIO_enumSetPinValue(DIO_PORTB_PIN1 , DIO_HIGH);
			DIO_enumSetPinValue(DIO_PORTB_PIN2 , DIO_LOW);
		}
		else if(LOC_u16Result >= 3000 && LOC_u16Result <= 5000 ){
			DIO_enumSetPinValue(DIO_PORTB_PIN0 , DIO_LOW);
			DIO_enumSetPinValue(DIO_PORTB_PIN1 , DIO_LOW);
			DIO_enumSetPinValue(DIO_PORTB_PIN2 , DIO_HIGH);
		}
		_delay_ms(300);
	}

}

