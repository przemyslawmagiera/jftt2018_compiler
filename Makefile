all:
	bison -d grammar.y
	flex lexer.l grammar.tab.h
	g++ lex.yy.c grammar.tab.c
flex:
	flex lexer.l
	g++ lex.yy.c -lfl
