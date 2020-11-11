# Lex Yacc Programs

### Compile & Run Lex Programs
```bash
lex <lex filepath> && gcc -lfl lex.yy.c && ./a.out < input.txt | sed '/^$/d'
```
We use `sed` to remove empty lines.