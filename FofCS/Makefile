#
#
#
HDRS = fcs.h
LIBOBJS = Ch02.o
PROGS= prog.0203

all: $(PROGS)

Ch02.o: Ch02.c $(HDRS)
	$(CC) -c $(CFLAGS) Ch02.c

prog.0203: prog.0203.o $(LIBOBJS)
	$(CC) -o prog.0203 prog.0203.o $(LIBOBJS)

clean:
	rm -f *.o $(PROGS)
