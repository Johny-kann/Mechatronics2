/*
 * Proj2.cpp
 *
 * Created: 6/9/2015 8:23:22 PM
 *  Author: User
 */ 

# define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "LcdCom.h"

int main(void)
{
	
//	USART_Init(MYUBRR);
//	USART_Sendbyte(0xFE);
//	USART_Sendbyte(0x01);
	LcdDisplay lcd;
	lcd.init_lcd();
	lcd.clearDisplay();
//	int i = 1;
	
    while(1)
    {
		
        //TODO:: Please write your application code 
	//	USART_Send_int(i);
	lcd.displayString("Hello");
		_delay_ms(2000);
		lcd.blinkCursor();
		_delay_ms(1000);
		lcd.clearDisplay();
		lcd.displayString("Moving right 3");
		_delay_ms(1000);
		lcd.moveRightTimes(3);
		_delay_ms(1000);
		lcd.clearDisplay();
		lcd.displayString("Going 2,3");
		_delay_ms(1000);
		lcd.gotoXY(2,3);
		lcd.displayString("Hai");
		_delay_ms(1000);
		
    }
}