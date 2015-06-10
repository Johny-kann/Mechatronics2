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

void adc_init();

uint16_t adc_read(uint8_t ch);

uint16_t readX();

uint16_t readY();



#endif /* OPERTIONS_H_ */