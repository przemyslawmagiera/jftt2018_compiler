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


class Divider
{
	public:
    static int prepare(long long, long long);
    static int prepare(long long, string);
    static int prepare(string, long long);
    static int prepare(string, string);
		static void doTheJob();
};

int Divider::prepare(long long a, long long b)
{
  constructValueToRegister(a);
  asmInstrunctions.push_back(new AsmInstruction("STORE", 9));
  constructValueToRegister(b);
  asmInstrunctions.push_back(new AsmInstruction("STORE", 10));
	return 0;
}

int Divider::prepare(long long a, string name)
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
	  asmInstrunctions.push_back(new AsmInstruction("STORE", 9));
	  asmInstrunctions.push_back(new AsmInstruction("LOAD", it->second->cell));
		asmInstrunctions.push_back(new AsmInstruction("STORE", 10));
		return 0;
	}
}

int Divider::prepare(string name, long long a)
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
		asmInstrunctions.push_back(new AsmInstruction("STORE", 10));
	  asmInstrunctions.push_back(new AsmInstruction("LOAD", it->second->cell));
	  asmInstrunctions.push_back(new AsmInstruction("STORE", 9));
		return 0;
	}
}


int Divider::prepare(string name1, string name2)
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
		asmInstrunctions.push_back(new AsmInstruction("STORE", 9));
	  asmInstrunctions.push_back(new AsmInstruction("LOAD", it2->second->cell));
		asmInstrunctions.push_back(new AsmInstruction("STORE", 10));
		return 0;
	}
}

void Divider::doTheJob()
{
	//check if b is not zero
	asmInstrunctions.push_back(new AsmInstruction("LOAD", 10));
	asmInstrunctions.push_back(new AsmInstruction("JZERO",asmInstrunctions.size()+2));
	asmInstrunctions.push_back(new AsmInstruction("JUMP",asmInstrunctions.size()+4));
	asmInstrunctions.push_back(new AsmInstruction("STORE",11));
	asmInstrunctions.push_back(new AsmInstruction("STORE",9));
	asmInstrunctions.push_back(new AsmInstruction("JUMP",asmInstrunctions.size()+47));

	asmInstrunctions.push_back(new AsmInstruction("ZERO"));
	asmInstrunctions.push_back(new AsmInstruction("INC"));
	asmInstrunctions.push_back(new AsmInstruction("STORE",13));
	asmInstrunctions.push_back(new AsmInstruction("ZERO"));
	asmInstrunctions.push_back(new AsmInstruction("STORE",11));
	asmInstrunctions.push_back(new AsmInstruction("STORE",12));//6

	int condition = asmInstrunctions.size();
	//while
	//condition RGE (9,10)
	asmInstrunctions.push_back(new AsmInstruction("LOAD", 9));
	asmInstrunctions.push_back(new AsmInstruction("INC"));
	asmInstrunctions.push_back(new AsmInstruction("SUB", 10));//9

	asmInstrunctions.push_back(new AsmInstruction("JZERO", asmInstrunctions.size()+8));
	asmInstrunctions.push_back(new AsmInstruction("LOAD", 12));
	asmInstrunctions.push_back(new AsmInstruction("INC"));
	asmInstrunctions.push_back(new AsmInstruction("STORE", 12));
	asmInstrunctions.push_back(new AsmInstruction("LOAD", 10));
	asmInstrunctions.push_back(new AsmInstruction("SHL"));
	asmInstrunctions.push_back(new AsmInstruction("STORE", 10));
	asmInstrunctions.push_back(new AsmInstruction("JUMP", condition));//17
	//endwhile

	asmInstrunctions.push_back(new AsmInstruction("LOAD", 10));
	asmInstrunctions.push_back(new AsmInstruction("SHR"));
	asmInstrunctions.push_back(new AsmInstruction("STORE", 10));//20

	//for RGE (k,i)
	int forCondition = asmInstrunctions.size();
	asmInstrunctions.push_back(new AsmInstruction("LOAD", 12));
	asmInstrunctions.push_back(new AsmInstruction("INC"));
	asmInstrunctions.push_back(new AsmInstruction("SUB", 13));
	asmInstrunctions.push_back(new AsmInstruction("JZERO", asmInstrunctions.size()+23));
	//if b <= a
	asmInstrunctions.push_back(new AsmInstruction("LOAD", 9));
	asmInstrunctions.push_back(new AsmInstruction("INC"));
	asmInstrunctions.push_back(new AsmInstruction("SUB", 10));//27

	asmInstrunctions.push_back(new AsmInstruction("JZERO", asmInstrunctions.size()+9));
	asmInstrunctions.push_back(new AsmInstruction("LOAD", 9));
	asmInstrunctions.push_back(new AsmInstruction("SUB", 10));
	asmInstrunctions.push_back(new AsmInstruction("STORE", 9));
	asmInstrunctions.push_back(new AsmInstruction("LOAD", 11));
	asmInstrunctions.push_back(new AsmInstruction("SHL"));
	asmInstrunctions.push_back(new AsmInstruction("INC"));
	asmInstrunctions.push_back(new AsmInstruction("STORE", 11));
	asmInstrunctions.push_back(new AsmInstruction("JUMP", asmInstrunctions.size()+4));
	asmInstrunctions.push_back(new AsmInstruction("LOAD", 11));
	asmInstrunctions.push_back(new AsmInstruction("SHL"));
	asmInstrunctions.push_back(new AsmInstruction("STORE", 11));//39

	asmInstrunctions.push_back(new AsmInstruction("LOAD", 10));
	asmInstrunctions.push_back(new AsmInstruction("SHR"));
	asmInstrunctions.push_back(new AsmInstruction("STORE", 10));
	asmInstrunctions.push_back(new AsmInstruction("LOAD", 13));
	asmInstrunctions.push_back(new AsmInstruction("INC"));
	asmInstrunctions.push_back(new AsmInstruction("STORE", 13));
	asmInstrunctions.push_back(new AsmInstruction("JUMP", forCondition));//46

	asmInstrunctions.push_back(new AsmInstruction("LOAD", 11));
}
