// <Your name>
// Main file for Part2(b) of Homework 2.
// Code will compile and run after you have completed sequence_map.h.

#include "avl_tree.h"
//#include "sequence_map.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

namespace {

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.
template <typename TreeType>
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
	// Code for running Part2(b)
	a_tree.parse(db_filename);
	
	ifstream sequences(seq_filename);
	string sequence;
	int successfulQueries = 0;
	int totalRecursiveCalls = 0;
	while (sequences >> sequence)
	{
		SequenceMap seqmap(sequence, "");
		int find = a_tree.find(seqmap);
		totalRecursiveCalls += find;
		if (find != 0)
		{
			successfulQueries++;
		}
	}

	int nodeCount = a_tree.getNodeCount();
	double internalPathLength = a_tree.getPathLength();
	cout << "2: " << nodeCount << endl;
	cout << "3a: " << internalPathLength / nodeCount << endl;
	cout << "3b: " << internalPathLength / nodeCount / nodeCount << endl;
	cout << "4a: " << successfulQueries << endl;
	cout << "4b: " << totalRecursiveCalls / (double) successfulQueries << endl;

	ifstream sequence_removal(seq_filename);
//	int howMuchToAdd = 1;
//	int removeIndex = 0;
//	int currIndex = 0;
	int removalCount = 0;
	int removals = 0;
	while (sequence_removal >> sequence)
	{
		SequenceMap map(sequence, "");
		int c = a_tree.checkRemovable(map);
		if (c != 0)
			removals++;
		removalCount += c;
		sequence_removal >> sequence;
	/*	if (removeIndex == currIndex)
		{
			SequenceMap seqmap(sequence, "");
			a_tree.remove(seqmap);
			cout << "index: " << removeIndex << endl;
			removals++;
			removeIndex += howMuchToAdd;
			howMuchToAdd++; 
		}
		currIndex++;
	*/}
//	cout << a_tree.getMinCount() << " " << removalCount << endl;
	cout << "5a: " << nodeCount - a_tree.getNodeCount() << endl;
	cout << "5b: " << (a_tree.getMinCount() + removalCount) / ((float) removals) << endl;
	cout << "6a: " << a_tree.getNodeCount() << endl;
	cout << "6b: " << a_tree.getPathLength() / (double) a_tree.getNodeCount() << endl;
	cout << "6c: " << a_tree.getPathLength() / (double) a_tree.getNodeCount() / a_tree.getNodeCount() << endl;
}

}  // namespace

int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
		return 0;
	}
	const string db_filename(argv[1]);
	const string seq_filename(argv[2]);

	cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;

	AvlTree<SequenceMap> a_tree;
	TestTree(db_filename, seq_filename, a_tree);

	return 0;
}
