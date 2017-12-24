#include <cstdlib>

using namespace std;

// 0 - num, 1-normal, 2- array
class Variable
{
	public:
		long long value;
    long long index;
    string name;
		int type;
		Variable(string, int);
		Variable(long long);
};

Variable::Variable(string name, int type, long long index)
{
	this->type = type;
	this->name = name;
}

Variable::Variable(long long value)
{
	this->value = value;
  this->type = 0;
}
