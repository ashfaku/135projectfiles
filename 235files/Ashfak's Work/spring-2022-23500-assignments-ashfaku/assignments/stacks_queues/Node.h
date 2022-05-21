#pragma once

class Node
{
	private:
		//This could be any data type
		int data;
		//This will be a pointer for the next Node
		Node *next;
	public:
		//Basic constructors
		Node();
		Node(int data);
		Node(int data, Node* next);

		//Basic accessor method
		int getData();
		Node *getNext();

		//Basic setter method
		void setData(int data);
		void setNext(Node *next);
};
