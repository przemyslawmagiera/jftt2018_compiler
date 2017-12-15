#include <string>
#include <cstdlib>
#include <list>
#include <map>

using namespace std;

extern int constructValueToRegister(int value);
extern map<string, int> memoryMap;
extern list<AsmInstruction*> asmInstrunctions;


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
  constructValueToRegister(a);
  asmInstrunctions.push_back(new AsmInstruction("STORE", 0));
  constructValueToRegister(b);
  asmInstrunctions.push_back(new AsmInstruction("ADD", 0));
	return 0;
}

int Adder::add(int a, string name1)
{
	map<string, int>::iterator it = memoryMap.find(name);
	if(it == memoryMap.end())
	{
		undefinedVariableError(name);
		return 1;
	}
	else
	{
	  constructValueToRegister(b);
	  asmInstrunctions.push_back(new AsmInstruction("ADD", it->second));
		return 0;
	}
}
