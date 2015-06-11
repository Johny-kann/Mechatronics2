# define F_CPU 16000000L
#include "stepper_motor.h"

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/*
 * stepper_motor.cpp
 *
 * Created: 6/11/2015 2:39:08 AM
 *  Author: Janakiraman
 */ 

void StepperMotor::moveForward(int steps,int utime)
{
	this->forward = true;
	
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
	this->forward = false;
	
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
