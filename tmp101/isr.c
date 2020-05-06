void _ISR_NO_PSV _T1Interrupt(void)
{
	if(LCD_ptr==16) {
		PORTBbits.RB15 = 0;		// send command
		PORTE = LCD_cmd;
		PORTDbits.RD4 = 1;
		PORTDbits.RD4 = 1;
		PORTDbits.RD4 = 0;
		LCD_ptr = 0;
		LCD_line = (LCD_line ^ 0x0001);
		LCD_cmd = (LCD_cmd ^ 0x0040);
	}
	else {
		PORTBbits.RB15 = 1;		// send data
		PORTE = LCD_data[LCD_line][LCD_ptr];
		PORTDbits.RD4 = 1;
		PORTDbits.RD4 = 1;
		PORTDbits.RD4 = 0;
		LCD_ptr++;
	}
	
	_T1IF = 0;
} //T1Interrupt
