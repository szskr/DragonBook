#
# Simple makefile
#
CFLAGS += -DDEBUG
PROG = example434
OBJS = example434.o

example434 : $(OBJS)
	cc $(OBJS) -o $(PROG)

$(OBJS) : example434.y
	yacc -dv example434.y
	mv y.tab.c example434.c
	cc -c $(CFLAGS) example434.c

clean:
	rm -f $(OBJS) $(PROG) y.tab.h y.output example434.c
