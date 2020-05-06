TARGET_CHIP := 24FJ256GB110
TARGET_FAMILY := PIC24F

XC16DIR := 'C:\Program Files (x86)\Microchip\xc16\v1.33'
SUPPORTFILESDIR := ..\support-files

RM := del

CFLAGS := -mcpu=$(TARGET_CHIP) # -mno-eds-warn -no-legacy-libc

LDSCRIPT := $(XC16DIR)\support\$(TARGET_FAMILY)\gld\p$(TARGET_CHIP).gld
#LDFLAGS := --local-stack -p$(TARGET_CHIP) --script $(LDSCRIPT) --heap=512 -L$(XC16DIR)/lib -L$(XC16DIR)/lib/$(TARGET_FAMILY)
LDFLAGS := --script $(LDSCRIPT) -L$(XC16DIR)/lib -L$(XC16DIR)/lib/$(TARGET_FAMILY)
LIBS := -lc -lpic30 -lm # -lpPIC24Fxxx-elf # List any other library you need here (order matters)

.DEFAULT_GOAL := all
.PHONY: all clean
OBJS := main.o ee308.o i2c.o tmp101.o

all: result.hex

# Rule to compile C source files (using the official C compiler)
%.o: %.c
	$(XC16DIR)\bin\xc16-gcc $(CFLAGS) -c $< -o $@

# Rule to link together object files created through distinct compiler invocations
result.elf: $(OBJS)
	$(XC16DIR)\bin\xc16-ld $(LDFLAGS) $^ $(LIBS) -o $@

# Rule to convert the resulting ELF file into a HEX file
result.hex: result.elf
	$(XC16DIR)\bin\xc16-bin2hex $<

clean:
	$(RM) *.elf *.hex $(OBJS) 2>NUL
