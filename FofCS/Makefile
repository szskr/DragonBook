#
#
#
HDRS = fcs.h
LIBOBJS = Ch02.o Ch05.o fcsTools.o
PROGS= prog.0203 prog.0501
TESTS= t.0201 t.0501

all: $(PROGS) $(LIBOBJS)

prog.0203: prog.0203.o $(LIBOBJS)
	$(CC) -o prog.0203 prog.0203.o $(LIBOBJS)

prog.0501: prog.0501.o $(LIBOBJS)
	$(CC) -o prog.0501 prog.0501.o $(LIBOBJS)

#
# Tests
#
test.0201: test.0201.o $(LIBOBJS)
	$(CC) -o test.0201 test.0201.o $(LIBOBJS)

tests: $(TESTS)

t.0201: test.0201
	echo "test.0201"
	test.0201

t.0501: prog.0501
	echo "TEST-0501"
	echo "5 1 5 3 2 4" | prog.0501

clean:
	rm -f *.o $(PROGS) $(TESTS)

#
#
#
%.o: %.c $(HDRS)
	$(CC) -c $(CFLAGS) -o $@ $<
