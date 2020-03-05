#
#
#
HDRS = fcs.h
LIBOBJS = Ch02.o Ch05.o fcsTools.o
PROGS= prog.0203
TESTS= test.0201

all: $(PROGS) $(LIBOBJS) $(TESTS)

prog.0203: prog.0203.o $(LIBOBJS)
	$(CC) -o prog.0203 prog.0203.o $(LIBOBJS)

test.0201: test.0201.o $(LIBOBJS)
	$(CC) -o test.0201 test.0201.o $(LIBOBJS)

test: test.0201
	echo "test.0201"
	test.0201

clean:
	rm -f *.o $(PROGS)

#
#
#
%.o: %.c $(HDRS)
	$(CC) -c $(CFLAGS) -o $@ $<
