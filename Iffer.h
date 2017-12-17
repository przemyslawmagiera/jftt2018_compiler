#include <string>
#include <cstdlib>
#include <vector>
#include "AsmInstruction.h"
#include "Condition.h"

using namespace std;

extern vector<AsmInstruction*> asmInstrunctions;

class Iffer
{
	public:
    string logicCondition;
    string a;
    string b;
    int instructionCounter = 0;
    int endLine = 0;
  	list<AsmInstruction*> ifInstrunctions;
    Iffer(string, string, string);
    void go();
}

Iffer::Iffer(string a1,string b1, string anLogicCondition)
{
  a = a1;
  b = b1;
  logicCondition = anLogicCondition;
}

void go()
{
  int afterConditionLineNo = asmInstrunctions.size();
  asmInstrunctions.push_back(new AsmInstruction("JZERO", "END"));
}
