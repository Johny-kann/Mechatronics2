/*
 * stepper_motor.h
 *
 * Created: 6/11/2015 2:38:51 AM
 *  Author: Janakiraman
 */ 
#include <avr/io.h>

#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

class StepperMotor
{

private:
uint16_t degree;
bool forward;

protected:
	
public:
	StepperMotor();
	void moveForward(int steps,int utime);
	void moveBackward(int steps,int utime);

	
};



#endif /* STEPPER_MOTOR_H_ */