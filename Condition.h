#include <string>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

extern int constructValueToRegister(int value);
extern void determineAndExecuteExpressionOperation(string arg1,string arg2,string oper, int gte);
extern vector<AsmInstruction*> asmInstrunctions;

class Condition
{
	public:
    static int gt(string, string);
    static int gte(string, string);
    static int eq(string, string);
    static int neq(string, string);
};
int gt(string a, string b)
{
  determineAndExecuteExpressionOperation(a,b,"-", 0);
}
int gte(string a, string b)
{
  determineAndExecuteExpressionOperation(a,b,"-", 1);
}
int eq(string a, string b)
{
  determineAndExecuteExpressionOperation(a,b,"-", 0);
  asmInstrunctions.push_back(new AsmInstruction("STORE", 0));
  determineAndExecuteExpressionOperation(b,a,"-", 0);
  asmInstrunctions.push_back(new AsmInstruction("STORE", 1));
  constructValueToRegister(1);
  asmInstrunctions.push_back(new AsmInstruction("SUB", 0));
  asmInstrunctions.push_back(new AsmInstruction("SUB", 1));
}
