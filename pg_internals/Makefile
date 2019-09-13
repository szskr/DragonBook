#
# 2019/09 szskr
#

CSRC=		y1.c y2.c y3.c y4.c dragon.c
OBJS=           y1.o y2.o y3.o y4.o dragon.o
CMMNTDF=		example434.READ.c
DYACC=		dyacc
DTYACC=         dtyacc
EXMPL434=       example434
CMMNTD434=	cmmntd434
SGRAMMAR=	sgrammar.c
CFLAGS=         -I./h -DDRAGON

GFILES= y.output y.tab.c y.tab.h example434.c y.tab.o\
	example434.output sgrammar.output sgrammar.c
DFILES= $(OBJS) $(DYACC) $(DTYACC) $(EXMPL434) $(GFILES) $(CMMNTD434)

all: $(DYACC) $(EXMPL434) $(SGRAMMAR) $(CMMNTD434)

$(DYACC): $(OBJS)
	$(CC) -o $(DYACC)  $(OBJS)
	ln -s $(DYACC) $(DTYACC)

$(EXMPL434): example434.y $(DYACC)
	./$(DYACC) -dv example434.y
	mv y.tab.c example434.c
	mv y.output example434.output
	$(CC) example434.c -o $(EXMPL434)

$(SGRAMMAR): sgrammar.y $(DYACC)
	./$(DYACC) -dv sgrammar.y
	mv y.tab.c sgrammar.c
	mv y.output sgrammar.output

$(CMMNTD434): $(CMMNTDF)
	$(CC) $(CMMNTDF) -o $(CMMNTD434)
	echo "(1+2)+3+4*5" | ./$(CMMNTD434)

clean:
	rm -f $(DFILES)
