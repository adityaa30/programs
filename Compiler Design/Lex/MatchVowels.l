%{
  #include <string.h>
  int count = 0;
%}

%%

[\t]+ {}

[a-zA-Z0-9]*[aeiouAEIOU][a-zA-Z0-9]* {
  printf("Word: %s\t Vowels: ", yytext);

  int len = strlen(yytext);
  int vowels = 0;
  for (int i = 0; i < len; ++i) {
    char c = yytext[i];
    if (
      c == 'a' || c == 'A'
      || c == 'e' || c == 'E'
      || c == 'i' || c == 'I'
      || c == 'o' || c == 'O'
      || c == 'u' || c == 'U'
    ) {
      ++vowels;
      printf("%c ", yytext[i]);
    }
  }
  printf("(%d)\n", vowels);
  count += vowels;
}

. {}

%%

int main() {
  yylex();
  printf("\nTotal count of vowels: %d\n", count);
}