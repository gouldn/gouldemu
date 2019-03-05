#include "graphics.h"

int scanlineCounter = 204;
int numInstructions = 0;

void graphicsStep(int cycles) {
  if(LCDEnabled()) {
    scanlineCounter -= cycles;
    numInstructions++;
  } else return;

  if(scanlineCounter <= 0) {
    internal[0xFF44]++;
    printf("Instructions since last scanline: %d\n", numInstructions);
    numInstructions = 0;

    scanlineCounter = 456;
  }
}

int LCDEnabled() {
  return 1;
}
