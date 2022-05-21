#include <iostream>
#include "OList.h"
#include "Node.h"
OList::OList()
{
	head = nullptr;
}
OList::~OList()
{
	Node *trailer;
	while(head != nullptr)
	{
		trailer = head;
		head = head->getNext();
		delete trailer;
	}
}
void OList::insert(int value)
{
	Node *newNode = new Node(value);
	Node *walker = head;
	Node* trailer = nullptr;
	while (walker != nullptr)
	{
		trailer = walker;
		walker = walker->getNext();
	}
	if (trailer == nullptr)
	{
		newNode->setNext(head);
        	head = newNode;
	}
	else
	{
		trailer->setNext(newNode);
		newNode->setNext(walker);
	}
}
int OList::get(int loc)
{
	int c = 0;
	Node *walker = head;
	while (walker != nullptr && c < loc)
	{
		walker = walker->getNext();
		c++;
	}
	if (c == loc)
		return walker->getData();
	throw std::out_of_range("Input index is not within range of list size");
}
void OList::remove(int n)
{
	if (n == 0)
	{
		head->setNext(nullptr);
		head = nullptr;
		return;
	}
	Node* walker = head;
	int c = 1; // removing the head is a bad idea
	while (walker != nullptr)
	{
		if (c == n)
		{
			Node* del = walker->getNext();
			walker->setNext(del->getNext());
			delete del;
			return;
		}
		walker = walker->getNext();
		c++;
	}
	throw std::out_of_range("Input index is not within range of list size");
}
bool OList::contains(int value)
{
	Node* walker = head;
	while (walker != nullptr)
	{
		if (walker->getData() > value)
			break;
		if (walker->getData() == value)
			return true;
		walker = walker->getNext();
	}
	return false;
}
std::string OList::toString()
{
	Node *walker = head;
	std::string l = "head-->";
	while (walker != nullptr)
	{
		l += std::to_string(walker->getData()) + "-->";
		walker = walker->getNext();
	//	std::cout << l << std::endl;
	}
	l += "nullptr";
	return l;
}
void OList::reverse()
{         // t = -9, f = null, h = -9
	Node *trailer = head, *future = nullptr;
	if (head == nullptr)
		return;
	if (head != nullptr && head->getNext() != nullptr)
		head = head->getNext();
	if (head != nullptr)
		future = head->getNext();
	trailer->setNext(nullptr);
	if (head != nullptr && trailer != head)
		head->setNext(trailer);
	while (future != nullptr && future->getNext() != nullptr)
	{
		trailer = future;
		future = future->getNext();
		trailer->setNext(head);
		head = trailer;
	}
	if (future != nullptr)
	{
		future->setNext(trailer);
		head = future;
	}
}
