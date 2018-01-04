%{
	#include <stdio.h>
	#include <string>
	#include <string.h>
	#include <cstdlib>
	#include <iostream>
	#include <map>
	#include <vector>
	#include "MemoryItem.h"
	#include "AsmInstruction.h"
	#include "Adder.h"
	#include "Substractor.h"
	#include "Multiplier.h"
	#include "Divider.h"
	#include <fstream>
	#include <bitset>
	#include <regex>
	#include <algorithm>
	extern "C" int yylex();
	extern "C" int yyparse();
	void yyerror (char const *);
	extern int yylineno;
	extern char* yytext;
	long long memory_pointer = 0;
	int valueTakenFromIdentifier = 0;
	int storeArrayValueInTemporaryVariable(std::string name, std::string index, int place);
	int storeAccumulatorInArray(std::string name, std::string index);
	int findVariableInMemory(std::string name);
	int loadTableElementToAccumulator(std::string name, std::string index);
	int determineAndExecuteExpressionOperation(std::string arg1, std::string arg2, std::string oper,int gte);
	int copyValueFromAnotherIdentifier(std::string from, std::string to);
	int assignValueToIdentifier(std::string name, long long value);
	int constructValueToRegister(long long value);
	void undefinedVariableError(std::string varName);
	void typeMismatchError(std::string varName);
	int storeIdentifier(std::string name);
	void printAsmInstructions();
	int readToIdentifier(std::string name);
	int initializeIdentifier(std::string name, int tab, long long size);
	void printAsmInstructions();
	int writeNumber(long long number);
	int writeIdentifier(std::string name);
	void immutableError(std::string varName);
	void uninitializedVariableError(std::string varName);
	int loadFromMemory(std::string name);
	std::map<std::string, MemoryItem*> memoryMap;
	std::vector<AsmInstruction*> asmInstrunctions;
	std::stack<int> jzeroLinePointerStack;
	std::stack<int> whileConditionPointerStack;
	std::stack<int> whileJumpPointerStack;
	std::stack<int> forCounterDeepStack;
	std::vector<string> initializedVars;
	std::vector<string> immutableVars;
	struct Value {
    bool isArray;
    bool isNumber;
    bool isVariable;
		bool isResult;
    string num;
    string name;
		string index;
	};
	#define OPERATION_STORING_PLACE 1
	#define ARRAY_BUFFER_STORING_PLACE_1 2
	#define ARRAY_BUFFER_STORING_PLACE_2 3
	#define ARRAY_BUFFER_STORING_PLACE_3 4
	std::string ARRAY_TEMP_VAR_1 = "A1";
	std::string ARRAY_TEMP_VAR_2 = "A2";
	std::string ARRAY_TEMP_VAR_3 = "A3";
	int for_var_counter = 0;
	#define TEMP_ACC_PLACE 8
%}
%union {
	char* string;
	int integer;
	struct Value* value;
	//Identifier* identifier;
	//Command* command;
};

%type <value> value
%type <value> expression
%type<value> identifier
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
								if(initializeIdentifier($2,0,1))
										return 1;
								}
              | vdeclarations PID  T_LBR num T_RBR {
								if(initializeIdentifier($2,1,atoll($4)))
									return 1;
							}
             	|

commands			:	commands command
        			| command

