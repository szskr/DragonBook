#
#
#
HDR = pcon.h

PROGS = rec\
	alds1_1_d alds1_1_a alds2_1_a alds1_2_b alds1_2_c alds1_2_d\
	alds1_3_a alds1_3_b alds1_3_c alds1_3_d \
	alds1_4_a alds1_4_b alds1_4_c alds1_4_d \
	alds1_5_a

TESTS= test_0 \
	test_alds1_1_d test_alds1_1_a test_alds2_1_a test_alds1_2_b test_alds1_2_c test_alds1_2_d\
	test_alds1_3_a test_alds1_3_b test_alds1_3_c \
	test_alds1_4_a test_alds1_4_b test_alds1_4_c test_alds1_4_d\
	test_alds1_5_a

LIBS= algorithms.o

all: $(PROGS) $(LIBS)

$(PROGS): $(LIBS)

rec: rec.o
	$(CC) -o rec rec.o $(LIBS)

alds1_1_d: alds1_1_d.o
	$(CC) -o alds1_1_d alds1_1_d.o $(LIBS)

alds1_1_a: alds1_1_a.o
	$(CC) -o alds1_1_a alds1_1_a.o $(LIBS)

alds2_1_a: alds2_1_a.o
	$(CC) -o alds2_1_a alds2_1_a.o $(LIBS)

alds1_2_b: alds1_2_b.o
	$(CC) -o alds1_2_b alds1_2_b.o $(LIBS)

alds1_2_c: alds1_2_c.o
	$(CC) -o alds1_2_c alds1_2_c.o $(LIBS)

alds1_2_d: alds1_2_d.o
	$(CC) -o alds1_2_d alds1_2_d.o $(LIBS)

alds1_3_a: alds1_3_a.o
	$(CC) -o alds1_3_a alds1_3_a.o $(LIBS)

alds1_3_b: alds1_3_b.o
	$(CC) -o alds1_3_b alds1_3_b.o $(LIBS)

alds1_3_c: alds1_3_c.o
	$(CC) -o alds1_3_c alds1_3_c.o $(LIBS)

alds1_3_d: alds1_3_d.o
	$(CC) -o alds1_3_d alds1_3_d.o $(LIBS)

alds1_4_a: alds1_4_a.o
	$(CC) -o alds1_4_a alds1_4_a.o $(LIBS)

alds1_4_b: alds1_4_b.o
	$(CC) -o alds1_4_b alds1_4_b.o $(LIBS)

alds1_4_c: alds1_4_c.o
	$(CC) -o alds1_4_c alds1_4_c.o $(LIBS)

alds1_4_d: alds1_4_d.o
	$(CC) -o alds1_4_d alds1_4_d.o $(LIBS)

alds1_5_a: alds1_5_a.o
	$(CC) -o alds1_5_a alds1_5_a.o $(LIBS)


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

test_alds1_2_d: alds1_2_d
	@echo ""
	echo 5 5 1 4 3 2 | alds1_2_d

test_alds1_3_a: alds1_3_a
	@echo ""
	echo "1 2 + 10 *" | alds1_3_a

test_alds1_3_b: alds1_3_b
	@echo ""
	echo "5 100 p1 150 p2 80 p3 200 p4 350 p5 20" | alds1_3_b

test_alds1_3_c: alds1_3_c
	@echo ""
	alds1_3_c

test_alds1_4_a: alds1_4_a
	@echo ""
	echo "5 1 2 3 4 5 3 3 4 1" | alds1_4_a

test_alds1_4_b: alds1_4_b
	@echo ""
	echo "5 1 2 3 4 5 3 3 4 1" | alds1_4_b

test_alds1_4_c: alds1_4_c
	@echo ""
	echo "6 insert AAA insert AAC find AAA find $(CC)C insert $(CC)C find $(CC)C" | alds1_4_c

test_alds1_4_d: alds1_4_d
	@echo ""
	echo "5 3 8 1 7 3 9" | alds1_4_d

test_alds1_5_a: alds1_5_a
	@echo ""
	echo "5  1 5 7 10 21 4 2 4 17 8" | alds1_5_a

#
# Macros
#
%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) -o $@ $<
