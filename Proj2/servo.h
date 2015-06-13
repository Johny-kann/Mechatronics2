/*
 * servo.h
 *
 * Created: 6/12/2015 6:46:30 PM
 *  Author: User
 */ 


#ifndef SERVO_H_
#define SERVO_H_
#include <avr/io.h>

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

#endif /* SERVO_H_ */