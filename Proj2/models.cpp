/*
 * touch_screen.cpp
 *
 * Created: 6/10/2015 6:58:22 PM
 *  Author: Janakiraman
 */ 
# define F_CPU 16000000L
#include <stdlib.h>
#include <util/delay.h>
#include "models.h"
#include "opertions.h"
#include "uart.h"


/*void TouchScreen::adc_init()
{
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2) | (1<<ADEN);	
}*/
//---------------------------Touch Screen-----------------

void TouchScreen::init()
{
	adc_init();
}

uint16_t TouchScreen::getPosX()
{
	return this->posX;
}

uint16_t TouchScreen::getPosY()
{
	return this->posY;
}

void TouchScreen::setPosX(uint16_t x)
{
	this->posX = x;
}

void TouchScreen::setPosY(uint16_t y)
{
	this->posY = y;
}

//--------------------Servo--------------------------

void Servo::setDegree(uint16_t degree)
{
	this->degree = degree;
	
	OCR1A = (int)(330*this->degree/140)+140;
}

uint16_t Servo::getDegree()
{
	return this->degree;
}

void Servo::stopTimer()
{
	TCCR1B &= ~(1<<CS10|1<<CS11|1<<CS12);
	TCCR1A &= ~(1<<COM1A0|1<<COM1A1|1<<COM1B0|1<<COM1B1);
}

void Servo::initAttachTimer()
{
	DDRB |= 1<<DDB1;
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)
	
	ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).
	
	this->setDegree(0);
}

//--------------------------------Stepper Motor---------------

void StepperMotor::moveForward(int steps,int utime)
{
//	this->forward = true;
	
	PORTD &= ~(1<<DDD2);
	
	for(int i=0 ; i<steps ; i++)
	{
		_delay_us(5000);
		PORTD |= (1<<DDD4);
		_delay_us(5000);
		PORTD &= ~(1<<DDD4);
	}
	this->degree+=steps;
	
}

void StepperMotor::moveBackward(int steps,int utime)
{
//	this->forward = false;
	
	PORTD |= (1<<DDD2);
	
	for(int i=0 ; i<steps ; i++)
	{
		_delay_us(5000);
		PORTD |= (1<<DDD4);
		_delay_us(5000);
		PORTD &= ~(1<<DDD4);
		//	_delay_us(utime);
	}
	this->degree-=steps;
}

StepperMotor::StepperMotor()
{
	this->degree = 0;
	this->forward = true;
	DDRD |= (1<<DDD2 | 1<<DDD4);
	PORTD &= ~(1<<DDD2|1<<DDD4);
}

void StepperMotor::move(int steps,int utime)
{
	if(this->forward)
		moveForward(steps,utime);
	else
		moveBackward(steps,utime);
}

void StepperMotor::moveDegree(int degree,int utime)
{
	int moveDeg;
	
	if(this->forward)
	{
		moveDeg = this->degree - degree;
		
		if(moveDeg < 0)
			moveDeg += 360;
		
	}else
	{
		moveDeg = degree - this->degree;
		
		if(moveDeg < 0)	
			moveDeg+=360;
	}
	
//	float steps = ((float)moveDeg)*200/360;
	this->degree = degree;
	
	this->move((moveDeg*200)/360 , utime);
	
	
	
	
}

void StepperMotor::setForward()
{
	this->forward = true;	
}

void StepperMotor::setReverse()
{
	this->forward = false;	
}

//---------------------------LCD Screen------------------

void LcdDisplay::init_lcd()
{
	USART_Init(MYUBRR);
}

void LcdDisplay::clearDisplay()
{
	USART_Sendbyte(0xFE);
	USART_Sendbyte(0x01);
}

void LcdDisplay::displayString(const char *str)
{
	USART_Send_string(str);
}

void LcdDisplay::displayInt(int num)
{
	USART_Send_int(num);
}

void LcdDisplay::blinkCursor()
{
	USART_Sendbyte(0xFE);
	USART_Sendbyte(0x0D);
}

void LcdDisplay::moveLeftTimes(unsigned int i)
{
	while(i-->0)
	{
		
		USART_Sendbyte(0xFE);
		USART_Sendbyte(0x18);
	}
}

void LcdDisplay::moveRightTimes(unsigned int i)
{
	while(i-->0)
	{
		
		USART_Sendbyte(0xFE);
		USART_Sendbyte(0x1C);
	}
}

void LcdDisplay::cursorLeftTimes(unsigned int i)
{
	while(i-->0)
	{
		
		USART_Sendbyte(0xFE);
		USART_Sendbyte(0x10);
	}
}

void LcdDisplay::cursorRightTimes(unsigned int i)
{
	while(i-->0)
	{
		
		USART_Sendbyte(0xFE);
		USART_Sendbyte(0x1C);
	}
}

void LcdDisplay::gotoXY(unsigned char row, unsigned int col)
{
	USART_Sendbyte(0xFE);
	if(row==1)
	{
		USART_Sendbyte(0+(col-1)+128);
	}else if(row==2)
	{
		USART_Sendbyte(64+(col-1)+128);
	}
}
