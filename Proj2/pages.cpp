/*
 * pages.cpp
 *
 * Created: 6/13/2015 3:18:42 AM
 *  Author: Janakiraman
 */ 
#include "pages.h"
# define F_CPU 16000000L
#include <util/delay.h>

void Pages::chooseAction(uint16_t posx,uint16_t posy)
{
	if(this->range(posx,950,5) && range(posy,950,5))
	{
		if(pageNo == 1)
			this->page1Action(posx,posy);
		else if(pageNo == 2)
			this->page2Action(posx,posy);
		else if(pageNo == 3)
			this->page3Action(posx,posy);
	}
}

void Pages::introPage()
{
	lcd.clearDisplay();
	lcd.gotoXY(1,4)	;
	lcd.displayString("Welcome to ");
	lcd.gotoXY(2,4)	;
	lcd.displayString("Johny's Proj");
	_delay_ms(2000);
	this->dispPage1();
}

void Pages::page1Action(uint16_t posx,uint16_t posy)
{
	if(range(posx,950,560) && range(posy,950,800))
	{
		dispPage3();
	}
	else if(range(posx,450,100) && range(posy,790,700))
	{
		dispPage2();
	}
}

void Pages::page2Action(uint16_t posx,uint16_t posy)
{
	if(range(posx,950,800) && range(posy,950,800))
	{
	//	dispPage2();
	}
	else if(range(posx,280,100) && range(posy,950,800))
	{
	//	dispPage3();
	}
	else if(range(posx,660,400) && range(posy,950,800))
	{
		dispPage1();
		
	}
	else if(range(posx,900,130) && range(posy,790,700))
	{
		//	dispPage3();
	}
	
}

void Pages::page3Action(uint16_t posx,uint16_t posy)
{
	if(range(posx,950,590) && range(posy,950,800))
	{
		//	dispPage2();
	}
	else if(range(posx,370,100) && range(posy,950,800))
	{
		dispPage1();
	}
	else if(range(posx,900,130) && range(posy,790,700))
	{
		//	dispPage3();
	}
}

 Pages::Pages()
{
	this->lcd.init_lcd();
	this->lcd.clearDisplay();
}

void Pages::dispPage1()
{	
	this->pageNo = 1;
	this->lcd.clearDisplay();
	this->lcd.displayString("Servo");
//	this->lcd.gotoXY(1,10);
//	this->lcd.displayString("Home");
	this->lcd.gotoXY(2,10);
	this->lcd.displayString("Stepper");
}

void Pages::dispPage2()
{
	this->pageNo = 2;
	this->lcd.clearDisplay();
	this->lcd.displayString("CW");
	this->lcd.gotoXY(1,7);
	this->lcd.displayString("Home");
	this->lcd.gotoXY(1,14);
	this->lcd.displayString("CCW");
	this->lcd.gotoXY(2,1);
	this->lcd.displayString("0 - - -");
	this->lcd.gotoXY(2,9);
	this->lcd.displayString("- - -360");
}

void Pages::dispPage3()
{
	this->pageNo = 3;
	this->lcd.clearDisplay();
	this->lcd.displayString("Servo");
	this->lcd.gotoXY(1,13);
	this->lcd.displayString("Home");
	this->lcd.gotoXY(2,1);
	this->lcd.displayString("0 - - -");
	this->lcd.gotoXY(2,9);
	this->lcd.displayString("- - -160");
}

bool Pages::range(int num,int max,int min)
{
	return (num<max && num>min)?true:false;
}
