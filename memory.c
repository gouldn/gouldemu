#include <stdlib.h>
#include <string.h>
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

void loadROM(FILE *f) {

	memset(cartridge, 0, sizeof(cartridge));

	fread(cartridge, 1, sizeof(cartridge), f);

	fclose(f);

}