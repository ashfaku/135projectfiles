#include <iostream>
#include "Dictionary.h"
#include "Node.h"
#include "Person.h"

Dictionary::Dictionary()
{
	size = 10;
	for (int i=0; i < getSize(); i++)
		list[i] = new OList();
}
Dictionary::~Dictionary()
{
	try
	{
		int size = getSize();
		for (int i=0; i<size; i++)
		{
			OList *l = list[i];
			Node* current = l->getHead();
			while (current != nullptr)
			{
				Node* next = current->getNext();
				delete current;
				current = next;
			}
			l->setHead(nullptr);
		}
	}
	catch(...)
	{
	}
}

int Dictionary::getSize()
{
	return size;
}
void Dictionary::insertPerson(Person *&p)
{
	try
	{
		std::string name = p->get_name();
		int hash = 0;
		for (int i=0; i < name.length(); i++)
			hash += name[i];
		int insertionIndex = (hash) % getSize();
		list[insertionIndex]->insert(p);
	}
	catch(...)
	{
		std::cout << "Error" << std::endl;
	}
	return;
}

Person* Dictionary::retrievePerson(Person *&p)
{
	try
	{
		std::string name = p->get_name();
		int hashValue = 0;
		for (int i = 0; i < name.length(); i++)
			hashValue += name[i];
		int insertionIndex = (hashValue) % getSize();
		Node *node = list[insertionIndex]->getHead();
		while (node != nullptr)
		{
			std::string searchName = node->getData()->get_name();
			if (name == searchName)
				return node->getData();
			else
				node = node->getNext();
		}
	}
	catch(...)
	{
		std::cout << "Error in retrieving Person." << std::endl;
	}
	throw std::out_of_range("Null value"); // or return nullptr? had no clue which one to do here
}
std::string Dictionary::getKeys()
{
	std::string keys = "";
	try
	{
		int size = getSize();
		for (auto i=0; i<size; i++)
		{
			OList *l = list[i];
			Node* current = l->getHead();
			while (current != nullptr)
			{
				keys = keys + current->getData()->get_name() + "\n";
				current = current->getNext();
			}
		}
	}
	catch(...)
	{
		std::cout << "Invalid attempt to retrieve keys." << std::endl;
	}
	return keys;
}
