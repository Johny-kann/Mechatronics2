/*
 * Proj2.cpp
 *
 * Created: 6/9/2015 8:23:22 PM
 *  Author: User
 */ 

# define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "servo.h"
//#include "LcdCom.h"
//#include "touch_screen.h"
//#include "items.h"
//#include "opertions.h"
//#include "stepper_motor.h"

//TouchScreen touchscreen;

/*void timer1_interrupt_init(unsigned int number)
{
	TCCR1B |= 1<<CS10 | 1<<CS11 | 1<<WGM12;
	TIMSK1 = 1 << OCIE1A;
	OCR1A = number;
	
}*/


int main(void)
{
	/* DDRD |= 0xFF;
	 DDRB |= 0xFF;

	  TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
	  TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)
	  
	  

	  ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).
	  */

	Servo servo;
	servo.initAttachTimer();
	 while (1)
	 {
		 for(int i=0;i<=160;i+=5)
		 {
			servo.setDegree(i);
			_delay_ms(50);
		 }
		
		for(int i=160;i>=0;i-=5)
		{
			servo.setDegree(i);
			_delay_ms(50);
		}
		 servo.setDegree(0);
		 _delay_ms(1000);
		 servo.setDegree(160);
		 _delay_ms(1000);
	 }
}


/*
ISR(TIMER1_COMPA_vect)
{
	touchscreen.setPosX(readX());
	touchscreen.setPosY(readY());
}

*/