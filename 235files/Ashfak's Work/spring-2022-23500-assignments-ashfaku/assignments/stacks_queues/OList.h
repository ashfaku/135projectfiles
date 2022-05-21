#pragma once
#include <iostream>
#include "Node.h"
class OList
{
	private:
		Node *head;
	public:
		OList();
		~OList();
		void insert(int value);
		std::string toString();
		bool contains(int value);
		int get(int n);
		void remove(int loc);
		void reverse();
};
