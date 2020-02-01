#
#
#
CFLAGS= -c
FILES= malloc.c
OBJS= malloc.o
ARCHIVE=unix.a

all: unix

malloc.o: malloc.c
	$(CC) $(CFLAGS) malloc.c

unix: $(OBJS)
	rm -f $(ARCHIVE)
	ar cr $(ARCHIVE) $(OBJS)

clean:
	rm -f *.o $(ARCHIVE)
