#pragma once

class Node
{
	private:
		//This could be any data type
		int data;
		//This will be a pointer for the next Node
		Node *left;
		Node *right;
	public:
		//Basic constructors
		Node();
		Node(int data);
		Node(int data, Node* left, Node* right);

		//Basic accessor method
		int getData();
		Node *getLeft();
		Node *getRight();

		//Basic setter method
		void setData(int data);
		void setLeft(Node *left);
		void setRight(Node *right);
};
