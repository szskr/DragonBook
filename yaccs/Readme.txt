#
# Readme.txt
#

0. Introduction
The purpose of this directory is to explore the internals of parser generators.
The generators to study are yacc and clyacc.

1. Files
The following files are taken from OpenSolaris_b135,
most of them from usr/src/cmd/sgs/yacc.

    Makefile
    dextern
    yaccpar
    
    y1.c
    y2.c
    y3.c
    y4.c
    
    h/values.h
    h/isa_defs.h
    h/malloc.h

They are modified as needed so yacc could be built on MacOS 10.15 Beta.
Most of i18n supports are removed for simplicity.
