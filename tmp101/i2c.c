#include <p24FJ256GB110.h>
#include "i2c.h"
#include <xc.h>
#include <libpic30.h>

void initI2C(void)
{
	I2C1BRG = 0x27;				// set BAUD rate
	I2C1CONbits.A10M = 0;		// 7-bit slave address
	I2C1CONbits.I2CEN = 1;		// enable I2C module #1
}

void I2Cstart(void)
{
	I2C1CONbits.SEN = 1;		// start condition
	while(I2C1CONbits.SEN){}	// wait while start condition in progress
}

void I2Cstop(void)
{
	I2C1CONbits.PEN = 1;		// stop condition
	while(I2C1CONbits.PEN){}	// wait while stop condition in progress
}

void I2Crestart(void)
{
	I2C1CONbits.RSEN = 1;		// restart condition
	while(I2C1CONbits.RSEN){}	// wait while restart condition in progress
}

unsigned char I2Cwrite(unsigned int c)
{
	I2C1TRN = c;
	while(I2C1STATbits.TBF){}	// wait write
	while(I2C1STATbits.TRSTAT){}	// wait slave ack	
	return(I2C1STATbits.ACKSTAT ? 0 : 1);	// not acknowledge = 0, acknowledge = 1
}

unsigned char I2Cread(void)
{
	//unsigned int c;
	I2C1CONbits.RCEN = 1;		// master receive enable
	while(I2C1CONbits.RCEN){}	// wait read
	return(I2C1RCV);
	//c = I2C1RCV;
	//return(c);
}

void I2Cack(void)
{
	I2C1CONbits.ACKDT = 0;		// ACK bit 0
	I2C1CONbits.ACKEN = 1;		// send ACK
	while(I2C1CONbits.ACKEN){}	// wait_ack
}

void I2Cnack(void)
{
	I2C1CONbits.ACKDT = 1;		// ACK bit 1
	I2C1CONbits.ACKEN = 1;		// send ACK
	while(I2C1CONbits.ACKEN){}	// wait_ack
}

