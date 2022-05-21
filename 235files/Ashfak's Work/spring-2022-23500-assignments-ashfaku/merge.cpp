#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
void print_vector(vector<int> a)
{
	for (auto i: a)
		cout << i << " ";
	cout << endl;
}
//so we just create a function to merge the two together, 0 --- 100

// 1 2 4
// 2 3 5

// 1 2 2 3 4 5
vector<int> merge(vector<int> left, vector<int> right)
{
	vector<int> merged;
	int size = std::max(left.size(), right.size());
	for (int i = 0; i < size; i++)
	{
		if (i < left.size() && i < right.size())
		{
			if (left[i] <= right[i])
			{
				merged.push_back(left[i]);
				left.erase(left.begin(), left.begin() + 1);
			}
			else
			{
				merged.push_back(right[i]);
				right.erase(right.begin(), right.begin() + 1);
			}
			i--;
		}
	}
	for (int i = 0; i < left.size(); i++)
		merged.push_back(left[i]);
	for (int i = 0; i < right.size(); i++)
		merged.push_back(right[i]);
	return merged;
}
int main()
{
	vector<int> a, b;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	b.push_back(3);
	b.push_back(5);
	vector<int> c = merge(a, b);
	print_vector(a);
	print_vector(b);
	print_vector(c);
	return 0;
}
