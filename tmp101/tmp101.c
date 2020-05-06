//EE 308 Lab 4 (Project)
//Modified by A.Furkan Okuyucu 19736

#include <p24FJ256GB110.h>
#include "tmp101.h"
#include "i2c.h"
#include <xc.h>
#include <libpic30.h>

void initTMP101(void)
{
	I2Cstart();
	I2Cwrite(I2CaddrW);
	I2Cwrite(0x01); // make pointer to point configuration register
	I2Cwrite(0x20); // 00100000  resolution is 10 bit ; shutdown , os alert, faltquee bits are set to zero
	I2Cstop();
}

int TMP101readT(void)
{
	I2Cstart();
	I2Cwrite(I2CaddrW);//slave address for write
	I2Cwrite(0x00); // make pointer to point temperature register
	
	I2Crestart(); // restart to ic2 connection to read operation
	I2Cwrite(I2CaddrR); //slave address for read
	unsigned char temperature0 = I2Cread();//upper part of temperature
	I2Cack(); 
	unsigned char temperature1 = I2Cread();//decimal part of temperature
	I2Cack();
	I2Cstop();

	int retVal = 0;
	int decimal = 0;
	retVal = temperature0; // upper part of temperature
	decimal = temperature1;// decimal part of temperature
	\
	if (decimal == 192)//0.75
	{
		decimal = 75;
	}
	else if (decimal == 128) // 0.50
	{
		decimal = 50;
	}
	else if (decimal == 64) // 0.25
	{
		decimal = 25;
	}
	else
	{
		decimal = 0;
	}
	retVal = retVal * 100;
	retVal = retVal + decimal;
	return(retVal);
}
