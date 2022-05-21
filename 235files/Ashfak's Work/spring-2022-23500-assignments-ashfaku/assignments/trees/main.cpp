
#include "Node.h"
#include "BSTree.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
/*	Node *root = new Node(1);
	cout << root->getData() << endl;
	Node *left = new Node(2);
	Node *right = new Node(3);
	root->setLeft(left);
	root->setRight(right);
	cout << root->getLeft()->getData() << endl;
	cout << root->getRight()->getData() << endl;
	Node *left2 = new Node(4), *right2 = new Node(5), *left3 = new Node(6), *right3 = new Node(7);
	left->setLeft(left2);
	left->setRight(right2);
	right->setLeft(left3);
	right->setRight(right3);
	cout << left->getLeft()->getData() << " " << left->getRight()->getData() << " " << right->getLeft()->getData() << " " <<
	right->getRight()->getData() << endl;
*/
	BSTree *t = new BSTree();
//				1
//		-5				10
//	-10		-3		9		15

	t->rinsert(1);

	t->rinsert(14);
	t->rinsert(-5);
	t->rinsert(15);
	t->rinsert(9);
	t->rinsert(-10);
	t->rinsert(-3);
	t->rinsert(-1);
	t->rinsert(25);
	t->rinsert(12);
	t->rinsert(-7);
	t->rinsert(-4);
	t->rinsert(10);
	cout << t->countLeaves() << endl;
	t->print();
//	cout << t->get_debug_string() << endl;
//	t->deleteNode(10);
//	cout << "Check: " << t->getRoot()->getData() << endl;
//	cout << t->get_debug_string() << endl;
	return 0;
}