command	      : identifier T_ASG expression T_EL {
									//printf("debug exp: %s \n", $3);
									if($1->isVariable == true)
									{
										if($3->isNumber)
										{
											if(assignValueToIdentifier($1->name, stoll($3->num)))
												return 1;
										}
										else if($3->isResult)
										{
											//printf("debug identifier %s \n", $1);
											int place = findVariableInMemory($1->name);
											if(place == -1)
												return 1;
											asmInstrunctions.push_back(new AsmInstruction("STORE", place));
										}
										else if($3->isArray)
										{
											if(loadTableElementToAccumulator($3->name, $3->index))
												return 1;
											int place = findVariableInMemory($1->name);
											if(place == -1)
												return 1;
											asmInstrunctions.push_back(new AsmInstruction("STORE", place));
										}
										else if($3->isVariable)
										{
											//printf("debug identifier %s \n", $1);
											if(copyValueFromAnotherIdentifier($3->name, $1->name))
												return 1;
										}
										if(find(immutableVars.begin(), immutableVars.end(), $1->name) != immutableVars.end())
										{
											immutableError($1->name);
											return 1;
										}
										initializedVars.push_back($1->name);
									}
									else
									{
										//puts("chuuiiichuj");
										if($3->isNumber)
										{
											//puts("chuuiiichuj1");
											constructValueToRegister(stoll($3->num));
											if(storeAccumulatorInArray($1->name, $1->index))
												return 1;
											//puts("chuuujjj2");
										}
										else if($3->isResult)
										{
											if(storeAccumulatorInArray($1->name, $1->index))
												return 1;
										}
										else if($3->isArray)
										{
											if(loadTableElementToAccumulator($3->name, $3->index))
												return 1;
											if(storeAccumulatorInArray($1->name, $1->index))
												return 1;
										}
										else if($3->isVariable)
										{
											int place = findVariableInMemory($3->name);
											if(place == -1)
												return 1;
											asmInstrunctions.push_back(new AsmInstruction("LOAD", place));
											if(storeAccumulatorInArray($1->name, $1->index))
												return 1;
										}
									}

								}
             	| IF condition {
								//printf("pushneem wlasnie: %d",asmInstrunctions.size());
								jzeroLinePointerStack.push(asmInstrunctions.size());
							  asmInstrunctions.push_back(new AsmInstruction("JZERO", 0));
							} THEN commands{

							} innerIf
             	| WHILE {
								whileConditionPointerStack.push(asmInstrunctions.size());
							} condition{
								whileJumpPointerStack.push(asmInstrunctions.size());
								asmInstrunctions.push_back(new AsmInstruction("JZERO", 0));

							} DO commands ENDWHILE {
								int whileConditionStart = whileConditionPointerStack.top();
								whileConditionPointerStack.pop();
								asmInstrunctions.push_back(new AsmInstruction("ZERO"));
								asmInstrunctions.push_back(new AsmInstruction("JZERO", whileConditionStart));
								int whileJump = whileJumpPointerStack.top();
								whileJumpPointerStack.pop();
								asmInstrunctions[whileJump]->arg = asmInstrunctions.size();
							}
             	| FOR PID FROM value TO value DO {
								//zastoruj iterator
								immutableVars.push_back($2);
								if(initializeIdentifier($2,0,1))
									return 1;
								//wczytaj value1 do akumulatora
								if($4->isVariable)
								{
									int p = findVariableInMemory($4->name);
									if(p == -1)
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("LOAD", p));
								}
								else if($4->isArray)
								{
									if(loadTableElementToAccumulator($4->name, $4->index))
										return 1;
								}
								else if($4->isNumber)
								{
									constructValueToRegister(stoll($4->num));
								}
								int iterAddress = findVariableInMemory($2);
								asmInstrunctions.push_back(new AsmInstruction("STORE", iterAddress));
								initializedVars.push_back($2);
								//teraz mamy już value1 w zmiennej i, co więcej jest zainicjalizowana
								//zrobmy jeszcze value2 do zmiennej Cx, gdzie x to counter (zeby nie bylo kolizji)
								if(initializeIdentifier("C"+to_string(for_var_counter),0,1))
									return 1;
								if($6->isVariable)
								{
									int p = findVariableInMemory($6->name);
									if(p == -1)
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("LOAD", p));
								}
								else if($6->isArray)
								{
									if(loadTableElementToAccumulator($6->name, $6->index))
										return 1;
								}
								else if($6->isNumber)
								{
									//puts("chhhuuujjj");
									constructValueToRegister(stoll($6->num));
								}
								int p = findVariableInMemory("C"+to_string(for_var_counter));
								asmInstrunctions.push_back(new AsmInstruction("STORE", p));
								initializedVars.push_back("C"+to_string(for_var_counter));
								//mamy zastorowane Tx, teraz trzeba zrobić warunek

								whileConditionPointerStack.push(asmInstrunctions.size());
								//condition right greater equals: i <= val2
								if(determineAndExecuteExpressionOperation("C"+to_string(for_var_counter),$2,"-",1))
									return 1;

								whileJumpPointerStack.push(asmInstrunctions.size());
								asmInstrunctions.push_back(new AsmInstruction("JZERO", 0));
								for_var_counter++;
							}
							commands ENDFOR {
								int iterAddress = findVariableInMemory($2);
								asmInstrunctions.push_back(new AsmInstruction("LOAD", iterAddress));
								asmInstrunctions.push_back(new AsmInstruction("INC"));
								asmInstrunctions.push_back(new AsmInstruction("STORE", iterAddress));
								int whileConditionStart = whileConditionPointerStack.top();
								whileConditionPointerStack.pop();
								asmInstrunctions.push_back(new AsmInstruction("ZERO"));
								asmInstrunctions.push_back(new AsmInstruction("JZERO", whileConditionStart));
								int whileJump = whileJumpPointerStack.top();
								whileJumpPointerStack.pop();
								asmInstrunctions[whileJump]->arg = asmInstrunctions.size();
								//usunac ze zmiennych Tx oraz iterator
								vector<string>::iterator it1 = find(initializedVars.begin(), initializedVars.end(), $2);
								initializedVars.erase(it1);
								it1 = find(immutableVars.begin(), immutableVars.end(), $2);
								immutableVars.erase(it1);

								map<string, MemoryItem*>::iterator it2 = memoryMap.find($2);
  							memoryMap.erase(it2);
							  memoryMap.erase ("C"+to_string(for_var_counter-1));
								for_var_counter--;
							}
             	| FOR PID FROM value DOWNTO value DO {
								//zastoruj iterator
								immutableVars.push_back($2);
								if(initializeIdentifier($2,0,1))
									return 1;
								//wczytaj value1 do akumulatora
								if($4->isVariable)
								{
									int p = findVariableInMemory($4->name);
									if(p == -1)
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("LOAD", p));
								}
								else if($4->isArray)
								{
									if(loadTableElementToAccumulator($4->name, $4->index))
										return 1;
								}
								else if($4->isNumber)
								{
									constructValueToRegister(stoll($4->num));
								}
								int iterAddress = findVariableInMemory($2);
								asmInstrunctions.push_back(new AsmInstruction("STORE", iterAddress));
								initializedVars.push_back($2);
								//teraz mamy już value1 w zmiennej i, co więcej jest zainicjalizowana
								//zrobmy jeszcze value2 do zmiennej Cx, gdzie x to counter (zeby nie bylo kolizji)
								if(initializeIdentifier("C"+to_string(for_var_counter),0,1))
									return 1;
								if($6->isVariable)
								{
									int p = findVariableInMemory($6->name);
									if(p == -1)
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("LOAD", p));
								}
								else if($6->isArray)
								{
									if(loadTableElementToAccumulator($6->name, $6->index))
										return 1;
								}
								else if($6->isNumber)
								{
									constructValueToRegister(stoll($6->num));
								}
								int p = findVariableInMemory("C"+to_string(for_var_counter));
								asmInstrunctions.push_back(new AsmInstruction("STORE", p));
								initializedVars.push_back("K"+to_string(for_var_counter));
								//mamy zastorowane Tx, teraz trzeba zrobić warunek

								//condition right greater equals: i + 1  > val2
								// k = a-b
								if(initializeIdentifier("K"+to_string(for_var_counter),0,1))
								{
									return 1;
								}
								asmInstrunctions.push_back(new AsmInstruction("LOAD", iterAddress));
								asmInstrunctions.push_back(new AsmInstruction("INC"));
								asmInstrunctions.push_back(new AsmInstruction("SUB", p));
								int p1 = findVariableInMemory("K"+to_string(for_var_counter));
								asmInstrunctions.push_back(new AsmInstruction("STORE", p1));
								whileConditionPointerStack.push(asmInstrunctions.size());
								if(determineAndExecuteExpressionOperation("K"+to_string(for_var_counter),to_string(0),"-",0))
									return 1;

								whileJumpPointerStack.push(asmInstrunctions.size());
								asmInstrunctions.push_back(new AsmInstruction("JZERO", 0));
								for_var_counter++;
							} commands ENDFOR {
								int iterAddress = findVariableInMemory($2);
								int p1 = findVariableInMemory("K"+to_string(for_var_counter-1));
								asmInstrunctions.push_back(new AsmInstruction("LOAD", iterAddress));
								asmInstrunctions.push_back(new AsmInstruction("DEC"));
								asmInstrunctions.push_back(new AsmInstruction("STORE", iterAddress));
								asmInstrunctions.push_back(new AsmInstruction("LOAD", p1));
								asmInstrunctions.push_back(new AsmInstruction("DEC"));
								asmInstrunctions.push_back(new AsmInstruction("STORE", p1));
								int whileConditionStart = whileConditionPointerStack.top();
								whileConditionPointerStack.pop();
								asmInstrunctions.push_back(new AsmInstruction("ZERO"));
								asmInstrunctions.push_back(new AsmInstruction("JZERO", whileConditionStart));
								int whileJump = whileJumpPointerStack.top();
								whileJumpPointerStack.pop();
								asmInstrunctions[whileJump]->arg = asmInstrunctions.size();
								//usunac ze zmiennych Tx oraz iterator
								vector<string>::iterator it1 = find(initializedVars.begin(), initializedVars.end(), $2);
								initializedVars.erase(it1);
								map<string, MemoryItem*>::iterator it2 = memoryMap.find($2);
								memoryMap.erase(it2);
							  memoryMap.erase ("K"+to_string(for_var_counter-1));
							  memoryMap.erase ("C"+to_string(for_var_counter-1));
								it1 = find(immutableVars.begin(), immutableVars.end(), $2);
								immutableVars.erase(it1);
								for_var_counter--;
							}
             	| READ identifier T_EL {
							//wydrukuj GET i STORE pod komorka pamieci memoryMap.find(identifier)
								if($2->isVariable)
								{
									if(readToIdentifier($2->name))
										return 1;
								}
								else
								{
									asmInstrunctions.push_back(new AsmInstruction("GET"));
									if(storeAccumulatorInArray($2->name,$2->index))
										return 1;
								}
							}
             	| WRITE value T_EL {
								if($2->isNumber)
								{
									if(writeNumber(stoll($2->num)))
										return 1;
								}
								else if($2->isVariable)
								{
									if(writeIdentifier($2->name))
										return 1;
								}
								else
								{
									if(loadTableElementToAccumulator($2->name, $2->index))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("PUT"));
								}

							}

