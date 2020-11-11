%{
  #include<stdio.h>
  #include<stdlib.h>
  int yylex(void);
  int yyerror(const char *s);
  int success = 1;
%}

%token NUM ID SWITCH CASE BREAK DEFAULT OP
%left '+' '-'  
%left '*''/'  
%right '^'  
%right '='  
%nonassoc UMINUS  

%%

S             : SWITCH '(' EXPR ')' '{' BODY  '}'
              ;
BODY          : BODY BODY
              | CASE EXPR ':' STMTS
              | CASE EXPR ':' STMTS BREAK ';'
              | CASE EXPR ':' STMTS BREAK ';' DEFAULT ':' STMTS
              ;
STMTS         : EXPR';'
              |
              ;
EXPR          : EXPR OP EXPR
              | ID
              | NUM
              |
              ;

%%

int main (void) {
    yyparse();
    if(success)
    	printf("Parsing Successful\n");
    return 0;
}

int yyerror(const char *msg) {
	printf("Parsing Failed\nLine Number: %d %s\n", yylval, msg);
  success = 0;
	return 0;
}