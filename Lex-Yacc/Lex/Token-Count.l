%{
  int operatorsCount = 0;
  int identifiersCount = 0;
  int keywordsCount = 0;
  int specialSymbolsCount = 0;
%}

KEYWORDS        (auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while)

ARITHMETIC      (\+|-|\*|\/|%|\+\+|--)
RELATIONAL      (==|!=|>=|<=|>|<)
LOGICAL         (&&|\|\||!)
BITWISE         (\^|\||&|<<|>>)
ASSIGNMENT      (=|\+=|-=|\*=|\/=|%=)

OPERATORS       ({ARITHMETIC}|{RELATIONAL}|{LOGICAL}|{BITWISE}|{ASSIGNMENT})

SPECIAL_SYMBOLS [;{}\(\)\[\]@#$,"`~!&?\\\.\*]

%%

[\s]+                   /* ignore whitespaces */

{OPERATORS} {
  operatorsCount++;
}

{KEYWORDS} {
  keywordsCount++;
}

[a-zA-Z_][a-zA-Z0-9_]* {
  identifiersCount++;
}

{SPECIAL_SYMBOLS} { 
  specialSymbolsCount++;
}

. {}                        

%%

int main() {
  yylex();
  printf("\n\nNumber of Operators: %d\n", operatorsCount);
  printf("Number of Identifiers: %d\n", identifiersCount);
  printf("Number of Keywords: %d\n", keywordsCount);
  printf("Number of Special Symbols: %d\n", specialSymbolsCount);
}