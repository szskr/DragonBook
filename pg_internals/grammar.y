/*
 * Grammar 4.34 (page 222 (4.19))
 */

%token  id
%left '+' 
%left '*'

%%
S : E '\n'
  ;

E : E '+' T
  | T 
  ;

T : T '*' F 
  | F  
  ;

F : '(' E ')' 
  | id 
  ;

%%
