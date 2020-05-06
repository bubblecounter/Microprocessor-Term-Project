#include <p24FJ256GB110.h>
#include "ee308.h"
#include <xc.h>
#include <libpic30.h>

void initKeypad(void)
{
	TRISD = TRISD|0x004F;
}

void initLED(void)
{
	TRISF = 0xFFF0;
	LATF = LATF&0xFFF0;		// all LEDs of	
}

void initLCD(void)
{
	TRISBbits.TRISB15 = 0;
	PORTDbits.RD4 = 0;		// make sure LCD is disabled before port is set to output mode
	TRISDbits.TRISD4 = 0;
	TRISDbits.TRISD5 = 0;
	TRISE = 0xFF00;

	PORTDbits.RD5 = 0;		// select LCD WR mode

	sendcomm(0x0038);			// init LCD
	__delay_ms(60);
	sendcomm(0x000E);			// LCD on, cursor on
	__delay_ms(20);
	sendcomm(0x0001);			// clear LCD
	__delay_ms(20);
}

void sendcomm(unsigned int cmd)
{
	PORTBbits.RB15 = 0;		// select LCD command register 
	PORTE	= cmd; 				// output command
	PORTDbits.RD4 = 1;
	__delay_ms(10);
	PORTDbits.RD4 = 0;
	__delay_ms(10);
}

//void senddata(unsigned int cmd)
//{
//	PORTBbits.RB15 = 1;		// select LCD data register 
//	PORTE	= cmd; 				// output command
//	PORTDbits.RD4 = 1;
//	__delay_ms(10);
//	PORTDbits.RD4 = 0;
//	__delay_ms(10);
//}


void initTimer1(void)
{
	//_T1IP = 4;	// set Timer1 priority, (4 is the default value)
	TMR1	= 0x0000;
	PR1	= 0x0040;
	T1CONbits.TCKPS0 = 1;
	T1CONbits.TCKPS1 = 1;	// prescaler set to 256
	_T1IF = 0;
	_T1IE = 1;
	T1CONbits.TON = 1;
}

void initTimer2(void)
{
	TMR2	= 0x0000;
	PR2	= 31249;
	T2CONbits.TCKPS0 = 0;
	T2CONbits.TCKPS1 = 1;	// prescaler set to 64
	T2CONbits.TON = 1;
}



