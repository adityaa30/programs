%{
  int count = 0;
%}

%%

[\s]+ {}

[a-zA-Z0-9]*([a-z][a-zA-Z0-9]*[A-Z]|[A-Z][a-zA-Z0-9]*[a-z])[a-zA-Z0-9] {
  count++;
  printf("%s\n", yytext);
}

. {}

%%

int main() {
  yylex();
  printf("\n\nNumber of words with mixed case: %d\n", count);
}