innerIf				: ELSE {
								int jzero = jzeroLinePointerStack.top();
								jzeroLinePointerStack.pop();
								//printf("scionglem wlasnie: %d",jzero);
								asmInstrunctions.push_back(new AsmInstruction("ZERO"));
								jzeroLinePointerStack.push(asmInstrunctions.size());
								asmInstrunctions.push_back(new AsmInstruction("JZERO", 0));
								asmInstrunctions[jzero]->arg = asmInstrunctions.size();
							} commands ENDIF {
								int jzero = jzeroLinePointerStack.top();
								jzeroLinePointerStack.pop();
								//printf("scionglem wlasnie: %d",jzero);
								asmInstrunctions[jzero]->arg = asmInstrunctions.size();
							}
							| ENDIF {
								int jzero = jzeroLinePointerStack.top();
								jzeroLinePointerStack.pop();
								//printf("scionglem wlasnie: %d",jzero);
								asmInstrunctions[jzero]->arg = asmInstrunctions.size();
							}

expression		:	value {$$ = $1;}
             	| value T_ADD value {
								//printf("debug value>num :%s + %s\n",$1, $3);
								//std::cout <<"name: "<< $1->name<<" array: "<< $1->isArray <<endl;
								if($1->isArray == true && $3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2) || storeArrayValueInTemporaryVariable($3->name, $3->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"+",0))
										return 1;
								}
								else if($3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation($1->name,ARRAY_TEMP_VAR_2,"+",0))
										return 1;
								}
								else if($1->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,$3->name,"+",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation($1->name,$3->name,"+",0))
										return 1;
								}
								Value* newValue = new Value;
								newValue->isArray = false;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = true;
								$$ = newValue;
							}
             	| value T_MIN value {
								if($1->isArray == true && $3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"-",0))
										return 1;
								}
								else if($3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation($1->name,ARRAY_TEMP_VAR_2,"-",0))
										return 1;
								}
								else if($1->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,$3->name,"-",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation($1->name,$3->name,"-",0))
										return 1;
								}
								Value* newValue = new Value;
								newValue->isArray = false;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = true;
								$$ = newValue;
							}
             	| value T_MUL value {
								if($1->isArray == true && $3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"*",0))
										return 1;
								}
								else if($3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation($1->name,ARRAY_TEMP_VAR_2,"*",0))
										return 1;
								}
								else if($1->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,$3->name,"*",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation($1->name,$3->name,"*",0))
										return 1;
								}
								Value* newValue = new Value;
								newValue->isArray = false;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = true;
								$$ = newValue;
							}
             	| value T_DIV value {
								if($1->isArray == true && $3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"/",0))
										return 1;
								}
								else if($3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation($1->name,ARRAY_TEMP_VAR_2,"/",0))
										return 1;
								}
								else if($1->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,$3->name,"/",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation($1->name,$3->name,"/",0))
										return 1;
								}
								Value* newValue = new Value;
								newValue->isArray = false;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = true;
								$$ = newValue;
							}
             	| value T_MOD value {
								if($1->isArray == true && $3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"/",0))
										return 1;
								}
								else if($3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation($1->name,ARRAY_TEMP_VAR_2,"/",0))
										return 1;
								}
								else if($1->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,$3->name,"/",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation($1->name,$3->name,"/",0))
										return 1;
								}
								asmInstrunctions.push_back(new AsmInstruction("LOAD", 9));
								Value* newValue = new Value;
								newValue->isArray = false;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = true;
								$$ = newValue;
							}

