%option yylineno

%{
  #include "y.tab.h"
  extern int yylval;
%}

NUMBER        ([0-9]+(".")?([0-9])*)
IDENTIFIER    ([a-zA-z_][a-zA-z_0-9]*)

%%

[\t ]           /* ignore whitespaces */ ;

"if"            {return IFTOK;}
"else"          {return ELSETOK;}
"break"         {return BREAKTOK;}
"do"            {return DOTOK;}
"void"          {return VOIDTOK;}
"return"        {return RETURNTOK;}
"null"          {return NULLTOK;}
"int"           {return TYPE;}
"float"         {return TYPE;}
"=="			      {return DEQ;}
"!="			      {return NEQ;}
"<="			      {return LE;}
">="			      {return GE;}

{NUMBER}        {return NUM;}
{IDENTIFIER}    {return ID;}

.               {return yytext[0];}

\n              {yylval = yylineno;}

\n\n            {return 0;}
%%