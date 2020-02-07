#
#
#
HDR = pcon.h
PROGS = alds1_1_d alds1_1_a alds2_1_a alds1_2_b alds1_2_c
TESTS= test_0 \
	test_alds1_1_d test_alds1_1_a test_alds2_1_a test_alds1_2_b test_alds1_2_c
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

alds1_2_c: alds1_2_c.o
	cc -o alds1_2_c alds1_2_c.o $(LIBS)

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

test_alds1_2_b: alds1_2_b
	@echo ""
	echo 1 1 | alds1_2_b
	echo 2 1 2 | alds1_2_b
	echo 2 2 1 | alds1_2_b
	echo 6 5 6 4 2 1 3 | alds1_2_b

test_alds1_2_c: alds1_2_c
	@echo ""
	echo 5 h4 c9 s4 d2 c3 | alds1_2_c
	echo 3 a1 b2 c3 | alds1_2_c

#x
# Macros
#
%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) -o $@ $<
