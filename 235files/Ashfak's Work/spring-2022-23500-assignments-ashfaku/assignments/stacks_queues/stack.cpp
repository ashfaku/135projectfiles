#include "stack.h"
#include <iostream>

void Stack::push(int item)
{
	dataList.insert(item);
	topindex++;
}

int Stack::pop()
{
//	std::cout << "index: " << topindex << std::endl;
	if (topindex <= 0)
	{
		throw std::out_of_range("Cannot pop an empty list");
	}
	int tmp = dataList.get(topindex - 1);
//	std::cout << "tmp: " <<  tmp << std::endl;
	dataList.remove(topindex - 1);
	topindex--;
	return tmp;
}

int Stack::top()
{
	if (topindex <= 0)
	{
		throw std::out_of_range("Cannot get top of empty list");
	}
	return dataList.get(topindex - 1);
}

bool Stack::is_empty()
{
	return (dataList.toString() == "head-->nullptr");
}
bool Stack::is_full()
{
	return false;
	// ... a stack can never be full so long as there's memory? I didn't know what to do here
}
