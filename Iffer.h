#include <string>
#include <cstdlib>
#include <list>
#include "AsmInstruction.h"
#include "Condition.h"

using namespace std;

extern list<AsmInstruction*> asmInstrunctions;

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
  int startLineNo = asmInstrunctions.size();
  if(logicCondition == "<")
    Condition::gt(a,b);
  else if(logicCondition == ">")
    Condition::gt(b,a);
  else if(logicCondition == ">=")
    Condition::gte(b,a);
  else if(logicCondition == "<=")
    Condition::gte(a,b);
  int afterConditionLineNo = asmInstrunctions.size();
  asmInstrunctions.push_back(new AsmInstruction("JZERO", "END"));
}
