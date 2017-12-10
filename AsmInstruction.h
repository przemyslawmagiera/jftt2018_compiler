#include <string>
#include <cstdlib>

class AsmInstruction
{
	public:
    std::string name;
    int arg;
    AsmInstruction(std::string,int);
    AsmInstruction(std::string);
		std::string toString()
		{
      if(arg == -1)
			  return name;
      else
        return name + " " + std::to_string(arg);
		}
};

AsmInstruction::AsmInstruction(std::string aName, int anArg)
{
  name = aName;
  arg = anArg;
}

AsmInstruction::AsmInstruction(std::string aName)
{
  name = aName;
  arg = -1;
}
