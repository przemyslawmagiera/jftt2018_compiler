#include <string>
#include <cstdlib>
#include <vector>
#include <map>


using namespace std;
extern int constructValueToRegister(int value);
extern void	undefinedVariableError(string varName);
extern int	checkInitialization(string varName);
extern map<string, MemoryItem*> memoryMap;
extern vector<AsmInstruction*> asmInstrunctions;


class Adder
{
	public:
    static int add(int, int);
    static int add(int, string);
    static int add(string, string);
};

/*
	0 is temp cell in memory
*/
int Adder::add(int a, int b)
{
	//puts("chuje");
  constructValueToRegister(a);
  asmInstrunctions.push_back(new AsmInstruction("STORE", 0));
  constructValueToRegister(b);
  asmInstrunctions.push_back(new AsmInstruction("ADD", 0));
	return 0;
}

int Adder::add(int a, string name)
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
	  asmInstrunctions.push_back(new AsmInstruction("ADD", it->second->cell));
		return 0;
	}
}


int Adder::add(string name1, string name2)
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
	  asmInstrunctions.push_back(new AsmInstruction("ADD", it2->second->cell));
		return 0;
	}
}
