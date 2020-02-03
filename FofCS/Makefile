#
#
#
HDRS = fcs.h
LIBOBJS = Ch02.o fcsTools.o
PROGS= prog.0203
TESTS= test.0201

all: $(PROGS) $(LIBOBJS) $(TESTS)

Ch02.o: Ch02.c $(HDRS)
	$(CC) -c $(CFLAGS) Ch02.c

fcsTools.o: fcsTools.c $(HDRS)
	$(CC) -c $(CFLAGS) fcsTools.c

prog.0203: prog.0203.o $(LIBOBJS)
	$(CC) -o prog.0203 prog.0203.o $(LIBOBJS)

test.0201: test.0201.o $(LIBOBJS)
	$(CC) -o test.0201 test.0201.o $(LIBOBJS)


clean:
	rm -f *.o $(PROGS)
