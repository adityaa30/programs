%{
  int count = 0;
%}

%%

[\s]+ // Ignore Whitespaces
[kK][a-zA-Z]* {
  count++;
  printf("%s", yytext);
}

[a-zA-Z]* {}
. {}

%%

int main() {
  yylex();
  printf("\n\n%d words starts with k or K.", count);
}