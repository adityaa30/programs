%{
  #include<stdio.h>
  int yylex(void);
  int yyerror(const char *s);
%}

%token EMAIL

%%

statement: EMAIL { 
    printf("Valid Email!\n"); 
    return 0;
  };

%%

int main(void) {
  yyparse();
  return 0;
}

int yyerror(const char *s) {
  printf("Invalid Email!\n");
  return 0;
}