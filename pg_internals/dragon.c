/*
 * Dragon Yacc Supplementary functions.
 */
#include <stdio.h>
#include "dragon.h"

static int indent_level = 0;

/*
 * tracer
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

void
d_trace(char *s)
{
  int i = 0;
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
