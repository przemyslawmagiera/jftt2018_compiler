%{
	#include <stdio.h>
	#include <string>
	#include <string.h>
	#include <cstdlib>
	#include <iostream>
	#include <map>
	#include <vector>
	#include "AsmInstruction.h"
	#include "Adder.h"
	#include "Substractor.h"
	#include "Identifier.h"
	#include "Condition.h"
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
	int findVariableInMemory(std::string name);
	void determineAndExecuteExpressionOperation(std::string arg1, std::string arg2, std::string oper,int gte);
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
	int writeNumber(int number);
	int writeIdentifier(std::string name);
	std::map<std::string, int> memoryMap;
	std::vector<AsmInstruction*> asmInstrunctions;
	std::stack<int> jzeroLinePointerStack;
%}
%union {
	char* string;
	int integer;
	//Identifier* identifier;
	//Command* command;
};

%type <string> value
%type <string> expression
%type<string> identifier
%type<string> condition

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
%token<string> T_EQ 	"="
%token<string> T_NEQ	"<>"
%token<string> T_RGT	"<"
%token<string> T_RGE	"<="
%token<string> T_LGE	">="
%token<string> T_LGT 	">"
%token T_ASG	":="
%token T_EL		';'
%token T_LBR	'['
%token T_RBR	']'
%token 				ERR

%%
program				:	VAR vdeclarations T_BEGIN commands END {
								asmInstrunctions.push_back(new AsmInstruction("HALT"));
								printAsmInstructions();
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
									//printf("debug exp: %s \n", $3);
									if(std::regex_match($3, std::regex("[0-9]+")))
									{
										if(assignValueToIdentifier($1, atoi($3)))
											return 1;
									}
								else if(strcmp($3," OEX"))
									{
										//printf("debug identifier %s \n", $1);
										int place = findVariableInMemory($1);
										if(place == -1)
											return 1;
										asmInstrunctions.push_back(new AsmInstruction("STORE", place));
									}
									else
									{
										//printf("debug identifier %s \n", $1);
										if(copyValueFromAnotherIdentifier($3, $1))
											return 1;
									}
								}
             	| IF condition {
								//printf("pushneem wlasnie: %d",asmInstrunctions.size());
								jzeroLinePointerStack.push(asmInstrunctions.size());
							  asmInstrunctions.push_back(new AsmInstruction("JZERO", 0));
							} THEN commands{

							} innerIf
             	| WHILE condition DO commands ENDWHILE
             	| FOR PID FROM value TO value DO commands ENDFOR
             	| FOR PID FROM value DOWNTO value DO commands ENDFOR
             	| READ identifier T_EL {
							//wydrukuj GET i STORE pod komorka pamieci memoryMap.find(identifier)
								if(readToIdentifier($2))
									return 1;
							}
             	| WRITE value T_EL {
								if(std::regex_match($2, std::regex("[0-9]+")))
								{
									if(writeNumber(atoi($2)))
										return 1;
								}
								else
								{
									if(writeIdentifier($2))
										return 1;
								}

							}

innerIf				: ELSE {
								int jzero = jzeroLinePointerStack.top();
								jzeroLinePointerStack.pop();
								//printf("scionglem wlasnie: %d",jzero);
								asmInstrunctions.push_back(new AsmInstruction("ZERO"));
								jzeroLinePointerStack.push(asmInstrunctions.size());
								asmInstrunctions.push_back(new AsmInstruction("JZERO", 0));
								asmInstrunctions[jzero]->arg = asmInstrunctions.size()+1;
							} commands ENDIF {
								int jzero = jzeroLinePointerStack.top();
								jzeroLinePointerStack.pop();
								//printf("scionglem wlasnie: %d",jzero);
								asmInstrunctions[jzero]->arg = asmInstrunctions.size()+1;
							}
							| ENDIF {
								int jzero = jzeroLinePointerStack.top();
								jzeroLinePointerStack.pop();
								//printf("scionglem wlasnie: %d",jzero);
								asmInstrunctions[jzero]->arg = asmInstrunctions.size()+1;
							}

expression		:	value {$$ = $1;}
             	| value T_ADD value {

								printf("debug value>num :%s + %s\n",$1, $3);
								determineAndExecuteExpressionOperation($1,$3,"+",0);
								char f[4] = "OEX";
								$$ = f;
							}
             	| value T_MIN value {
								determineAndExecuteExpressionOperation($1,$3,"-",0);
								char f[4] = "OEX";
								$$ = f;
							}
             	| value T_MUL value {}
             	| value T_DIV value {}
             	| value T_MOD value {}

