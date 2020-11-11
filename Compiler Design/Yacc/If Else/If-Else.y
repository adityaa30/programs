%{
  #include<stdio.h>
  #include<stdlib.h>
  int yylex(void);
  int yyerror(const char *s);
  int success = 1;
%}

%token NUM ID LT GT EQ LE GE NE AND OR INC DEC END  
%left '+' '-'  
%left '*''/'  
%right '^'  
%right '='  
%nonassoc UMINUS  
%nonassoc IF  
%nonassoc ELSE  
%left GE NE LT GT LE EQ  
%left AND OR  

%%

S       : IF '(' F ')' '{' S '}' %prec IF  
        | IF '(' F ')' '{' S '}' ELSE '{' S '}'  
        | E ';'  
        | E ';' S
        ;  
F       : C LO C  
        | C
        ;  
LO      : AND  
        | OR
        ;
C       : E RELOP E  
        | E
        ;
E       : ID '=' E  
        | E '+' E   
        | E '-' E   
        | E '*' E   
        | E '/' E  
        | E '^' E  
        | '(' E ')'   
        | '-' E %prec UMINUS  
        | ID  
        | NUM  
        | ID INC  
        | ID DEC  
        ;
RELOP   :LT  
        | GT  
        | EQ  
        | LE  
        | GE  
        | NE  
        ;

%%

int main (void) {
  yyparse();
  if(success) printf("Parsing Successful\n");
  return 0;
}

int yyerror(const char *msg) {
  printf("Parsing Failed\nLine Number: %d %s\n", yylval, msg);
  success = 0;
  return 0;
}