/*
 * pages.h
 *
 * Created: 6/13/2015 3:18:21 AM
 *  Author: Janakiraman
 */ 

#include <avr/io.h>
#ifndef PAGES_H_
#define PAGES_H_
#include "models.h"

class Pages
{
private:
	uint16_t pageNo;
	LcdDisplay lcd;
	bool range(int num,int max,int min);

public:	
	Pages();
	void chooseAction(uint16_t posx,uint16_t posy);
	void introPage();
	void dispPage1();
	void dispPage2();
	void dispPage3();
	void page1Action(uint16_t posx,uint16_t posy);
	void page2Action(uint16_t posx,uint16_t posy);
	void page3Action(uint16_t posx,uint16_t posy);
	
	
};

#endif /* PAGES_H_ */