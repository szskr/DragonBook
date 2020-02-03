#
#
#
HDR = pcon.h
PROGS = alds1_1_d
TESTS= test_alds1_1_d
LIBS=

all: $(PROGS)

alds1_1_d: alds1_1_d.o
	cc -o alds1_1_d alds1_1_d.o $(LIBS)

alds1_1_d.o: alds1_1_d.c $(HDR)
	cc -c $(CFLAGS) alds1_1_d.c

clean:
	rm -f *.o $(PROGS)

#
# tests
#
tests: $(TESTS)

test_alds1_1_d: alds1_1_d
	echo 2 1 10 | alds1_1_d
	@echo "  should be 9\n"
	echo 6 10 1 100 20 1000 30 | alds1_1_d
	@echo "  should be 999\n"
