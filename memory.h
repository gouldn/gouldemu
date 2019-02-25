#include <stdio.h>
#include "types.h"

extern unsigned char cartridge[0x20000];
extern unsigned char internal[0x10000];

unsigned char writeByte(WORD address, BYTE value);
void loadROM(FILE *f);