/*
 * DragonBook
 */
#include <stdio.h>
#include <stdarg.h>

void in_func();
void out_func();
void d_trace_on();
int d_indent_level();
void d_trace(char *s);
void d_printf(char *format, ...);

/*
 * stub routines
 */
char *gettext(char *s);
