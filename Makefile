CC = sdcc
CFLAGS = -mstm8 --std-c99

FLASHER = ../stm8flash

SOURCES = main.c

all: compile

compile:
	$(CC) $(CFLAGS) $(SOURCES)
flash:
	$(FLASHER) -c stlinkv2 -p stm8s105c6 -w main.ihx
clean:
	rm *.asm *.cdb *.map *.lk *.rst *.lst *.ihx *.rel *.sym
