#include "myvector.h"
int main()
{
	MyVector<std::string> t;
	t.push_back("hi");
	t.push_back("my");
	t.push_back("name");
	t.push_back("is");
	t.push_back("john");
	t.print();
	t.pop_back(0);
	t.print();
	cout << t[2];
	return 0;
}
