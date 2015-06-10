#include "LcdCom.h"
#include "uart.h"

/*
 * lcdCom.cpp
 *
 * Created: 6/9/2015 8:48:01 PM
 *  Author: Janakiraman
 */ 

void LcdDisplay::init_lcd()
{
	USART_Init(MYUBRR);
}

void LcdDisplay::clearDisplay()
{
	USART_Sendbyte(0xFE);
	USART_Sendbyte(0x01);
}

void LcdDisplay::displayString(const char *str)
{
	USART_Send_string(str);
}

void LcdDisplay::displayInt(int num)
{
	USART_Send_int(num);
}

void LcdDisplay::blinkCursor()
{
		USART_Sendbyte(0xFE);
		USART_Sendbyte(0x0D);
}

void LcdDisplay::moveLeftTimes(unsigned int i)
{
	while(i-->0)
	{
		
		USART_Sendbyte(0xFE);
		USART_Sendbyte(0x18);
	}
}

void LcdDisplay::moveRightTimes(unsigned int i)
{
	while(i-->0)
	{
		
		USART_Sendbyte(0xFE);
		USART_Sendbyte(0x1C);
	}
}

void LcdDisplay::cursorLeftTimes(unsigned int i)
{
	while(i-->0)
	{
		
		USART_Sendbyte(0xFE);
		USART_Sendbyte(0x10);
	}
}

void LcdDisplay::cursorRightTimes(unsigned int i)
{
	while(i-->0)
	{
		
		USART_Sendbyte(0xFE);
		USART_Sendbyte(0x1C);
	}
}

void LcdDisplay::gotoXY(unsigned char row, unsigned int col)
{
	USART_Sendbyte(0xFE);
	if(row==1)
	{
		USART_Sendbyte(0+(col-1)+128);
	}else if(row==2)
	{
		USART_Sendbyte(64+(col-1)+128);
	}
}
