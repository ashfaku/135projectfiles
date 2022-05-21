#include <iostream>
#include "OList.h"
using std::cout;
using std::endl;
using std::string;

int main()
{
	OList l;
	l.insert(10);
	l.insert(4);
	l.insert(3);
	l.insert(7);
	l.insert(11);
	l.insert(-5);
	l.insert(-9);
	cout << l.toString() << endl;
	l.remove(1);
	cout << l.toString() << endl;
	l.reverse();
	cout << l.toString() << endl;
	return 0;
}
