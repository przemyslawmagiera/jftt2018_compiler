#include <string>
#include <cstdlib>
#include <list>
#include <map>

using namespace std;

extern int constructValueToRegister(int value);
extern void	undefinedVariableError(string varName);
extern map<string, int> memoryMap;
extern list<AsmInstruction*> asmInstrunctions;


class Substractor
{
	public:
    static int sub(int, int);
    static int sub(int, string);
    static int sub(string, int);
    static int sub(string, string);
};

/*
	0 is temp cell in memory
*/
int Substractor::sub(int a, int b)
{
  constructValueToRegister(b);
  asmInstrunctions.push_back(new AsmInstruction("STORE", 0));
  constructValueToRegister(a);
  asmInstrunctions.push_back(new AsmInstruction("SUB", 0));
	return 0;
}

int Substractor::sub(int a, string name)
{
	map<string, int>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return 1;
	}
	else
	{
	  constructValueToRegister(a);
	  asmInstrunctions.push_back(new AsmInstruction("SUB", it->second));
		return 0;
	}
}

int Substractor::sub(string name, int a)
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
		constructValueToRegister(a);
	  asmInstrunctions.push_back(new AsmInstruction("STORE", 0));
	  asmInstrunctions.push_back(new AsmInstruction("SUB", 0));
		return 0;
	}
}


int Substractor::sub(string name1, string name2)
{
	map<string, int>::iterator it1 = memoryMap.find(name1);
	map<string, int>::iterator it2 = memoryMap.find(name2);
	if(it1 == memoryMap.end())
	{
		undefinedVariableError(name1);
		return 1;
	}
	else if(it2 == memoryMap.end())
	{
		undefinedVariableError(name2);
		return 1;
	}
	else
	{
	  asmInstrunctions.push_back(new AsmInstruction("LOAD", it1->second));
	  asmInstrunctions.push_back(new AsmInstruction("SUB", it2->second));
		return 0;
	}
}
