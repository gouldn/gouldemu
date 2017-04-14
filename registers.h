#include "types.h"

struct registers {
	struct {
		union {
			struct {
				BYTE f;
				BYTE a;
			};
			WORD af;
		};
	};
	
	struct {
		union {
			struct {
				BYTE c;
				BYTE b;
			};
			WORD bc;
		};
	};
	
	struct {
		union {
			struct {
				BYTE e;
				BYTE d;
			};
			WORD de;
		};
	};
	
	struct {
		union {
			struct {
				BYTE l;
				BYTE h;
			};
			WORD hl;
		};
	};
	
	WORD sp;
	WORD pc;
	BYTE ie;
} extern registers;