condition			:value T_EQ value {
								if($1->isArray == true && $3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_3,ARRAY_TEMP_VAR_1,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								else if($3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation($1->name,ARRAY_TEMP_VAR_2,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2, $1->name,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								else if($1->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,$3->name,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation($3->name, ARRAY_TEMP_VAR_2,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								else
								{
									if(determineAndExecuteExpressionOperation($1->name,$3->name,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation($3->name,$1->name,"-", 0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								constructValueToRegister(1);
								asmInstrunctions.push_back(new AsmInstruction("SUB", 5));
								asmInstrunctions.push_back(new AsmInstruction("SUB", 6));
							}
             	| value T_NEQ value {
								if($1->isArray == true && $3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_3,ARRAY_TEMP_VAR_1,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								else if($3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation($1->name,ARRAY_TEMP_VAR_2,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2, $1->name,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								else if($1->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,$3->name,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation($3->name, ARRAY_TEMP_VAR_2,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								else
								{
									if(determineAndExecuteExpressionOperation($1->name,$3->name,"-",0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 5));
									if(determineAndExecuteExpressionOperation($3->name,$1->name,"-", 0))
										return 1;
									asmInstrunctions.push_back(new AsmInstruction("STORE", 6));
								}
								asmInstrunctions.push_back(new AsmInstruction("ZERO"));
								asmInstrunctions.push_back(new AsmInstruction("ADD", 5));
								asmInstrunctions.push_back(new AsmInstruction("ADD", 6));
							}
             	| value T_RGT value {
								if($1->isArray == true && $3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_3,ARRAY_TEMP_VAR_2,"-",0))
										return 1;
								}
								else if($3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2, $1->name,"-",0))
										return 1;
								}
								else if($1->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation($3->name,ARRAY_TEMP_VAR_2,"-",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation($3->name,$1->name,"-",0))
										return 1;
								}
							}
             	| value T_LGT value {
								if($1->isArray == true && $3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"-",0))
										return 1;
								}
								else if($3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation($1->name,ARRAY_TEMP_VAR_2,"-",0))
										return 1;
								}
								else if($1->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,$3->name,"-",0))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation($1->name,$3->name,"-",0))
										return 1;
								}
							}
             	| value T_RGE value {
								if($1->isArray == true && $3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_3,ARRAY_TEMP_VAR_2,"-",1))
										return 1;
								}
								else if($3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2, $1->name,"-",1))
										return 1;
								}
								else if($1->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation($3->name,ARRAY_TEMP_VAR_2,"-",1))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation($3->name,$1->name,"-",1))
										return 1;
								}
							}
             	| value T_LGE value {
								if($1->isArray == true && $3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 3))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,ARRAY_TEMP_VAR_3,"-",1))
										return 1;
								}
								else if($3->isArray == true)
								{
									if(storeArrayValueInTemporaryVariable($3->name, $3->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation($1->name,ARRAY_TEMP_VAR_2,"-",1))
										return 1;
								}
								else if($1->isArray == true)
								{
									//puts("ok");
									if(storeArrayValueInTemporaryVariable($1->name, $1->index, 2))
										return 1;
									if(determineAndExecuteExpressionOperation(ARRAY_TEMP_VAR_2,$3->name,"-",1))
										return 1;
								}
								else
								{
									if(determineAndExecuteExpressionOperation($1->name,$3->name,"-",1))
										return 1;
								}
							}

