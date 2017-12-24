#include <cstdlib>

using namespace std;

class MemoryItem
{
	public:
		long long cell;
		int array;
		int size;
		string name;
		MemoryItem(string, int, long long, int);
		MemoryItem(string, long long);
};

MemoryItem::MemoryItem(string name, int isInTable, long long memoryCell, int sizeOfContainingTable)
{
	this->array = isInTable;
	this->cell = memoryCell;
	this->size = sizeOfContainingTable;
	this->name = name;
}

MemoryItem::MemoryItem(string name, long long memoryCell)
{
	this->cell = memoryCell;
	this->name = name;
	this->array = 0;
	this->size = 1;
}
