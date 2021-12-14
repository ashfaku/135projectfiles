#include <iostream>
using namespace std;
int unbalanced_brackets(string input)
{
	int i = 0;
	for (char s : input)
	     i += (s == '{' ? 1 : s == '}' ? -1 : 0);
	 return i;
}
