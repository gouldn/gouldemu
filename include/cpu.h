#include "types.h"

#define FLAGZ (1 << 7)
#define FLAGN (1 << 6)
#define FLAGH (1 << 5)
#define FLAGC (1 << 4)

#define ISSET(x) (registers.f & (x))
#define SET(x) (registers.f |= (x))
#define CLEAR(x) (registers.f &= ~(x))
#define SUBHALFCARRY(x, y) (((x & 0xF) + -(y & 0xF)) & 0x10)

struct instruction {
	char *disassembly;
	BYTE operandLength;
	BYTE ticks;
	int *execute;
} extern const instructions[256];



BYTE cpuStep(void);
void initCpu();

// Macro functions
void xor(BYTE operand);
BYTE dec(BYTE operand);

int undefined(void);
int nop(void);
int jp(WORD operand);
int jr_nz_n(BYTE operand);
int xor_a(void);
int ldhl_nn(WORD operand);
int ldc_n(BYTE operand);
int ldb_n(BYTE operand);
int lda_n(BYTE operand);
int ldd_phl_a(void);
int ldFF00_a(BYTE operand);
int lda_FF00(BYTE operand);
int dec_b(void);
int dec_c(void);
int cp_n(BYTE operand);
int di(void);
