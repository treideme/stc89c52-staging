###############################################################################
#                                                                             #
# STC89C52 Hello World Project                                                   #
# -------------------------                                                   #
###############################################################################

## Tool configuration
CC=sdcc
LD=sdcc
OC=objcopy
SZ=size

CSRC=$(wildcard *.c)
OBJ=$(CSRC:.c=.rel)
INCLUDE=-I. -I../include

CFLAGS=-mmcs51 --model-small --Werror --opt-code-size

all: app.bin
	

app.bin: app.hex
	$(OC) --input-target=ihex --output-target=binary $< $@
	$(SZ) $<

app.hex: $(OBJ)
	$(LD) -I. -I../include $(CFLAGS) -o $@ $^

%.rel: %.c
	$(CC) -I. -I../include $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.asm *.ihx *.lk *.lst *.bin *.map *.mem *.rel *.rst *.sym *.hex
