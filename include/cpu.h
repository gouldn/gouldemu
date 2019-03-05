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
	void *execute;
} extern const instructions[256];



BYTE cpuStep(void);
void initCpu();

void undefined(void);
void xor(BYTE operand);
BYTE dec(BYTE operand);
void nop(void);
void jp(WORD operand);
void jr_nz_n(BYTE operand);
void xor_a(void);
void ldhl_nn(WORD operand);
void ldc_n(BYTE operand);
void ldb_n(BYTE operand);
void lda_n(BYTE operand);
void ldd_phl_a(void);
void ldFF00_a(BYTE operand);
void lda_FF00(BYTE operand);
void dec_b(void);
void dec_c(void);
void cp_n(BYTE operand);
void di(void);
