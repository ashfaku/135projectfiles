#include "BSTree.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
BSTree::BSTree()
{
	root = nullptr;
}
Node* BSTree::getRoot()
{
	return root;
}
int BSTree::height()
{
	return height(root);
}
int BSTree::height(Node* head)
{
	if (head == nullptr)
		return 0;
	if (head->getLeft() == nullptr && head->getRight() == nullptr)
		return 1;
	return 1 + std::max(height(head->getLeft()), height(head->getRight()));
}
int BSTree::sumLevel(Node* root, int lev)
{
	if (lev == 1)
        {
                if (root != nullptr)
			return root->getData();
                return 0;
        }
        return sumLevel(root == nullptr ? nullptr : root->getLeft(), lev - 1) +
		sumLevel(root == nullptr ? nullptr : root->getRight(), lev - 1);
}
int BSTree::sumLevel(int lev)
{
	if (lev > height(root) || lev < 1) // invalid level at that point
		return 0;
	return sumLevel(root, lev);
}
int BSTree::getLevel(Node* head, int n)
{
	if (head == nullptr)
		return -1;
	if (head->getData() == n)
		return 1;
	if (head->getData() < n)
		return 1 + getLevel(head->getRight(), n);
	return 1 + getLevel(head->getLeft(), n);
}
int BSTree::getLevel(int n)
{
	return getLevel(root, n);
}

int BSTree::countLeaves(Node* head)
{
	if (head == nullptr)
		return 0;
	if (head->getLeft() == nullptr && head->getRight() == nullptr)
		return 1;
	return countLeaves(head->getLeft()) + countLeaves(head->getRight());
}
int BSTree::countLeaves()
{
	return countLeaves(root);
}
// height 1, 1 tab
//	10


//height 2, 2 tab
//		10
//	5		25


//2^(height-level)


//height 3, 4 tab
//				10
//		5				25
//	2		7		12		26



