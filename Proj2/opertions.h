/*
 * opertions.h
 *
 * Created: 6/10/2015 7:17:37 PM
 *  Author: Janakiraman
 */ 


#ifndef OPERTIONS_H_
#define OPERTIONS_H_
#include <avr/io.h>
//#include "items.h"

void timer1_interrupt_init(unsigned int number);

void timer0_interrupt_init();

void adc_init();

uint16_t adc_read(uint8_t ch);

uint16_t readX();

uint16_t readY();

uint16_t angleConversion(uint16_t touchPoint,uint16_t minTouch,uint16_t maxTouch,uint16_t minAngle,uint16_t maxAngle);

uint16_t stepss(int angle);

#endif /* OPERTIONS_H_ */




