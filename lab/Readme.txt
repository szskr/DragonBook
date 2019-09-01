#
# LALR(1)
#

example434.y
 yacc version
 % make
 % ./example434
 1+2
     val= 3
 1 + 2 * 3
     val = 7
 
example434.lisp
 clyacc version
 % clisp
 > (load "./yacc.lisp")
 > (load "./example434.lisp")
 > (example434:example434)
 ? 1+2
  ==> 3
 ? 1 + 2 * 3
  ==> 7
  
