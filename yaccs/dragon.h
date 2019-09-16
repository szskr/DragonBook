/*
 * DragonBook
 */
#include <stdio.h>
#include <stdarg.h>

#define TFLG_OFF 0x00
#define TFLG_ON  0x01

void in_func();
void out_func();
void d_tflag(unsigned char);
int d_indent_level();
void d_trace(char *s);
void d_printf(char *format, ...);

/*
 * stub routines
 */
char *gettext(char *s);
