%{
  int classesCount = 0;
  int dataMembersCount = 0;
  int memberFunctionsCount = 0;
%}

DATA_TYPES ((((signed|unsigned|short|long)[ ])?(int|char|double))|(float|bool|void|wchar_t))
IDENTIFIERS ([a-zA-Z_][a-zA-Z0-9_]*)

MEMBER_FUNCTIONS ({DATA_TYPES}[ ]+{IDENTIFIERS}[ ]*\()
DATA_MEMBERS ({DATA_TYPES}[ ]+{IDENTIFIERS}) 

%%

[\s]* {}

class {
  classesCount++;
}

{MEMBER_FUNCTIONS} {
  memberFunctionsCount++;
}

{DATA_MEMBERS} {
  dataMembersCount++;
}

[a-zA-Z]* {}
. {}

%%

int main () {
  yylex();
  printf("Number of classes: %d\n", classesCount);
  printf("Number of data members: %d\n", dataMembersCount);
  printf("Number of member functions: %d\n", memberFunctionsCount);
}