value					:	num {
									Value* newValue = new Value;
									newValue->isArray = false;
									newValue->isVariable = false;
									newValue->isNumber = true;
									newValue->isResult = false;
									newValue->num = $1;
									newValue->name = $1; //tylko do determina
									$$ = newValue;
									//printf("debug value>num :%s\n", $1);
								}
             	| identifier {$$ = $1;}

identifier:   	PID {
									Value* newValue = new Value;
									newValue->isArray = false;
									newValue->isVariable = true;
									newValue->isNumber = false;
									newValue->isResult = false;
									newValue->name = $1;
									$$ = newValue;
								}
             	| PID T_LBR PID T_RBR {
								Value* newValue = new Value;
								newValue->isArray = true;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = false;
								newValue->name = $1;
								newValue->index = $3;
								$$ = newValue;
							}
             	| PID  T_LBR num T_RBR {
								Value* newValue = new Value;
								newValue->isArray = true;
								newValue->isVariable = false;
								newValue->isNumber = false;
								newValue->isResult = false;
								newValue->name = $1;
								newValue->index = $3;
								$$ = newValue;
							}
%%

/********************************METHODS***********************************/

using namespace std;



//są trzy miejsca w ktorych mozna schować wartości arraya
int storeArrayValueInTemporaryVariable(string name, string index, int place)
{
	if(loadTableElementToAccumulator(name, index))
		return 1;
	if(place == 1)
	{
		asmInstrunctions.push_back(new AsmInstruction("STORE", ARRAY_BUFFER_STORING_PLACE_1));
	}
	else if(place == 2)
	{
		asmInstrunctions.push_back(new AsmInstruction("STORE", ARRAY_BUFFER_STORING_PLACE_2));
	}
	else if(place == 3)
	{
		asmInstrunctions.push_back(new AsmInstruction("STORE", ARRAY_BUFFER_STORING_PLACE_3));
	}
	return 0;
}

