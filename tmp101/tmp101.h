#define	I2CaddrW							0x90
#define I2CaddrR							0x91
#define RegisterValues						0x20
#define TEMPERATURE_REGISTER				0x00
#define CONFIGURATION_REGISTER				0x01
#define TEMPERATURELIMIT_LOW_REGISTER		0x02
#define TEMPERATURELIMIT_HIGH_REGISTER		0x03
#define RESOLUTION_REGISTER_VALUE			0x20
#define RESOLUTION_CALCULATION_VALUE		0.25		// 10 Bits = 0.25 C / tick
#define SHUTDOWN_ON							0x01
#define SHUTDOWN_OFF						0x00
#define DEFAULT_POLARITY_BIT				0x00
#define THERMOSTAT_STARTUP_BIT				0x00

void initTMP101(void);
int  TMP101readT(void);
void SetLowTempLimit(int value);