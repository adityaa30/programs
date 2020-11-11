%option yylineno

%{
  #include "y.tab.h"
  extern int yylval;
%}

NUMBER        ([0-9]+(".")?([0-9])*)
IDENTIFIER    ([a-zA-z_][a-zA-z_0-9]*)
OP            (\+|\-|\*|\/|%|\-\-|&&|\|\||>|<|==|>=|<=|=)

%%

[\t ]           /* ignore whitespaces */ ;

switch         {return SWITCH;}
case           {return CASE;}
break          {return BREAK;}
default        {return DEFAULT;}

{OP}           {return OP;}
{NUMBER}       {return NUM;}  
{IDENTIFIER}   {return ID;}

.              {return yytext[0];}

\n             {yylval = yylineno;}

\n\n            {return 0;}

%%