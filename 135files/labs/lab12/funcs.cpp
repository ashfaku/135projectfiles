#include <vector>
#include "funcs.h"
using std::vector;
vector<int> makeVector(int n)
{
	vector<int> r;
	for (int i = 0; i < n; i++)
		r.push_back(i);
	return r;
}
vector<int> goodVibes(const vector<int> &v)
{
	vector<int> r;
	for (int i: v)
		if (i > 0)
			r.push_back(i);
	return r;
}
void gogeta(vector<int> &goku, vector<int> &vegeta) // vegito they should've said
{
	for (int i : vegeta)
		goku.push_back(i);
	vegeta.clear();
}
vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2)
{
	vector<int> r;
	int max = std::max(v1.size(), v2.size());
	for (int i = 0; i < max; i++)
	{
		int sum = (i < v1.size() ? v1[i] : 0) + (i < v2.size() ? v2[i] : 0);
		r.push_back(sum);
	}
	return r;
}
