#include <stdio.h>
#include "types.h"

extern unsigned char cartridge[0x20000];
extern unsigned char internal[0x10000];

BYTE writeByte(WORD address, BYTE value);
BYTE readByte(WORD address);
void initMemory(char** argv);
//BYTE* grabVRAM();
