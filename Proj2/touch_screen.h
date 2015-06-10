/*
 * touch_screen.h
 *
 * Created: 6/10/2015 6:58:02 PM
 *  Author: Janakiraman
 */ 


#ifndef TOUCH_SCREEN_H_
#define TOUCH_SCREEN_H_
#include <avr/io.h>

class TouchScreen
{
	
	
public:
	void init();
	uint16_t getPosX();
	uint16_t getPosY();
	void setPosX(uint16_t x);
	void setPosY(uint16_t y);
	
protected:

private:
	uint16_t posX,posY;
	void adc_init();

};



#endif /* TOUCH_SCREEN_H_ */