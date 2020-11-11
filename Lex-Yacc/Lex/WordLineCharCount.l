%{
  #include<string.h>
  int wordsCount = 0;
  int lineCount = 1;
  int charactersCount = 0;
  int numbersCount = 0;
  int spacesCount = 0;
  int commaCount = 0;
  int fullStopCount = 0;
%}

%%

[0-9]+ {
  numbersCount++;
  charactersCount += (int)strlen(yytext);
}

[ ]+ {
  spacesCount++;
  charactersCount++;
}
                      
, {
  commaCount++;
  charactersCount++;
}

\. {
  fullStopCount++;
  charactersCount++;
}

[a-zA-Z0-9']+ {
  wordsCount++;
  charactersCount += (int)strlen(yytext);
}

. {
  charactersCount++;
}

\n { 
  lineCount++;
  charactersCount++;
}

%%

int main() {
  yylex();
  printf("Number of words: %d\n", wordsCount);
  printf("Number of lines: %d\n", lineCount);
  printf("Number of characters: %d\n", charactersCount);
  printf("Number of numbers: %d\n", numbersCount);
  printf("Number of spaces: %d\n", spacesCount);
  printf("Number of commas: %d\n", commaCount);
  printf("Number of full stops: %d\n", fullStopCount);
}