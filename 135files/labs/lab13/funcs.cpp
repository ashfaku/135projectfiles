#include "funcs.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
string printRange(int left, int right)
{
	if (left == right)
		return std::to_string(right);
	if (left > right)
		return "";
	return std::to_string(left) + " " + printRange(left + 1, right);
}
int sumRange(int left, int right)
{
	if (left == right)
		return right;
	if (left > right)
		return 0;
	return left + sumRange(left + 1, right);
}
int sumArray(int *arr, int size)
{
	if (size == 1)
		return *arr;
	if (size <= 0)
		return 0;
	return *arr + sumArray(arr + 1, size - 1);
}
bool isAlphaNumeric(string s)
{
	if (s.length() == 0)
		return true;
	if (!isalnum(s[0]))
		return false;
	return isAlphaNumeric(s.substr(1));
}

bool nestedParens(string s)
{
	if (s.length() == 0)
		return true;
	if (s.length() % 2 == 1)
		return false;
	if ((s[0] != '(' || s[s.length() - 1] != ')'))
		return false;
	return nestedParens(s.substr(1, s.length() - 2));
}
