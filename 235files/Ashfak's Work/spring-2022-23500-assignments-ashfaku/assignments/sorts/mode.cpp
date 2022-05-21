#include <iostream>
#include <vector>
#include <climits>
using std::vector;
using std::cout;
using std::endl;
int count(vector<int> v, int value)
{
	int c = 0;
	for (int i: v)
		c += (i == value ? 1 : 0);
	return c;
}
int largest(vector<int> v)
{
	int large = INT_MIN;
	for (int i: v)
		large = (i > large ? i : large);
	return large;
}
bool contains(vector<int> v, int val)
{
	for (int i: v)
		if (i == val)
			return true;
	return false;
}
int mode(std::vector<int> v)
{
	int mode = INT_MIN, num, c;
	if (v.size() == 0)
		throw std::length_error("There cannot be a mode with a list of 0 elements");
	vector<int> l; // so i dont count each number more than once maybe
	for (int i : v)
	{
		if (!contains(l, i) && (c = count(v, i)) >= mode)
		{
			mode = c;
			num = i;
		}
		if (!contains(l, i))
			l.push_back(i);
	}
	return num;
}
int main()
{
	vector<int> a = {1,2,2,3,4,5,1};
	cout << mode(a) << endl;
	return 0;
}
