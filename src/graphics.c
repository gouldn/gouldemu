#include "graphics.h"

int scanlineCounter = 456;

void graphicsStep(int cycles) {
  if(LCDEnabled()) {
    scanlineCounter -= cycles;
  } else return;

  int mode = GetLCDMode();

  if(scanlineCounter <= 0) {
    internal[0xFF44]++;

    scanlineCounter = 456;
  }
}

int LCDEnabled() {
  return 1;
}
