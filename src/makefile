IDIR =../include
CC=gcc
CFLAGS=-I $(IDIR) -lSDL2

ODIR=obj
LDIR =../lib

_DEPS = registers.h types.h cpu.h memory.h graphics.h window.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = registers.o cpu.o memory.o graphics.o window.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

../emu: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
