/*
 * Grammar 4.34 (page 222 (4.19))
 */

%token  id
%left '+' 

%%
S : E '\n'
  ;

E : E '+' F
  | F
  ;

F : '(' E ')' 
  | id 
  ;

%%
