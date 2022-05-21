#pragma once
#include "Person.h"

class Node{
	private:
	Person* data;
	Node *next;

	public:
	Node();
	Node(Person* data);
	Node(Person* data, Node *next);

	void setData(Person* data);
	void setNext(Node *next);

	Person* getData();
	Node* getNext();
};
