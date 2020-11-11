%{
  #include<stdio.h>
%}

%token NUMBER
%left '|'
%left '^'
%left '&'
%left '(' ')'


%%

statement   :      expression             { printf("= %d\n", $1); }
            ;

expression  :      expression '&' expression       { $$ = $1 & $3; }
            |      expression '|' expression       { $$ = $1 | $3; }
            |      expression '^' expression       { $$ = $1 ^ $3; }
            |      '(' expression ')'              { $$ = $2; } 
            |      NUMBER                          { $$ = $1; }
            ;

%%

main() {
  yyparse();
  return 0;
}

yyerror() {
  printf("Invalid Input!\n");
}