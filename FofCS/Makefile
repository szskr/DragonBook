#
#
#
HDRS = fcs.h
LIBOBJS = 02.02.o
PROGS= prog.0203

all: $(PROGS)

02.02.o: 02.02.c $(HDRS)
	$(CC) -c $(CFLAGS) 02.02.c

prog.0203: prog.0203.o $(LIBOBJS)
	$(CC) -o prog.0203 prog.0203.o $(LIBOBJS)

clean:
	rm -f *.o $(PROGS)