int findVariableInMemory(string name)
{
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return -1;
	}
	else
	{
		return it->second->cell;
	}
}

//jeśli wywołasz tablice z indexem -1 (takim do zmiennych) to rzuć błąd, lub wiekszym niz rozmiar
int loadTableElementToAccumulator(string name, string index)
{
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return 1;
	}
	else if(it->second->array == 1)
	{
		if(regex_match(index, regex("[0-9]+")))
		{
			constructValueToRegister(stoll(index));
		}
		else
		{
			//załaduj variable do akumulatora
			map<string, MemoryItem*>::iterator it1 = memoryMap.find(index);
			if(it1 == memoryMap.end())
			{
					undefinedVariableError(index);
					return 1;
			}
			if(it1->second->array == 1)
			{
					typeMismatchError(index);
					return 1;
			}
			if(checkInitialization(index))
				return 1;
			int place = findVariableInMemory(index);
			if(place == -1)
				return 1;
			asmInstrunctions.push_back(new AsmInstruction("LOAD", place));
		}
		asmInstrunctions.push_back(new AsmInstruction("STORE", ARRAY_BUFFER_STORING_PLACE_1));
		asmInstrunctions.push_back(new AsmInstruction("LOAD", it->second->cell));
		asmInstrunctions.push_back(new AsmInstruction("ADD", ARRAY_BUFFER_STORING_PLACE_1));
		asmInstrunctions.push_back(new AsmInstruction("STORE", ARRAY_BUFFER_STORING_PLACE_1));
		asmInstrunctions.push_back(new AsmInstruction("LOADI", ARRAY_BUFFER_STORING_PLACE_1));
		return 0;
	}
	else
	{
		typeMismatchError(name);
		return 1;
	}
}

int copyValueFromAnotherIdentifier(string from, string to)
{
	map<string, MemoryItem*>::iterator itFrom = memoryMap.find(from);
	map<string, MemoryItem*>::iterator itTo = memoryMap.find(to);
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
		if(checkInitialization(from))
			return 1;
		asmInstrunctions.push_back(new AsmInstruction("LOAD", itFrom->second->cell));
		asmInstrunctions.push_back(new AsmInstruction("STORE", itTo->second->cell));
	}
	return 0;
}

int storeIdentifier(string name)
{
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(memoryMap.find(name) == memoryMap.end())
	{
		undefinedVariableError(name);
		return 1;
	}
else if(it->second->array == false)
	{
		int placeInMemory = it->second->cell;
		AsmInstruction* a = new AsmInstruction("STORE", placeInMemory);
		asmInstrunctions.push_back(a);
		return 0;
	}
	else
	{
		typeMismatchError(name);
		return 1;
	}
}

