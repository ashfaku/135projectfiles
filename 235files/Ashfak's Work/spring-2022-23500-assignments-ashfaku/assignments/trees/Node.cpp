#include <iostream>
#include "Node.h"

Node::Node()
{
	left = nullptr;
	right = nullptr;
	data = 0;
}

Node::Node(int d)
{
	data = d;
	left = nullptr;
	right = nullptr;
}

Node::Node(int d, Node *left, Node *right)
{
	data = d;
	this->left = left;
	this->right = right;
}

int Node::getData()
{
	return this->data;
}

Node *Node::getLeft()
{
	return this->left;
}

Node *Node::getRight()
{
	return this->right;
}
void Node::setData(int data)
{
	this->data = data;
}

void Node::setLeft(Node *left)
{
	this->left = left;
}

void Node::setRight(Node *right)
{
	this->right = right;
}
