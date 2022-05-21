#include <iostream>
using std::cout;
using std::endl;

int stepPerms(int n)
{
	if (n < 1)
		return 0;
	if (n < 3)
		return n;
	if (n == 3)
		return 4;
	return stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3);
}
void print(int n)
{
	cout << "n value: " << n << ", stepPerms(n): " << stepPerms(n) << endl;
}
int main()
{
	print(5);
	print(7);
	print(15);
	print(12);
	print(21);
	print(26);
	return 0;
}
