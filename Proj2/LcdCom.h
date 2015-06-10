/*
 * LcdCom.h
 *
 * Created: 6/9/2015 8:47:24 PM
 *  Author: Janakiraman
 */ 


#ifndef LCDCOM_H_
#define LCDCOM_H_


class LcdDisplay
{

private:

public:	

void init_lcd();

void clearDisplay();

void displayString(const char *str);

void displayInt(int num);

void blinkCursor();

void moveLeftTimes(unsigned int i);

void moveRightTimes(unsigned int i);

void cursorLeftTimes(unsigned int i);

void cursorRightTimes(unsigned int i);

void gotoXY(unsigned char row, unsigned int col);
	};


#endif /* LCDCOM_H_ */