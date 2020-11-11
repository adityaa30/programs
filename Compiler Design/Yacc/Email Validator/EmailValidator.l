%{
  #include "y.tab.h"
  extern int yylval; 
%}

EMAIL_REGEX ([a-zA-Z0-9_\.]+@[a-zA-Z0-9_]+\.[a-zA-Z]+)
%%

[\t ]+  ;

{EMAIL_REGEX} {
  return EMAIL;
}

. {
  return yytext[0];
}

%%