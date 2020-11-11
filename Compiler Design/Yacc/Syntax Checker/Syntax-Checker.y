%{
    #include<stdio.h>
    int yylex(void);
    int yyerror(const char *s);
    int success = 1;
%}

%start Program
%token IFTOK ELSETOK ID NUM WHILETOK DOTOK BREAKTOK TYPE VOIDTOK RETURNTOK NULLTOK
%token DEQ NEQ LE GE
%nonassoc ELSETOK
%left '+' '-'
%left '*' '/'
%%

Program    : Functions
           ;
Functions  : Functions Function
           |
           ;
Block      : '{' Decls Stmts '}'
           ;
Decls      : Decls Decl
           |
           ;
Decl       : Type ID ';'
           ;
Type       : Type '[' NUM ']'
           | TYPE
           ;
Stmts      : Stmts Stmt
           |
           ;
Stmt       : Loc '=' Bool ';'
           | IFTOK '(' Bool ')' Stmt ELSETOK Stmt
           | WHILETOK '(' Bool ')' Stmt
           | DOTOK Stmt WHILETOK '(' Bool ')' ';'
           | BREAKTOK ';'
           | RETURNTOK ';'
           | RETURNTOK NUM ';'
           | Func_call
           | Block
           ;
Function   : TYPE ID '(' Param_list ')' Block
           | VOIDTOK ID '(' Param_list ')' Block
           ;
Param_list : Param_list ',' TYPE ID
           | TYPE ID
           |
           ;
Func_call  : ID '(' Arglist ')' ';'
           ;
Arglist    : Arglist ',' ID
           | ID
           |
           ;
Loc        : Loc '[' Bool ']'
           | ID
           ;
Bool       : Bool '|' '|' Join
           | Join
           ;
Join       : Join '&' '&' Equality
           | Equality
           ;
Equality   : Equality DEQ Rel
           | Equality NEQ Rel
           | Rel
           ;
Rel        : Expr LE Expr
           | Expr '<' Expr
           | Expr '>' Expr
           | Expr GE Expr
           | Expr
           ;
Expr       : Expr '+' Term
           | Expr '-' Term
           | Term
           ;
Term       : Term '*' Unary
           | Term '/' Unary
           | Unary
           ;
Unary      : '!' Unary
           | '-' Unary
           | Factor
           ;
Factor     : '(' Bool ')'
           | Loc
           | NUM
           ;

%%

int main (void)
{
    yyparse();
    if(success)
    	printf("Parsing Successful\n");
    return 0;
}

int yyerror(const char *msg)
{
	printf("Parsing Failed\nLine Number: %d %s\n",yylval,msg);
  success = 0;
	return 0;
}