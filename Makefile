CC = sdcc
CFLAGS = -mstm8 --std-sdcc99 --opt-code-size
INCLUDES = -I../stm8-header/


FLASHER = ../stm8flash

SOURCES = main.c
OBJS = $(SOURCES:%.c=%.rel)


all: compile

compile: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)



%.rel: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $<


flash:
	$(FLASHER) -c stlinkv2 -p stm8s105c6 -w main.ihx

clean:
	rm -f *.asm *.cdb *.map *.lk *.rst *.lst *.ihx *.rel *.sym