int assignValueToIdentifier(string name, long long value)
{
	constructValueToRegister(value);
	return storeIdentifier(name);
}
//gte sluzy do tego zeby zrobic trik ze zwiekszeniem b przy porownaniu
int determineAndExecuteExpressionOperation(string arg1,string arg2,string oper, int gte)
{
	//cout<<"arg1: "<< arg1 << "arg2: "<< arg2 <<endl;
	//printf("debug oper: %s \n", oper.c_str());
	int arg1Num = regex_match(arg1, std::regex("[0-9]+"));
	int arg2Num = regex_match(arg2, std::regex("[0-9]+"));
	//printf("debug arg1: %s czy num: %d arg2: %s, czy num: %d \n",arg1.c_str(), arg1Num, arg2.c_str(), arg2Num);
	if(oper == "+")
	{
		if(arg1Num && arg2Num)
		{	if(Adder::add(atoi(arg1.c_str()), atoi(arg2.c_str())))
				return 1;}
		else if(!arg1Num && arg2Num)
		{	if(Adder::add(atoi(arg2.c_str()), arg1))
				return 1;}
		else if(arg1Num && !arg2Num)
		{
			if(Adder::add(atoi(arg1.c_str()), arg2))
				return 1;
		}
		else if(!arg1Num && !arg2Num)
		{	if(Adder::add(arg1,arg2))
				return 1;}
	}
	else if(oper == "-")
	{
		if(arg1Num && arg2Num)
		{
			if(gte)
			{	if(Substractor::sub(atoi(arg1.c_str())+1, atoi(arg2.c_str())))
					return 1;}
			else
			{	if(Substractor::sub(atoi(arg1.c_str()), atoi(arg2.c_str())))
					return 1;}
		}
		else if(!arg1Num && arg2Num)
		{
			if(gte)
			{	if(Substractor::subge(arg1, atoi(arg2.c_str())))
					return 1;}
			else
				{if(Substractor::sub(arg1, atoi(arg2.c_str())))
					return 1;}
		}
		else if(arg1Num && !arg2Num)
		{
			if(gte)
			{	if(Substractor::sub(atoi(arg1.c_str())+1, arg2))
					return 1;}
			else
			{	if(Substractor::sub(atoi(arg1.c_str()), arg2))
					return 1;}
		}
		else if(!arg1Num && !arg2Num)
		{
			if(gte)
			{	if(Substractor::subge(arg1,arg2))
					return 1;}
			else
			{	if(Substractor::sub(arg1,arg2))
					return 1;}
		}
	}
	else if(oper == "*")
	{
		if(arg1Num && arg2Num)
		{
			if(Multiplier::prepare(atoi(arg1.c_str()), atoi(arg2.c_str())))
				return 1;
		}
		else if(!arg1Num && arg2Num)
		{
			if(Multiplier::prepare(atoi(arg2.c_str()), arg1))
				return 1;
		}
		else if(arg1Num && !arg2Num)
		{
			if(Multiplier::prepare(atoi(arg1.c_str()), arg2))
				return 1;
		}
		else if(!arg1Num && !arg2Num)
		{
			if(Multiplier::prepare(arg1,arg2))
				return 1;
		}
		Multiplier::doTheJob();
	}
	else if(oper == "/")
	{
		if(arg1Num && arg2Num)
		{
			if(Divider::prepare(atoi(arg1.c_str()), atoi(arg2.c_str())))
				return 1;
		}
		else if(!arg1Num && arg2Num)
		{
			if(Divider::prepare(arg1,atoi(arg2.c_str())))
				return 1;
		}
		else if(arg1Num && !arg2Num)
		{
			if(Divider::prepare(atoi(arg1.c_str()), arg2))
				return 1;
		}
		else if(!arg1Num && !arg2Num)
		{
			if(Divider::prepare(arg1,arg2))
				return 1;
		}
		Divider::doTheJob();
	}
	return 0;
}

int writeNumber(long long number)
{
	constructValueToRegister(number);
	asmInstrunctions.push_back(new AsmInstruction("PUT"));
	return 0;
}

int writeIdentifier(string name)
{
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return 1;
	}
	else
	{
		if(checkInitialization(name))
			return 1;
		asmInstrunctions.push_back(new AsmInstruction("LOAD", it->second->cell));
		asmInstrunctions.push_back(new AsmInstruction("PUT"));
		return 0;
	}
}

string decToBin(long long number)
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

