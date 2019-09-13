/*
 * example434.c 
 *  Edited version 
 */
#include <ctype.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define YYFLAG 	(-10000000)
#define YYMAXDEPTH 150
#define YYERRCODE 256
#define id 257
#define	YYCONST	const

typedef int yytabelem;
typedef union YYSTYPE {
  int val;
  char *str;
} YYSTYPE;

int yyparse(void);

YYSTYPE yylval;
YYSTYPE yyval;

/* stack and stack values */
int     yy_yys[YYMAXDEPTH], *yys = yy_yys;
YYSTYPE yy_yyv[YYMAXDEPTH], *yyv = yy_yyv;
static int yymaxdepth = YYMAXDEPTH;

int
yylex(void)
{
  int c;
  
  while ((c = getchar()) == ' ' || c == '\t')
    ;
  if (c == EOF)
    return (EOF);

  switch (c) {
  case '\n': case '(': case ')': case '+': case '*':
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

static YYCONST yytabelem yyexca[] ={
  -1, 1,
  0, -1,
  -2, 0,
};

# define YYNPROD 8
# define YYLAST 218
static YYCONST yytabelem yyact[]={
     5,     7,    13,     4,     8,     9,     3,     1,     2,     0,
     0,     0,     0,    12,    10,    11,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     8,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     6
};

static YYCONST yytabelem yypact[] = {
   -40, YYFLAG,    -9,   -37, YYFLAG,   -40, YYFLAG, YYFLAG,
   -40,   -40, -39,   -37, YYFLAG, YYFLAG
};

static YYCONST yytabelem yypgo[] = {
     0,     7,     8,     6,     3
};

static YYCONST yytabelem yyr1[] = {
     0,     1,     2,     2,     3,     3,     4,     4
};

static YYCONST yytabelem yyr2[] = {
     0,     5,     7,     3,     7,     3,     7,     3
};

static YYCONST yytabelem yychk[] = {
  YYFLAG,    -1,    -2,    -3,    -4,    40,   257,    10,
  43,    42, -2,    -3,    -4,    41
};

static YYCONST yytabelem yydef[] = {
     0,    -2,     0,     3,     5,     0,     7,     1,
     0,     0,     0,     2,     4,     6
};

typedef struct yytoktype {
  const char *t_name;
  int t_val;
} yytoktype;


yytoktype yytoks[] = {
	"id",	257,
	"+",	43,
	"*",	42,
	"-unknown-",	-1	/* ends search */
};

const char * yyreds[] = {
	"-no such reduction-",
	"S : E '\n'",
	"E : E '+' T",
	"E : T",
	"T : T '*' F",
	"T : F",
	"F : '(' E ')'",
	"F : id",
};

/*
** yacc user known macros and defines
*/
#define YYACCEPT	return(0)
#define YYABORT		return(1)

#define YYNEW(type)	malloc(sizeof(type) * yynewmax)
#define YYCOPY(to, from, type) \
  (type *) memcpy(to, (char *) from, yymaxdepth * sizeof (type))

/*
** driver internal defines
*/


/*
** global variables used by the parser
*/
YYSTYPE *yypv;			/* top of value stack */
int *yyps;			/* top of state stack */

int yystate;			/* current state */
int yytmp;			/* extra var (lasts between blocks) */

int yynerrs;			/* number of errors */
int yyerrflag;			/* error recovery flag */
int yychar;			/* current input token number */

/*
** yyparse - return 0 if worked, 1 if syntax error not recovered from
*/
int yyparse(void)
{
	YYSTYPE *yypvt = 0;	/* top of value stack for $vars */

	/*
	** Initialize externals - yyparse may be called more than once
	*/
	yypv = &yyv[-1];
	yyps = &yys[-1];
	yystate = 0;
	yytmp = 0;
	yynerrs = 0;
	yyerrflag = 0;
	yychar = -1;
	{
		YYSTYPE *yy_pv;	/* top of value stack */
		int *yy_ps;		/* top of state stack */
		int yy_state;		/* current state */
		int  yy_n;		/* internal state number info */
	fprintf(stderr, "D:00:          yystate = %d, yy_state = %d\n", yystate, yy_state);
	goto yystack;	/* moved from 6 lines above to here to please C++ */

		/*
		** get globals into registers.
		** branch to here only if YYBACKUP was called.
		*/
	yynewstate:
	fprintf(stderr, "D:yynewstate: yystate = %d, yy_state = %d\n", yystate, yy_state);
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;
		goto yy_newstate;

		/*
		** get globals into registers.
		** either we just started, or we just finished a reduction
		*/
	yystack:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;
	fprintf(stderr, "D:01:yystack:  yystate = %d, yy_state = %d\n", yystate, yy_state);

		/*
		** top of for (;;) loop while no reductions done
		*/
	yy_stack:
		/*
		** put a state and value onto the stacks
		*/
        fprintf(stderr, "D:02:yy_stack: yystate = %d, yy_state = %d\n", yystate, yy_state);
		if (++yy_ps >= &yys[yymaxdepth])	/* room on stack? */
		{
		  fprintf(stderr, "DRAGON: STACK OVERFLOW\n");
		  exit(1);
		}
		*yy_ps = yy_state;
		*++yy_pv = yyval;

		/*
		** we have a new state - find out what to do
		*/
	yy_newstate:
		if ((yy_n = yypact[yy_state]) <= YYFLAG)
			goto yydefault;		/* simple state */
		if ((yychar < 0) && ((yychar = yylex()) < 0))
			yychar = 0;		/* reached EOF */
		if (((yy_n += yychar) < 0 ) || (yy_n >= YYLAST))
			goto yydefault;
		if (yychk[yy_n = yyact[yy_n]] == yychar)	/*valid shift*/
		{
			yychar = -1;
			yyval = yylval;
			yy_state = yy_n;
			if ( yyerrflag > 0 )
				yyerrflag--;
			goto yy_stack;
		}

	yydefault:
		if ((yy_n = yydef[yy_state]) == -2)
		{
			if ((yychar < 0) && ((yychar = yylex()) < 0 ))
				yychar = 0;		/* reached EOF */

			/*
			** look through exception table
			*/
			{
				YYCONST int *yyxi = yyexca;

				while ((*yyxi != -1) ||
				       (yyxi[1] != yy_state))
				  yyxi += 2;
				while ((*(yyxi += 2) >= 0) &&
				       (*yyxi != yychar))
				  ;
				if ((yy_n = yyxi[1]) < 0)
				  YYACCEPT;
			}
		}

		/*
		** check for syntax error
		*/
		if (yy_n == 0)	/* have an error */
		{
   		  switch (yyerrflag) {
       		  case 0:    /* new error */
		  case 1:
		  case 2:    /* incompletely recovered error */
		    fprintf(stderr,  "syntax error" );
       		    YYABORT;
		  case 3:	   /* no shift yet; eat a token */
		    if (yychar == 0)	/* reached EOF. quit */
		      YYABORT;
		    yychar = -1;
		    goto yy_newstate;
		  }
		}/* end if ( yy_n == 0 ) */
		
		/*
		** reduction by production yy_n
		** put stack tops, etc. so things right after switch
		*/
		
		fprintf(stderr, "D:GOING To consult parsing tables\n");
	
		yytmp = yy_n;			/* value to switch over */
		yypvt = yy_pv;			/* $vars top of value stack */
		/*
		** Look in goto table for next state
		** Sorry about using yy_state here as temporary
		** register variable, but why not, if it works...
		** If yyr2[ yy_n ] doesn't have the low order bit
		** set, then there is no action to be done for
		** this reduction.  So, no saving & unsaving of
		** registers done.  The only difference between the
		** code just after the if and the body of the if is
		** the goto yy_stack in the body.  This way the test
		** can be made before the choice of what to do is needed.
		*/
		{
		  /* length of production doubled with extra bit */
		  int yy_len = yyr2[yy_n];

		  if (!(yy_len & 01)) {
		    yy_len >>= 1;
		    yyval = (yy_pv -= yy_len)[1]; /* $$ = $1 */
		    yy_state = yypgo[yy_n = yyr1[yy_n]] +
		      *(yy_ps -= yy_len) + 1;
		    if (yy_state >= YYLAST ||
			yychk[yy_state = yyact[yy_state]] != -yy_n)
		      yy_state = yyact[yypgo[yy_n]];
		    goto yy_stack;
		  }
		  
		  yy_len >>= 1;
		  yyval = (yy_pv -= yy_len)[1];	/* $$ = $1 */
		  yy_state = yypgo[yy_n = yyr1[yy_n]] +
		    *(yy_ps -= yy_len) + 1;
		  if (yy_state >= YYLAST ||
		      yychk[yy_state = yyact[yy_state]] != -yy_n)
		    yy_state = yyact[ yypgo[ yy_n ]];
		}
		/* save until reenter driver code */
		yystate = yy_state;
		yyps = yy_ps;
		yypv = yy_pv;
	}
	
	/*
	** code supplied by user is placed in this switch
	*/
	switch(yytmp) {
	case 1: 
	    yyval.val = yypvt[-1].val;
	    printf("\tval = %d\n", yyval.val);
	    return (0);
	case 2:
	  yyval.val = yypvt[-2].val + yypvt[-0].val;
	  break;
	case 3:
	  yyval.val = yypvt[-0].val;
	  break;
	case 4:
	  yyval.val = yypvt[-2].val * yypvt[-0].val;
	  break;
	case 5:
	  yyval.val = yypvt[-0].val;
	  break;
	case 6:
	  yyval.val = yypvt[-1].val;
	  break;
	case 7:
	  yyval.val = yypvt[-0].val;
	  break;
	}
	goto yystack;		/* reset registers in driver code */
}
