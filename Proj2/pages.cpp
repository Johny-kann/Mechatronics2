/*
 * pages.cpp
 *
 * Created: 6/13/2015 3:18:42 AM
 *  Author: Janakiraman
 */ 
#include "pages.h"
# define F_CPU 16000000L
#include <util/delay.h>
#include "opertions.h"

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
		else if(pageNo== 4)
			this->page4Action(posx,posy);
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
		
		dispPage4();
		this->servo.initAttachTimer();
		_delay_ms(500);
	}
	else if(range(posx,450,100) && range(posy,790,650))
	{
		dispPage2();
		_delay_ms(500);
	}
}

void Pages::page2Action(uint16_t posx,uint16_t posy)
{
	if(range(posx,950,800) && range(posy,950,800))
	{
		this->stepper.setForward();
		dispPage3();
		_delay_ms(500);
		
	}
	else if(range(posx,280,100) && range(posy,950,800))
	{
		
		this->stepper.setReverse();
		dispPage3();
		_delay_ms(500);
		
	}
	else if(range(posx,660,400) && range(posy,790,650))
	{
		dispPage1();
		_delay_ms(500);
		
	}
	
	
}

void Pages::page3Action(uint16_t posx,uint16_t posy)
{
	if(range(posx,370,100) && range(posy,950,800))
	{
		dispPage1();
		_delay_ms(500);
	}
	else if(range(posx,900,130) && range(posy,790,650))
	{
		uint16_t angle = angleConversion(posx,165,870,0,359);
		
		dispPage3();
		
		this->lcd.gotoXY(1,9);
		this->lcd.displayInt(angle);
		_delay_ms(500);
		this->stepper.moveDegree(angle,5000);
		_delay_ms(1000);
	}
}

void Pages::page4Action(uint16_t posx,uint16_t posy)
{
	if(range(posx,370,100) && range(posy,950,800))
	{
		dispPage1();
		_delay_ms(500);
		this->servo.stopTimer();
	}
	else if(range(posx,900,130) && range(posy,790,650))
	{
		
		uint16_t angle = angleConversion(posx,165,870,0,160);
		dispPage4();
		
		this->lcd.gotoXY(1,9);
		
		this->lcd.displayInt(angle);

		_delay_ms(500);
		this->servo.setDegree(angle);
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

	this->lcd.gotoXY(2,10);
	this->lcd.displayString("Stepper");
//	_delay_ms(500);
}

void Pages::dispPage2()
{
	this->pageNo = 2;
	this->lcd.clearDisplay();
	this->lcd.displayString("CW");
	this->lcd.gotoXY(2,7);
	this->lcd.displayString("Home");
	this->lcd.gotoXY(1,14);
	this->lcd.displayString("CCW");
//	_delay_ms(500);

}

void Pages::dispPage4()
{
	this->pageNo = 4;
	this->lcd.clearDisplay();
	this->lcd.displayString("Servo");
	this->lcd.gotoXY(1,13);
	this->lcd.displayString("Home");
	this->lcd.gotoXY(2,1);
	this->lcd.displayString("0 - - -");
	this->lcd.gotoXY(2,9);
	this->lcd.displayString("- - -160");
//	_delay_ms(500);
}

bool Pages::range(int num,int max,int min)
{
	return (num<max && num>min)?true:false;
}



void Pages::dispPage3()
{
	this->pageNo = 3;
	this->lcd.clearDisplay();
	this->lcd.displayString("Stepper");
	this->lcd.gotoXY(1,13);
	this->lcd.displayString("Home");

	this->lcd.gotoXY(2,1);
	this->lcd.displayString("0 - - -");
	this->lcd.gotoXY(2,9);
	this->lcd.displayString("- - -359");
	
}
