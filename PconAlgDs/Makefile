#
#
#
HDR = pcon.h
PROGS = alds1_1_d alds1_1_a alds2_1_a alds1_2_b
TESTS= test_0 \
	test_alds1_1_d test_alds1_1_a test_alds2_1_a test_alds1_2_b
LIBS=

all: $(PROGS)

alds1_1_d: alds1_1_d.o
	cc -o alds1_1_d alds1_1_d.o $(LIBS)

alds1_1_a: alds1_1_a.o
	cc -o alds1_1_a alds1_1_a.o $(LIBS)

alds2_1_a: alds2_1_a.o
	cc -o alds2_1_a alds2_1_a.o $(LIBS)

alds1_2_b: alds1_2_b.o
	cc -o alds1_2_b alds1_2_b.o $(LIBS)

clean:
	rm -f *.o $(PROGS)

#
# tests
#
tests: $(TESTS)

test_0:
	@echo "TESTING starts here"
	@echo ""

test_alds1_1_d: alds1_1_d
	echo 2 1 10 | alds1_1_d
	@echo "  should be 9\n"
	echo 6 10 1 100 20 1000 30 | alds1_1_d
	@echo "  should be 999\n"

test_alds1_1_a: alds1_1_a
	echo 1 1  | alds1_1_a
	@echo ""
	echo 2 2 1 | alds1_1_a
	@echo ""
	echo 6 5 2 4 6 1 3 | alds1_1_a

test_alds2_1_a: alds2_1_a
	@echo ""
	echo 1 1  | alds2_1_a
	@echo ""
	echo 2 2 1 | alds2_1_a
	@echo ""
	echo 6 5 2 4 6 1 3 | alds2_1_a

#
# Macros
#
%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) -o $@ $<
