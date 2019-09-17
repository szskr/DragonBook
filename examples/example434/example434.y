/*
 * Grammar 4.34 (page 222 (4.19))
 */

%{
#include <ctype.h>
#include <stdio.h>
int yylex(void);
void yyerror (char const *);
%}

%union {
  int val;
  char *str;
}

%token <val> id
%type <val> S
%type <val> E
%type <val> T
%type <val> F
%left '+' 
%left '*'

%%
S : E '\n' { $$ = $1;
    printf("\tval = %d\n", $$);
    return (0);
  }
  ;

E : E '+' T {$$ = $1 + $3;}
  | T       {$$ = $1;}
  ;

T : T '*' F {$$ = $1 * $3;}
  | F       {$$ = $1;}
  ;

F : '(' E ')' {$$ = $2;}
  | id        {$$ = $1;}
  ;

%%
void
yyerror(char const *s)
{
  fprintf(stderr, "%s\n", s);
}

int
yylex(void)
{
  int c;
  
  while ((c = getchar()) == ' ' || c == '\t')
    ;
  if (c == EOF)
    return (EOF);

  switch (c) {
  case '\n': case '(': case ')':
  case '+': case '*':
    return (c);
  }
  
  if (isdigit(c)) {
    yylval.val = c - '0';
    return (id);
  }

  return (c);
}

int
main(int argc, char *argv[])
{
  int ret = 0;
  while (ret == 0)
    ret = yyparse();
}
