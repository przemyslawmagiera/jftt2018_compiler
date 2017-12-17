#include <string>
#include <cstdlib>
#include <list>
#include <map>

using namespace std;

extern void determineAndExecuteExpressionOperation(string arg1,string arg2,string oper, int gte);

class Condition
{
	public:
    static int gt(string, string);
    static int gte(string, string);
};
int gt(string a, string b)
{
  determineAndExecuteExpressionOperation(a,b,"-", 0);
}
int gte(string a, string b)
{
  determineAndExecuteExpressionOperation(a,b,"-", 1);
}
