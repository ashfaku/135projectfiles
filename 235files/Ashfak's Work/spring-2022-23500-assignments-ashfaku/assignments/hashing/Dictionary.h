#pragma once
#include <iostream>
#include "Node.h"
#include "Person.h"
#include "OList.h"

class Dictionary{
	private:
		OList* list[10];
		int size;
	public:
		Dictionary();
		~Dictionary();
		void insertPerson(Person *&p);
		void runTests();
		int getSize();
		Person* retrievePerson(Person *&p);
		std::string getKeys();
};
