/*
 * touch_screen.h
 *
 * Created: 6/10/2015 6:58:02 PM
 *  Author: Janakiraman
 */ 


#ifndef MODELS_H_
#define MODELS_H_
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
//	void adc_init();

};


class Servo
{
	private:
	uint16_t degree;
	
	public:
	void initAttachTimer();
	void setDegree(uint16_t degree);
	uint16_t getDegree();
	void stopTimer();
};


class StepperMotor
{

	private:
	int degree;
	bool forward;

	protected:
	
	public:
	StepperMotor();
	void setForward();
	void setReverse();
	void moveDegree(int degree,int utime);
	void move(int steps,int utime);
	void moveForward(int steps,int utime);
	void moveBackward(int steps,int utime);

	
};


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


#endif /* TOUCH_SCREEN_H_ */