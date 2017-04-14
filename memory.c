#include <stdio.h>
#include "memory.h"

BYTE cartridge[0x20000];
BYTE internal[0x10000];

unsigned char writeByte(WORD address, BYTE value) {
	if(address >= 0xC000 && address <= 0xE000) {
		return internal[address];
	}

	printf("Problem writing to memory\n");
	return 0;
}