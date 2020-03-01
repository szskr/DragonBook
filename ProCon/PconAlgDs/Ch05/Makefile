#
#
#
HDR = pcon.h

PROGS = 

TESTS= 

LIBS= 

all: $(PROGS) $(LIBS)

clean:
	rm -f *.o $(PROGS)

#
# tests
#
tests: $(TESTS)

#
# Macros
#
%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) -o $@ $<
