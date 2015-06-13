/*
 * touch_screen.cpp
 *
 * Created: 6/10/2015 6:58:22 PM
 *  Author: Janakiraman
 */ 

#include "touch_screen.h"
#include "opertions.h"

/*void TouchScreen::adc_init()
{
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2) | (1<<ADEN);	
}*/

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