condition			: value T_EQ value {
								string a($1);
								string b($3);
								determineAndExecuteExpressionOperation(a,b,"-", 0);
								asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
								determineAndExecuteExpressionOperation(b,a,"-", 0);
								asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								constructValueToRegister(1);
								asmInstrunctions.push_back(new AsmInstruction("SUB", 5));
								asmInstrunctions.push_back(new AsmInstruction("SUB", 6));
							}
             	| value T_NEQ value {

							}
             	| value T_RGT value {
								string a($1);
								string b($3);
							  determineAndExecuteExpressionOperation(b,a,"-", 0);
								$$ = $2;
							}
             	| value T_LGT value {
								string a($1);
								string b($3);
							  determineAndExecuteExpressionOperation(a,b,"-", 0);
								$$ = $2;
							}
             	| value T_RGE value {
								string a($1);
								string b($3);
							  determineAndExecuteExpressionOperation(b,a,"-", 1);
								$$ = $2;
							}
             	| value T_LGE value {
								string a($1);
								string b($3);
							  determineAndExecuteExpressionOperation(a,b,"-", 1);
								$$ = $2;
							}

value					:	num { $$ = $1;
									//printf("debug value>num :%s\n", $1);
								}
             	| identifier {}

identifier:   	PID {}
             	| PID T_LBR PID T_RBR  {}
             	| PID  T_LBR num T_RBR  {}
%%

/********************************METHODS***********************************/

using namespace std;

#define OPERATION_STORING_PLACE 1;

int findVariableInMemory(string name)
{
	map<string, int>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return -1;
	}
	else
	{
		return it->second;
	}
}
//gte sluzy do tego zeby zrobic trik ze zwiekszeniem b przy porownaniu
void determineAndExecuteExpressionOperation(string arg1,string arg2,string oper, int gte)
{
	//printf("debug oper: %s \n", oper.c_str());
	int arg1Num = regex_match(arg1, std::regex("[0-9]+"));
	int arg2Num = regex_match(arg2, std::regex("[0-9]+"));
	if(oper == "+")
	{
		if(arg1Num && arg2Num)
			Adder::add(atoi(arg1.c_str()), atoi(arg2.c_str()));
		else if((!arg1Num && arg2Num) || (arg1Num && !arg2Num))
			Adder::add(atoi(arg1.c_str()), arg2);
		else if(!arg1Num && !arg2Num)
			Adder::add(arg1,arg2);
	}
	else if(oper == "-")
	{
		if(arg1Num && arg2Num)
		{
			if(gte)
				Substractor::sub(atoi(arg1.c_str())+1, atoi(arg2.c_str()));
			else
				Substractor::sub(atoi(arg1.c_str()), atoi(arg2.c_str()));
		}
		else if(!arg1Num && arg2Num)
		{
			if(gte)
				Substractor::subge(arg1, atoi(arg2.c_str()));
			else
				Substractor::sub(arg1, atoi(arg2.c_str()));
		}
		else if(arg1Num && !arg2Num)
		{
			if(gte)
				Substractor::sub(atoi(arg1.c_str())+1, arg2);
			else
				Substractor::sub(atoi(arg1.c_str()), arg2);
		}
		else if(!arg1Num && !arg2Num)
		{
			if(gte)
				Substractor::subge(arg1,arg2);
			else
				Substractor::sub(arg1,arg2);
		}
	}
}

int writeNumber(int number)
{
	constructValueToRegister(number);
	asmInstrunctions.push_back(new AsmInstruction("PUT"));
	return 0;
}

int writeIdentifier(string name)
{
	map<string, int>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return 1;
	}
	else
	{
		asmInstrunctions.push_back(new AsmInstruction("LOAD", it->second));
		asmInstrunctions.push_back(new AsmInstruction("PUT"));
		return 0;
	}
}

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

int copyValueFromMemory(int from, std::string to)
{
	map<string, int>::iterator itTo = memoryMap.find(to);
	if (itTo == memoryMap.end())
	{
		undefinedVariableError(to);
		return 1;
	}
	else
	{
		asmInstrunctions.push_back(new AsmInstruction("LOAD", from));
		asmInstrunctions.push_back(new AsmInstruction("STORE", itTo->second));
	}
	return 0;
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
	//printf("DEBUG: %d is binary: %s\n",value, valueBin.c_str());
	for(int i=0; i<valueBin.length(); i++)
	{
		if(valueBin[i] == '0' && i!=0)
			asmInstrunctions.push_back(new AsmInstruction("SHL"));
		else if(valueBin[i] == '1')
		{
			asmInstrunctions.push_back(new AsmInstruction("SHL"));
			asmInstrunctions.push_back(new AsmInstruction("INC"));
		}
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
	outputFile.open("output1.mr");
	vector<AsmInstruction*>::iterator it;
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
	if(strncmp(s," syntax",6))
	{
		printf("Error at line:%d near expression '%s', detail : %s \n", yylineno, yytext, "unrecognised expression");
	}
	else
	{
	printf("Error at line:%d near expression '%s', detail : %s \n", yylineno, yytext, s);
	}
}


int main (void)
{
	memory_pointer = 10;
	if(yyparse() == 0)
		printf("Process returned 0, no errors.\n");
	else
		printf("Process returned 1, error.\n");

		return 0;
}
