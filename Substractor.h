#include <string>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;
extern int constructValueToRegister(long long value);
extern void	undefinedVariableError(string varName);
extern int	checkInitialization(string varName);
extern map<string, MemoryItem*> memoryMap;
extern vector<AsmInstruction*> asmInstrunctions;


class Substractor
{
	public:
    static int sub(int, int);
    static int sub(int, string);
    static int sub(string, int);
    static int subge(string, int);
    static int sub(string, string);
    static int subge(string, string);
};

/*
	0 is temp cell in memory
*/
int Substractor::sub(int a, int b)
{
  constructValueToRegister(b);
  asmInstrunctions.push_back(new AsmInstruction("STORE", 0));
	//printf("a to: %d\n", a);
  constructValueToRegister(a);
  asmInstrunctions.push_back(new AsmInstruction("SUB", 0));
	return 0;
}

int Substractor::sub(int a, string name)
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
	  constructValueToRegister(a);
	  asmInstrunctions.push_back(new AsmInstruction("SUB", it->second->cell));
		return 0;
	}
}

int Substractor::sub(string name, int a)
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
		constructValueToRegister(a);
	  asmInstrunctions.push_back(new AsmInstruction("STORE", 0));
		asmInstrunctions.push_back(new AsmInstruction("LOAD", it->second->cell));
	  asmInstrunctions.push_back(new AsmInstruction("SUB", 0));
		return 0;
	}
}

int Substractor::subge(string name, int a)
{
	map<string, MemoryItem*>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return 1;
	}
	else
	{
		constructValueToRegister(a);
		if(checkInitialization(name))
			return 1;
	  asmInstrunctions.push_back(new AsmInstruction("STORE", 0));
		asmInstrunctions.push_back(new AsmInstruction("LOAD", it->second->cell));
		asmInstrunctions.push_back(new AsmInstruction("INC"));
	  asmInstrunctions.push_back(new AsmInstruction("SUB", 0));
		return 0;
	}
}

int Substractor::sub(string name1, string name2)
{
	map<string, MemoryItem*>::iterator it1 = memoryMap.find(name1);
	map<string, MemoryItem*>::iterator it2 = memoryMap.find(name2);
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
		if(checkInitialization(name1) || checkInitialization(name2))
			return 1;
	  asmInstrunctions.push_back(new AsmInstruction("LOAD", it1->second->cell));
	  asmInstrunctions.push_back(new AsmInstruction("SUB", it2->second->cell));
		return 0;
	}
}

int Substractor::subge(string name1, string name2)
{
	map<string, MemoryItem*>::iterator it1 = memoryMap.find(name1);
	map<string, MemoryItem*>::iterator it2 = memoryMap.find(name2);
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
		if(checkInitialization(name1) || checkInitialization(name2))
			return 1;
	  asmInstrunctions.push_back(new AsmInstruction("LOAD", it1->second->cell));
		asmInstrunctions.push_back(new AsmInstruction("INC"));
	  asmInstrunctions.push_back(new AsmInstruction("SUB", it2->second->cell));
		return 0;
	}
}
