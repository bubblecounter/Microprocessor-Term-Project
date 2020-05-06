//EE 308 Lab 4 (Project)
//Modified by A.Furkan Okuyucu 19736

#include <p24FJ256GB110.h>

#include "ee308.h"
#include "tmp101.h"
#include <xc.h>
#include <libpic30.h>
#include <stdio.h>

#include "config.h"

static volatile unsigned char LCD_data[2][16] = {"PIC24 Board v2.0", "Temp : + 00.00 C"};
volatile unsigned int LCD_ptr=0, LCD_cmd=0x00C0, LCD_line=0;
const unsigned char LookUp[16] = "0123456789ABCDEF";

#include "isr.c"

main()
{
	initKeypad();
	initLCD();
	initLED();
	initTimer1();
	initTimer2();
	initI2C();
	initTMP101();// initialize sensor
	
	while(1)
	{
		int x = TMP101readT(); //get the temperature in "abcd" format if temperature is "ab.cd" Celcius
		char str[4] = "";

		sprintf(str, "%d", x); //convert int to char array and store in str

		LCD_data[1][9] = str[0]; //tens position
		LCD_data[1][10] = str[1]; // ones position
		LCD_data[1][12] = str[2]; //tenths position
		LCD_data[1][13] = str[3];//hundredths position
		
		__delay_ms(500);
		PORTFbits.RF0 = 1;
		
		__delay_ms(500);
		PORTFbits.RF0 = 0; 
	}
}




