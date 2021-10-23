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
void sort3(int& a, int& b, int& c)

{
	sort2(a, b);
	sort2(a, c);
	sort2(b, c);
}
int main()
{
        int a = 3, b = 5, c = 1;
        sort3(a, b, c);
        cout << a << " " << b << " " << c;
        return 0;
}

