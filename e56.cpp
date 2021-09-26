#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	std::string s;
	cin >> s;
	cout << (s.length() % 2 == 1 ? s.at(s.length() / 2) : s.at(s.length() / 2 - 1) + s.at(s.length() / 2)) << endl;
	return 0;
}
