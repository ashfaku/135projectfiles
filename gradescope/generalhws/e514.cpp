#include <iostream>
using std::cout;
using std::endl;
void sort2(int& a, int& b)
{
	if (a > b)
	{
		int h = a;
		a = b;
		b = h;
	}
}
int main()
{
	int a = 3, b = 2;
	sort2(a, b);
	return 0;
}