// height 4, 8 tab
//								10
//				5								25
//		2				7				12				27
//	1		3		6		8		11		13		26		28
/*

man i tried, terminal width was too bothersome to get around and i had one tabbing issue i dont have the time to fix
with this format :(
void BSTree::printLevel(Node* root, int lev, int tab, int c)
{
//	cout << lev << endl;
	if (lev == 1)
	{
		for (int i = 0; i < tab; i++)
			cout << "\t";
		if (root != nullptr)
			cout << root->getData();
		return;
	}
	else
	{
		level(root == nullptr ? nullptr : root->getLeft(), lev - 1, tab/2, c);
			//cout << lev << endl;
		level(root == nullptr ? nullptr : root->getRight(), lev - 1, (c == 0 ? tab : tab/2));
	}
}
*/
void BSTree::print(Node* head, int h, char d)
{
/*	if (head == nullptr)
		return;
	int pow = std::pow(2, h - 1);
	for (int i = 0; i < h; i++)
	{
		printLevel(root, i+1, pow, 0);
		cout << endl;
	}
*/
	if (root == nullptr)
		return;
	if (h > 0)
		cout << "|";
	for (int i = 0; i < h; i++)
		cout << "\t";
	cout << (d == 'l' ? "Left " : (d == 'r' ? "Right " : "Head "));
	cout <<  (head == nullptr ? "null" : std::to_string(head->getData())) << endl << "|" << endl;
	if (head == nullptr)
		return;
	print(head->getLeft(), h+1, 'l');
	print(head->getRight(), h+1, 'r');
}
void BSTree::print()
{
	print(root, 0, 'p');
}
void BSTree::deleteNode(int value, Node **current, Node **parent, bool& check)
{
	if (*current == nullptr && check)
                throw 1;
	if (!check)
		return;
        int data = (*current)->getData();
	Node* left = (*current)->getLeft();
	Node* right = (*current)->getRight();
	if (data == value)
	{
		if (left != nullptr && right != nullptr)
		{
			Node* hold = right;
			while (right->getLeft() != nullptr)
				right = right->getLeft();
			(*current)->setData(right->getData());
			bool check1 = true;
			deleteNode(right->getData(), &hold, current, check1);
			(*current)->setRight(hold);
			(*current)->setLeft(left);
		}
		else
		{
			if (*current == root)
			{
				if (left == nullptr)
					root = right;
				else if (right == nullptr)
					root = left;
				else
					root = nullptr;
				return;
			}
			if (parent != nullptr && *parent != nullptr)
			{
				if (data > (*parent)->getData())
					(*parent)->setRight(left);
				else
					(*parent)->setLeft(right);
			}
			delete *current;
			*current = nullptr;
			current = nullptr;
		}
		check = false;
                return;
        }
	if (!check)
		return;
	if (data < value)
                deleteNode(value, &right, current, check);
	deleteNode(value, &left, current, check);
}
void BSTree::deleteNode(int value)
{
	bool check = true;
	deleteNode(value, &root, nullptr, check);
}
int BSTree::rsearch(int value, Node *root)
{
	if (root == nullptr)
		throw 1;
	int data = root->getData();
	if (data == value)
		return value;
	if (data < value)
		return rsearch(value, root->getRight());
	return rsearch(value, root->getLeft());
}
int BSTree::rsearch(int value)
{
	return rsearch(value, root);
}
void BSTree::rinsert(int value, Node **r, bool& check)
{
	if (*r == nullptr)
	{
		Node *hold = new Node(value);
		*r = hold;
		check = false;
		return;
	}
	int data = (*r)->getData();
	if (data == value && check)
	{
		check = false;
		return; // already in the tree
	}
	Node *left = (*r)->getLeft();
	Node *right = (*r)->getRight();
	if (data < value && check) // we go right
		rinsert(value, &right, check);
	if (data > value && check) // we go left
		rinsert(value, &left, check);

	(*r)->setRight(right); // cleanup after all the recursion
	(*r)->setLeft(left);
}
void BSTree::rinsert(int value)
{
	bool check = true; // similar to the maze recursion, i want any other recursive branches to stop when my value got inserted
	rinsert(value, &root, check);
}
void BSTree::insert(int value) // iterative insert
{
	// make a new node
	Node *newnode = new Node(value);

	// search for where the node would go as a leaf
	// that is, search until we get to null
	// we can use the piggyback strategy of having
	// a second pointer trail the lead pointer
	Node *p = root;
	Node *trailer;


	while (p != nullptr)
	{
		// note that trailer is one level behind
		trailer = p;
		if (p->getData() == value)
		{
			// do the stuff when the node is already in the tree
			return;
		}
		else if (p->getData() < value)
		{
			p = p->getRight();
		}
		else
		{
			p = p->getLeft();
		}
	}

	// handle the special case of the tree
	// being empty (null)
	if (root==nullptr)
	{
		root=newnode;
	}
	else
	{
		// trailer points to the node ABOVE where the new node
		// will go.
		// we have to figure out if newnode goes on the
		// left of trailer or on the right of trailer
		if (trailer->getData() < value)
		{
			trailer->setRight(newnode);
		}
		else
		{
			trailer->setLeft(newnode);
		}
	}
}
std::string BSTree::get_debug_string_helper(Node *root)
{
	if (root == nullptr)
		return "";
	Node *left = root->getLeft();
	Node *right = root->getRight();
	int data = root->getData();
	if (left == nullptr && right == nullptr)
		return std::to_string(data);
	if (left == nullptr)
		return std::to_string(data) + " " + get_debug_string_helper(right);
	if (right == nullptr)
		return std::to_string(data) + " " + get_debug_string_helper(left);
	return std::to_string(data) + " " + get_debug_string_helper(left) + " " + get_debug_string_helper(right);
}
std::string BSTree::get_debug_string()
{
	return get_debug_string_helper(root);
}
void BSTree::setup()
{
	root = new Node(1);
	Node *l = new Node(2), *r = new Node(3);
	root->setLeft(l);
	root->setRight(r);
	Node *l2 = new Node(4);
	Node *l3 = new Node(5);
	Node *l4 = new Node(6);
	Node *l5 = new Node(7);
	l->setLeft(l2);
	l->setRight(l3);
	r->setLeft(l4);
	r->setRight(l5);
}
