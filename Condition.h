#include <string>
#include <cstdlib>
#include <list>
#include <map>

using namespace std;

extern void determineAndExecuteExpressionOperation(string arg1,string arg2,string oper);

class Condition
{
	public:
    static int gt(string, string);
    static int gte(string, string);
};
/* w akumulatorze znajdzie się coś większego od zera jeśli to prawda*/
int gt(sting a, string b)
{
  determineAndExecuteExpressionOperation(a,b,"-");
}
/* w akumulatorze == 0 jeśli to prawda*/
int gte(sting a, string b)
{
  determineAndExecuteExpressionOperation(b,a,"-");
}
