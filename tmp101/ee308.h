//_CONFIG1( FWDTEN_OFF & JTAGEN_OFF )

#define FOSC    (4000000ULL)
#define FCY     (FOSC/2)
#define _ISR_PSV __attribute__((interrupt, auto_psv))
#define _ISR_NO_PSV __attribute__((interrupt, no_auto_psv))

void initKeypad(void);
void initLCD(void);
void initLED(void);
void sendcomm(unsigned int cmd);
//void senddata(unsigned int cmd);
void initTimer1(void);
void initTimer2(void);

// #define _XTAL_FREQ 8000000

//void _ISR _T1Interrupt( void)
