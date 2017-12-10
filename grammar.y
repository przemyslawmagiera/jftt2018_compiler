%{
	#include <stdio.h>
	#include <string>
	#include <cstdlib>
	extern "C" int yylex();
	extern "C" int yyparse();
	void yyerror (char const *);
	extern int yylineno;
	extern char* yytext;
	int memory_ponter = 0;
	void initializeVariable(std::string name);
%}
%define api.value.type {int}

%token <std::string> num
%token <std::string> pidentifier

%token 				VAR
%token				T_BEGIN
%token				END
%token				IF
%token				ELSE
%token				ENDIF
%token				THEN
%token				WHILE
%token				DO
%token				ENDWHILE
%token				FOR
%token				FROM
%token				TO
%token				ENDFOR
%token				DOWNTO
%token				READ
%token				WRITE
%token				SKIP
%token T_ADD	'+'
%token T_MIN	'-'
%token T_MUL	'*'
%token T_DIV	'/'
%token T_MOD	'%'
%token T_EQ 	'='
%token T_NEQ	"<>"
%token T_RGT	'<'
%token T_RGE	"<="
%token T_LGE	">="
%token T_LGT 	'>'
%token T_ASG	":="
%token T_EL		';'
%token T_LBR	'['
%token T_RBR	']'
%token 				ERR

%%
program				:	VAR vdeclarations T_BEGIN commands END

vdeclarations	: vdeclarations pidentifier
              | vdeclarations pidentifier T_LBR num T_RBR
             	|

commands			:	commands command
        			| command

command	      : identifier T_ASG expression T_EL
             	| IF condition THEN commands ELSE commands ENDIF
             	| IF condition THEN commands ENDIF
             	| WHILE condition DO commands ENDWHILE
             	| FOR pidentifier FROM value TO value DO commands ENDFOR
             	| FOR pidentifier FROM value DOWNTO value DO commands ENDFOR
             	| READ identifier T_EL
             	| WRITE value T_EL

expression		:	value
             	| value T_ADD value
             	| value T_MIN value
             	| value T_MUL value
             	| value T_DIV value
             	| value T_MOD value

condition			: value T_EQ value
             	| value T_NEQ value
             	| value T_RGT value
             	| value T_LGT value
             	| value T_RGE value
             	| value T_LGE value

value:					num
             	| identifier

identifier:   	pidentifier	{ initializeVariable(yytext); }
             	| pidentifier T_LBR pidentifier T_RBR
             	| pidentifier T_LBR num T_RBR
%%

void initializeVariable(std::string name)
{

}

void yyerror (char const *s)
{
	printf("Error at line:%d in expression '%s'\n", yylineno, yytext);
}

int main (void)
{
	if(yyparse() == 0)
		printf("\nProcess returned 0, no errors.");
	else
		printf("\nProcess returned 1, error.");

		return 0;
}
