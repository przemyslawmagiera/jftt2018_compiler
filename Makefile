all:
	bison -d grammar.y
	flex lexer.l grammar.tab.h
	g++ -std=c++14 lex.yy.c grammar.tab.c
flex:
	flex lexer.l
	g++ lex.yy.c -lfl
