/*
 * Dragon Yacc Supplementary functions.
 */
#include "dragon.h"

static int indent_level = 0;
static unsigned int t_flag = 0;

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
  
  if (t_flag == 0)
    return;
  
  va_start (arg, format);
  vfprintf(stderr, format, arg);
  va_end (arg);
}

void
d_trace_on()
{
  t_flag = 0x01;
}

void
d_trace(char *s)
{
  int i = 0;

  if (t_flag == 0)
    return;
  
  for (i = 0; i < indent_level; i++)
    fputc(' ', stderr), fputc (' ', stderr);
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
