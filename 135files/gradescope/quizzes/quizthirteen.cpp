#include <iostream>
#include <vector>
using namespace std;
vector<int> makeVector(int n)
{
	vector<int> r;
	for (int i = 0; i < n; i++)
		r.push_back(i);
	return r;
}
