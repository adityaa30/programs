%{
  int count = 0;
%}

%%

[\s]+ // Ignore Whitespaces

[a-zA-Z]*[aeiouAEIOU][a-zA-Z]*[aeiouAEIOU][a-zA-Z]*  {
  count++;
  printf("%s", yytext);
}

. {}

%%

int main() {
  yylex();
  printf("\n\n%d words have atleast two vowels\n", count);
}