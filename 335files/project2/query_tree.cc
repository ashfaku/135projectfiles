// <Your name>
// Main file for Part2(a) of Homework 2.
// Code will compile and run after you have completed sequence_map.h.

#include "avl_tree.h"
//#include "sequence_map.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

namespace {


// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void QueryTree(const string &db_filename, TreeType &a_tree) {
	// Code for running Part2(a)
	// Parse input file @db_filename and feel tree @a_tree
	// Then prompt the user for exactly three strings (do a loop) and
	// provide the results of find() as described in the assignment.
	a_tree.parse(db_filename);
    string holder;
	while (cin >> holder)
	{
        SequenceMap h(holder, "");
		if (!a_tree.printNode(h))
		{
			cout << "Not Found" << endl;
		}
	}
}

}  // namespace

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
		return 0;
	}
	const string db_filename(argv[1]);
	
	cout << "Input filename is " << db_filename << endl;
	AvlTree<SequenceMap> a_tree;
	QueryTree(db_filename, a_tree);

	return 0;
}
