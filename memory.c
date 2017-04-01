
#include <stdio.h>
#include "memory.h"

unsigned char cartridge[0x8000];
unsigned char internalRAM[0x2000];

unsigned char writeByte(unsigned short address, unsigned char value) {
	if(address >= 0xC000 && address <= 0xE000) {
		return internalRAM[address - 0xC000];
	}

	printf("Problem writing to memory\n");
	return 0;
}