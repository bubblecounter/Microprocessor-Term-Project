# Temperature Measurement using the TMP101
Digital thermometer using PIC24F Microcontroller and TMP 101 temperature sensor for Microprocessor Based System Design course

# Project Description
The TMP101 by Texas Instruments is a digital temperature sensor circuit with I2C interface.
Figure below shows the placement of the module on the PIC24 board along with the connection diagram.

I wrote a program that will communicate with the TMP101 over the I2C bus, and display the temperature in decimal format on the LCD of the PIC24 board. Program reads 10 bits temperature data so that the display resolution is 0.25◦C.

The main program calls the functioninitTMP101()function for initializing the sensor. The associated code written into the tmp101.c file. Similarly, TMP101readT() used for reading the temperature data. The main program then sends the data to the display in a human readable format.

##### Placement of TMP101 on PIC24 board
![Placement of TMP101 on PIC24 board](https://github.com/bubblecounter/Microprocessor-Term-Project/blob/master/figure.jpg "TMP101 placement")
