/*
 * Dragon Yacc Supplementary functions.
 */
#include "dragon.h"

#define PUT_SPACE() {\
  int i = 0;\
  for (i = 0; i < indent_level; i++)\
    fputc(' ', stderr), fputc (' ', stderr);\
  }

static int indent_level = 0;
static unsigned char tflag = 0;

/*
 * tracer routines
 */

void
in_func()
{
  indent_level++;
}

void
out_func()
{
  indent_level--;
}

int
d_indent_level()
{
  return (indent_level);
}

void
d_printf(char *format, ...)
{
  va_list arg;
  
  if (tflag == 0)
    return;
  
  va_start (arg, format);
  vfprintf(stderr, format, arg);
  va_end (arg);
}

void
d_tflag(unsigned char flg)
{
  tflag = flg;
}

void
d_trace(char *s)
{
  if (tflag == 0)
    return;

  PUT_SPACE();
  fprintf(stderr, "TRACE: %s\n", s);
}

/*
 * stub function for gettext()
 */
char *
gettext(char *s)
{
  return (s);
}
