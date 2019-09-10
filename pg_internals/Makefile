#
# CDDL HEADER START
#
# The contents of this file are subject to the terms of the
# Common Development and Distribution License, Version 1.0 only
# (the "License").  You may not use this file except in compliance
# with the License.
#
# You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
# or http://www.opensolaris.org/os/licensing.
# See the License for the specific language governing permissions
# and limitations under the License.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file at usr/src/OPENSOLARIS.LICENSE.
# If applicable, add the following below this CDDL HEADER, with the
# fields enclosed by brackets "[]" replaced with your own identifying
# information: Portions Copyright [yyyy] [name of copyright owner]
#
# CDDL HEADER END
#
#
#ident	"%Z%%M%	%I%	%E% SMI"
#
# Copyright (c) 1995,1997 by Sun Microsystems, Inc.
# All Rights Reserved.
#
# cmd/sgs/yacc/Makefile
#

#
# 2019/09 szskr
#

CSRC=		y1.c y2.c y3.c y4.c dragon.c
OBJS=           y1.o y2.o y3.o y4.o dragon.o
DYACC=		dyacc
EXMPL434=       example434
SGRAMMAR=	sgrammar.c
CFLAGS=         -I./h -DDRAGON

GFILES= y.output y.tab.c y.tab.h example434.c y.tab.o\
	example434.output sgrammar.output sgrammar.c
DFILES= $(OBJS) $(DYACC) $(EXMPL434) $(GFILES)

all: $(DYACC) $(EXMPL434) $(SGRAMMAR)

$(DYACC): $(OBJS)
	$(CC) -o $(DYACC)  $(OBJS)

$(EXMPL434): example434.y $(DYACC)
	./$(DYACC) -dv example434.y
	mv y.tab.c example434.c
	mv y.output example434.output
	$(CC) example434.c -o $(EXMPL434)

$(SGRAMMAR): sgrammar.y $(DYACC)
	./$(DYACC) -dv sgrammar.y
	mv y.tab.c sgrammar.c
	mv y.output sgrammar.output

clean:
	rm -f $(DFILES)
