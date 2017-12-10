#include <string>
#include <cstdlib>

class Identifier
{
	public:
    std::string name;
    int value;
    Identifier(std::string,int);
};

Identifier::Identifier(std::string aName, int anArg)
{
  name = aName;
  value = anArg;
}
