LOWER [a-z]

%%

[\t]+ {} 

{LOWER} {
  printf("%c", yytext[0] - ('a' - 'A'));
}

. { ECHO; }

%%

int main() {
  yylex();
}