int constructValueToRegister(long long value)
{
	string valueBin = decToBin(value);
	asmInstrunctions.push_back(new AsmInstruction("ZERO"));
	//printf("DEBUG: %d is binary: %s\n",value, valueBin.c_str());
	for(long long i=0; i<valueBin.length(); i++)
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

int initializeIdentifier(string name, int tab, long long size)
{
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		memoryMap[name] = new MemoryItem(name, tab, memory_pointer, size);
		if(tab == 1)
		{
			constructValueToRegister(memory_pointer+1);
			asmInstrunctions.push_back(new AsmInstruction("STORE", memory_pointer));
			memory_pointer++;
		}
		memory_pointer+=size;
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
	initializedVars.push_back(name);
	AsmInstruction* a = new AsmInstruction("GET");
	asmInstrunctions.push_back(a);
	return storeIdentifier(name);
}

int storeAccumulatorInArray(string name, string index)
{
//	cout<<"idx: "<< index << endl;
	asmInstrunctions.push_back(new AsmInstruction("STORE", TEMP_ACC_PLACE));
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return 1;
	}
else if(it->second->array == true)
	{
		if(regex_match(index, regex("[0-9]+")))
		{
			constructValueToRegister(stoll(index));
		}
		else
		{
			//załaduj index do akumulatora
			int place = findVariableInMemory(index);
			if(place == -1)
				return 1;
			asmInstrunctions.push_back(new AsmInstruction("LOAD", place));
		}
		asmInstrunctions.push_back(new AsmInstruction("ADD", it->second->cell));
		asmInstrunctions.push_back(new AsmInstruction("STORE", ARRAY_BUFFER_STORING_PLACE_1));
		asmInstrunctions.push_back(new AsmInstruction("LOAD", TEMP_ACC_PLACE));
		asmInstrunctions.push_back(new AsmInstruction("STOREI", ARRAY_BUFFER_STORING_PLACE_1));
		return 0;
	}
	else
	{
		typeMismatchError(name);
		return 1;
	}
}

int checkInitialization(string name)
{
	if(find(initializedVars.begin(), initializedVars.end(), name) != initializedVars.end())
	{
		return 0;
	}
	uninitializedVariableError(name);
	return 1;
}

void printAsmInstructions()
{
	ofstream outputFile;
	outputFile.open("output.mr");
	vector<AsmInstruction*>::iterator it;
	for (auto const& i : asmInstrunctions) {
    outputFile << i->toString() << endl;
	}
	outputFile.close();
}

/*******************ERROR HANDLING*********************************/

void immutableError(string varName)
{
	char* error =(char*) malloc(100);
	error = strcpy(error, "Attempt to edit immutable variable '");
	error = strcat(error,varName.c_str());
	error = strcat(error,"' .");
	yyerror(error);
	free(error);
}

void typeMismatchError(string varName)
{
	char* error =(char*) malloc(100);
	error = strcpy(error, "Incorrect call to '");
	error = strcat(error,varName.c_str());
	error = strcat(error,"' variable. Type mismatch.");
	yyerror(error);
	free(error);
}

void undefinedVariableError(string varName)
{
	char* error =(char*) malloc(100);
	error = strcpy(error, "Variable '");
	error = strcat(error,varName.c_str());
	error = strcat(error,"' undeclared.");
	yyerror(error);
	free(error);
}

void uninitializedVariableError(string varName)
{
	char* error =(char*) malloc(100);
	error = strcpy(error, "Variable '");
	error = strcat(error,varName.c_str());
	error = strcat(error,"' uninitialized.");
	yyerror(error);
	free(error);
}

void yyerror (char const *s)
{
	printf("Error at line:%d near expression '%s', detail : %s \n", yylineno, yytext, s);
}


int main (void)
{
	memory_pointer = 14;

	memoryMap[ARRAY_TEMP_VAR_1] = new MemoryItem(ARRAY_TEMP_VAR_1, 1, ARRAY_BUFFER_STORING_PLACE_1, 1);
	memoryMap[ARRAY_TEMP_VAR_2] = new MemoryItem(ARRAY_TEMP_VAR_2, 1, ARRAY_BUFFER_STORING_PLACE_2, 1);
	memoryMap[ARRAY_TEMP_VAR_3] = new MemoryItem(ARRAY_TEMP_VAR_3, 1, ARRAY_BUFFER_STORING_PLACE_3, 1);
	initializedVars.push_back(ARRAY_TEMP_VAR_1);
	initializedVars.push_back(ARRAY_TEMP_VAR_2);
	initializedVars.push_back(ARRAY_TEMP_VAR_3);

	if(yyparse() == 0)
		printf("Process returned 0, no errors.\n");
	else
		printf("Process returned 1, error.\n");

		return 0;
}
