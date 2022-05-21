#pragma once
#include "OList.h"

class Stack
{
	private:
		OList dataList;
		int topindex = 0;
	public:
		void push(int d);
		int pop();
		int top();
		bool is_empty();
		bool is_full();
};
