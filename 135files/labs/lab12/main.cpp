#include "funcs.h"
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
void printVector(const vector<int> &p)
{
	for (int i : p)
		cout << i << " ";
	cout << endl;
}
void printMakeVector(int n)
{
	vector<int> p = makeVector(n);
	cout << "Length of " << n << ": ";
	printVector(p);
}
void printGoodVibes(const vector<int> &p)
{
	cout << "-------------------------------------------------------" << endl;
	cout << "The original vector: ";
	printVector(p);
	cout << "The goodVibes vector: ";
	printVector(goodVibes(p));
	cout << "-------------------------------------------------------" << endl;
}
void printPair(const vector<int> a, const vector<int> b)
{
	cout << "--------------------------------------------------------------------" << endl;
	cout << "The first vector is: ";
	printVector(a);
	cout << "The second vector is: ";
	printVector(b);
	cout << "The sumPairWise of the two vectors is: ";
	printVector(sumPairWise(a, b));
	cout << "--------------------------------------------------------------------" << endl;
}
void printFusion(vector<int> &goku, vector<int> &vegeta)
{
	cout << "The first fusion component is: ";
	printVector(goku);
	cout << "The second fusion component is: ";
	printVector(vegeta);
	cout << "And now they've fused, leaving first component with all elements combined and second component empty" << endl;
	gogeta(goku, vegeta);
	cout << "The first fusion component now is: ";
	printVector(goku);
	cout << "And the second fusion component's size is " << vegeta.size() << endl;
	cout << "--------------------------------------------------------------------" << endl;
}
int main()
{
	cout << "--------------------------------------------------------------------" << endl;
	cout << "Task A: makeVector(int n)" << endl;
	printMakeVector(10);
	printMakeVector(5);
	printMakeVector(7);
	cout << "--------------------------------------------------------------------" << endl;

	cout << "Task B: goodVibes(const vector<int> &p)" << endl;
	vector<int> t{1,2,3,-4,-5,-10,6}, t1{0,-9,2,3,4,-2, 4,-100,4}, t2{-2,-4,-6,-1,1};
	printGoodVibes(t);
	printGoodVibes(t1);
	printGoodVibes(t2);
	cout << "--------------------------------------------------------------------" << endl;
	cout << "Task C: gogeta function" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	vector<int> s{1,2,3,4,5,6}, s1{7,8,9,10,11};

	printFusion(t, t1);
	printFusion(s, s1);
	printFusion(t, s);

	cout << "Task D: sumPairWise function" << endl;
	vector<int> e{1,2,3}, e1{4,5}, f{4,5,6,7}, f1{2,3,4,5}, g{9,0,-1}, g1{-9,0,1};
	printPair(e, e1);
	printPair(f, f1);
	printPair(g, g1);

	return 0;

}
