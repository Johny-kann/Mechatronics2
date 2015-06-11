/*
 * Proj2.cpp
 *
 * Created: 6/9/2015 8:23:22 PM
 *  Author: User
 */ 

# define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "LcdCom.h"
#include "touch_screen.h"
//#include "items.h"
#include "opertions.h"
#include "stepper_motor.h"

TouchScreen touchscreen;


int main(void)
{
	
//	USART_Init(MYUBRR);
//	USART_Sendbyte(0xFE);
//	USART_Sendbyte(0x01);
//	LcdDisplay lcd;
//	lcd.init_lcd();
//	lcd.clearDisplay();
//	int i = 1;

//	DDRC &= ~(0<<DDC1);
	
//	uint16_t adc_result ;
	sei();
	
	StepperMotor stepMotor;
	
//	touchscreen.init();
	
//	touchScreen.init();
//	timer1_interrupt_init(50000);
	
	
//	adc_init();
	
	
		
    while(1)
    {
	//	adc_result = adc_read(1);
//	USART_Send_string(" X: ");
//	USART_Send_int(touchscreen.getPosX());
//	USART_Send_string(" Y: ");
//	USART_Send_int(touchscreen.getPosY());
//	_delay_ms(1000);
	stepMotor.moveForward(360,2);
	_delay_ms(500);
	stepMotor.moveBackward(150,3);
		
    }
}

ISR(TIMER1_COMPA_vect)
{
	touchscreen.setPosX(readX());
	touchscreen.setPosY(readY());
}