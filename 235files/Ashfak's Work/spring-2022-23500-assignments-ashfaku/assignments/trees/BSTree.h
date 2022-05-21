#pragma once
#include <iostream>
#include "Node.h"
class BSTree
{
	private:
		Node* root;
		void rinsert(int value, Node **root, bool& check);
		int rsearch(int value, Node *root);
		std::string get_debug_string_helper(Node* root);
		void deleteNode(int value, Node** root, Node ** parent, bool& check);
		void print(Node* head, int height, char d);
		int height(Node* head);
//		void printLevel(Node* root, int lev, int tab, int c);
		int getLevel(Node* head, int n);
		int sumLevel(Node* head, int lev);
		int countLeaves(Node* head);
	public:
		BSTree();
		void insert(int data);
		int rsearch(int value);
		void rinsert(int value);
		std::string get_debug_string();
		Node * getRoot();
		void deleteNode(int value);
		void setup();
		void print();
		int height();
		int getLevel(int n);
		int sumLevel(int lev);
		int countLeaves();
};
