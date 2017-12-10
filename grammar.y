%{
	#include <stdio.h>
	#include <string>
	#include <string.h>
	#include <cstdlib>
	#include <iostream>
	#include <map>
	#include <list>
	#include "AsmInstruction.h"
	#include "Identifier.h"
	#include <fstream>
	#include <bitset>
	#include <regex>
	extern "C" int yylex();
	extern "C" int yyparse();
	void yyerror (char const *);
	extern int yylineno;
	extern char* yytext;
	int memory_pointer = 0;
	int valueTakenFromIdentifier = 0;
	int copyValueFromAnotherIdentifier(std::string from, std::string to);
	int assignValueToIdentifier(std::string name, int value);
	int constructValueToRegister(int value);
	void undefinedVariableError(std::string varName);
	int storeIdentifier(std::string name);
	void numberTooBigError(std::string varName);
	void printAsmInstructions();
	int readToIdentifier(std::string name);
	int initializeIdentifier(std::string name);
	void printAsmInstructions();
	std::map<std::string, int> memoryMap;
	std::list<int> assignmentMemoryList;
	std::list<AsmInstruction*> asmInstrunctions;
%}
%union {
	char* string;
	int integer;
	//Identifier* identifier;
};

%type <string> value
%type <string> expression
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

command	      : identifier T_ASG expression T_EL {
									if(std::regex_match($3, std::regex("[0-9]+")))
									{
										if(assignValueToIdentifier($1, atoi($3)))
											return 1;
									}
									else
									{
										if(copyValueFromAnotherIdentifier($3, $1))
											return 1;
									}
								}
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

expression		:	value {$$ = $1;}
             	| value T_ADD value {}
             	| value T_MIN value {}
             	| value T_MUL value {}
             	| value T_DIV value {}
             	| value T_MOD value {}

condition			: value T_EQ value
             	| value T_NEQ value
             	| value T_RGT value
             	| value T_LGT value
             	| value T_RGE value
             	| value T_LGE value

value					:	num { $$ = $1;
									//printf("debug value>num :%d\n", $1);
								}
             	| identifier {}

identifier:   	PID {}
             	| PID T_LBR PID T_RBR  {}
             	| PID  T_LBR num T_RBR  {}
%%

/********************************METHODS***********************************/

using namespace std;

string decToBin(int number)
{
    string result = "";
    do
    {
        if ( (number & 1) == 0 )
            result += "0";
        else
            result += "1";

        number >>= 1;
    } while ( number );

    reverse(result.begin(), result.end());
    return result;
}
int copyValueFromAnotherIdentifier(std::string from, std::string to)
{
	map<string, int>::iterator itFrom = memoryMap.find(from);
	map<string, int>::iterator itTo = memoryMap.find(to);
	if(itFrom == memoryMap.end())
	{
		undefinedVariableError(from);
		return 1;
	}
	else if (itTo == memoryMap.end())
	{
		undefinedVariableError(to);
		return 1;
	}
	else
	{
		asmInstrunctions.push_back(new AsmInstruction("LOAD", itFrom->second));
		asmInstrunctions.push_back(new AsmInstruction("STORE", itTo->second));
	}
	return 0;
}

int assignValueToIdentifier(string name, int value)
{
	if(constructValueToRegister(value))
	{
		numberTooBigError(name);
		return 1;
	}
	else
	{
		return storeIdentifier(name);
	}
}

int constructValueToRegister(int value)
{
	string valueBin = decToBin(value);
	asmInstrunctions.push_back(new AsmInstruction("ZERO"));
	printf("DEBUG: %d is binary: %s\n",value, valueBin.c_str());
	for(int i=0; i<valueBin.length(); i++)
	{
		if(valueBin[i] == '0' && i!=0)
			asmInstrunctions.push_back(new AsmInstruction("SHL"));
		else if(valueBin[i] == '1')
			asmInstrunctions.push_back(new AsmInstruction("INC"));
	}
	return 0;
}

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
	return storeIdentifier(name);
}

int storeIdentifier(string name)
{
	map<string, int>::iterator it = memoryMap.find(name);
	if(memoryMap.find(name) == memoryMap.end())
	{
		undefinedVariableError(name);
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

/*******************ERROR HANDLING*********************************/

void undefinedVariableError(string varName)
{
	char* error =(char*) malloc(100);
	error = strcpy(error, "Variable '");
	error = strcat(error,varName.c_str());
	error = strcat(error,"' undeclared.");
	yyerror(error);
	free(error);
}

void numberTooBigError(string varName)
{
	char* error =(char*) malloc(100);
	error = strcpy(error, "Cannot assign value to variable '");
	error = strcat(error,varName.c_str());
	error = strcat(error,"' - value too big.");
	yyerror(error);
	free(error);
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
