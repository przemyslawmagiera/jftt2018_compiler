%{
	#include <stdio.h>
	#include <string>
	#include <string.h>
	#include <cstdlib>
	#include <iostream>
	#include <map>
	#include <list>
	#include "AsmInstruction.h"
	#include <fstream>
	extern "C" int yylex();
	extern "C" int yyparse();
	void yyerror (char const *);
	extern int yylineno;
	extern char* yytext;
	int memory_pointer = 0;
	int assignValueToIdentifier(std::string name);
	void printAsmInstructions();
	int readToIdentifier(std::string name);
	int initializeIdentifier(std::string name);
	void printAsmInstructions();
	std::map<std::string, int> memoryMap;
	std::list<AsmInstruction*> asmInstrunctions;
%}
%union {
	char* string;
	int integer;
};

//%type <string> command
%type<string> identifier

%token <string> num
%token <string> PID "identifier"


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
program				:	VAR vdeclarations T_BEGIN commands END { printAsmInstructions();
								}

vdeclarations	: vdeclarations PID {
								if(initializeIdentifier($2))
										return 1;
								}
              | vdeclarations PID  T_LBR num T_RBR
             	|

commands			:	commands command
        			| command

command	      : identifier T_ASG expression T_EL
             	| IF condition THEN commands ELSE commands ENDIF
             	| IF condition THEN commands ENDIF
             	| WHILE condition DO commands ENDWHILE
             	| FOR PID FROM value TO value DO commands ENDFOR
             	| FOR PID FROM value DOWNTO value DO commands ENDFOR
             	| READ identifier T_EL {
							//wydrukuj GET i STORE pod komorka pamieci memoryMap.find(identifier)
								if(readToIdentifier($2))
									return 1;
							}
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
             	| identifier {}

identifier:   	PID //wyciagnij z mapy numer w pamieci pod ktorym jest identifier i wypluj
             	| PID T_LBR PID T_RBR
             	| PID  T_LBR num T_RBR
%%

/********************************METHODS***********************************/

using namespace std;
int initializeIdentifier(string name)
{
	if(memoryMap.find(name) == memoryMap.end())
	{
		memoryMap[name] = memory_pointer;
		memory_pointer++;
		return 0;
	}
	else
	{
		char* error =(char*) malloc(100);
		error = strcpy(error, "Duplicate identifier: ");
		error = strcat(error,name.c_str());
		yyerror(error);
		return 1;
	}
}

int readToIdentifier(string name)
{
	AsmInstruction* a = new AsmInstruction("GET");
	asmInstrunctions.push_back(a);
	return assignValueToIdentifier(name);
}

int assignValueToIdentifier(string name)
{
	map<string, int>::iterator it = memoryMap.find(name);
	if(memoryMap.find(name) == memoryMap.end())
	{
		char* error =(char*) malloc(100);
		error = strcpy(error, "Variable '");
		error = strcat(error,name.c_str());
		error = strcat(error,"' undeclared.");
		yyerror(error);
		return 1;
	}
	else
	{
		int placeInMemory = it->second;
		AsmInstruction* a = new AsmInstruction("STORE", placeInMemory);
		asmInstrunctions.push_back(a);
		return 0;
	}
}

void printAsmInstructions()
{
	ofstream outputFile;
	outputFile.open("output.mr");
	list<AsmInstruction*>::iterator it;
	for (auto const& i : asmInstrunctions) {
    outputFile << i->toString() << endl;
	}
	outputFile.close();
}

void yyerror (char const *s)
{
	printf("Error at line:%d near expression '%s', detail : %s \n", yylineno, yytext, s);
}


int main (void)
{
	if(yyparse() == 0)
		printf("Process returned 0, no errors.\n");
	else
		printf("Process returned 1, error.\n");

		return 0;
}
