#include "myvector.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	MyVector<int> v;
	cout << "Initial size: " << v.size() << endl;
	cout << "Initial capacity: " << v.capacity() << endl;
	cout << "It is " << (v.empty() ? "true" : "false") << " that the initial vector is empty" << endl;
	v.push_back(10);
	v.push_back(15);
	v.push_back(11);
	v.push_back(12);
	v.push_back(1000);
	v.push_back(-1);
	v.push_back(0);
	cout << "Vector now has a size of " << v.size() << " by adding 10, 15, 11, 12, 1000, -1, and 0 to it" << endl;
	cout << "Vector now has capacity of " << v.capacity() << endl;
	v.pop_back();
	cout << "Removed last element of vector, now has size of " << v.size() << endl;
	cout << "Vector is now ";
	v.print();
	v.pop_back(1);
	cout << "Removed second element of vector, vector is now ";
	v.print();
	v.clear();
	cout << "Vector is now empty with a size of " << v.size() << endl;
	cout << "Now, it is " << (v.empty() ? "true" : "false") << " that the vector is empty" << endl;
	return 0;
}
