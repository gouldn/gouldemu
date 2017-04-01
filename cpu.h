
#define FLAGZ (1 << 7)
#define FLAGN (1 << 6)
#define FLAGH (1 << 5)
#define FLAGC (1 << 4)

#define ISSET(x) (registers.f & (x))
#define SET(x) (registers.f |= (x))
#define CLEAR(x) (registers.f &= ~(x))

struct instruction {
	char *disassembly;
	unsigned char operandLength;
	unsigned char ticks;
	void *execute;
	//unsigned char ticks;
} extern const instructions[256];

void undefined(void);
void xor(unsigned char operand);
void dec(unsigned char operand);
void nop(void);
void jp(unsigned short operand);
void jr_nz_n(unsigned char operand);
void xor_a(void);
void ldhl_nn(unsigned short operand);
void ldc_n(unsigned char operand);
void ldb_n(unsigned char operand);
void lda_n(unsigned char operand);
void ldd_phl_a(void);
void dec_b(void);
void dec_c(void);
void di(void);