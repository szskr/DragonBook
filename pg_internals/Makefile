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

CSRC=		y1.c y2.c y3.c y4.c
OBJS=           y1.o y2.o y3.o y4.o
PROG=		dyacc
CFLAGS=         -I./h

$(PROG): $(OBJS)
	$(CC) -o $(PROG)  $(OBJS)

clean:
	rm -f $(PROG) $(OBJS)
