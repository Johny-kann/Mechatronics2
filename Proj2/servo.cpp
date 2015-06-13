/*
 * servo.cpp
 *
 * Created: 6/12/2015 6:46:46 PM
 *  Author: Janakiraman
 */ 
#include "servo.h"
#include <stdlib.h>


void Servo::setDegree(uint16_t degree)
{
	this->degree = degree;
	
	OCR1A = (int)(500/160)*this->degree+150;
}

uint16_t Servo::getDegree()
{
	return this->degree;
}

void Servo::stopTimer()
{
	TCCR1B |= (1<<CS10|1<<CS11|1<<CS12);
	TCCR1A |= (1<<COM1A0|1<<COM1A1|1<<COM1B0|1<<COM1B1);
}

void Servo::initAttachTimer()
{
	DDRB |= 1<<DDB1;
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)
	
	ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).
	
	setDegree(0);
}

