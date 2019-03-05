#include <stdlib.h>
#include <string.h>
#include "memory.h"

BYTE cartridge[0x20000];
BYTE internal[0x10000];

BYTE writeByte(WORD address, BYTE value) {
	if(address >= 0xC000 && address <= 0xE000) {
		return internal[address];
	}

	internal[address] = value;
	return internal[address];
}

BYTE readByte(WORD address) {
	return internal[address];
}

void initMemory(char** argv) {
	FILE* f = fopen(argv[1], "rb");

	memset(cartridge, 0, sizeof(cartridge));
	fread(cartridge, 1, sizeof(cartridge), f);
	fclose(f);
}

// BYTE* grabVRAM() {
// 	int arraySize = 0x97FF - 0x8000;
// 	BYTE* subset = malloc((arraySize)*sizeof(BYTE));
// 	for(int i = 0; i < arraySize; i++) {
// 		subset[i] = cartridge[0x8000 + i];
// 		printf("Byte 1: %02X\n", cartridge[0x8000 + i]);
// 		getchar();
// 	}
//
// 	return subset;
// }
