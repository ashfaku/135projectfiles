#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

using std::cout;
using std::endl;
using std::vector;
void print_vector(vector<int> a)
{
	for (auto i : a)
		cout << i << " ";
	cout << endl;
}
int find_min_index(vector<int> a, int start_index, int stop_index){
	int min_index = start_index, i;
	for (i = start_index;i < stop_index;i++)
	{
		if (a[i] < a[min_index])
			min_index = i;
	}
	return min_index;
}

vector<int> ssort(vector<int> a)
{
	int i,min_index,j,tmp;
	int len = a.size();
	// loop through the vector from 0 to end
	for (i = 0; i < len;i++)
	{
		// find the smallest value from i to the end
		min_index = find_min_index(a,i,len);
		tmp = a[i];
		a[i] = a[min_index];
		a[min_index] = tmp;

	}
	return a;
}

/*
  left and right are already sorted
3  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
vector<int> merge(vector<int> left, std::vector<int> right)
{
	vector<int> merged;

	// your code here
	int l = 0;
	int r = 0;

	while (l < left.size() && r < right.size())
	{
		if (left[l] < right[r]){
			merged.push_back(left[l]);
			l++;
		}
		else
		{
			merged.push_back(right[r]);
			r++;
		}
	}

	// add any extra elements in left
	while (l < left.size())
	{
		merged.push_back(left[l]);
		l++;
	}
	// add any extra elements in right
	while (r < right.size())
	{
		merged.push_back(right[r]);
		r++;
	}
	return merged;
}
vector<int> msort(vector<int> v)
{
	vector<int> left, right;
	int i;
	if (v.size() < 2)
		return v;
	for (i = 0; i < v.size() / 2; i++)
		left.push_back(v[i]);
	for (; i < v.size(); i++)
		right.push_back(v[i]);
	return merge(msort(left), msort(right));
}
std::vector<int> qsort(std::vector<int> list)
{

    int i, j;

    // base case
    if (list.size() <= 1)
    {
        return list;
    }

    // select a pivot value.
    // for now, just pick list[0]
    int pivot = list[0];

    // make 2 new vectors
    std::vector<int> lower, higher;

    // copy all the values < pivot value to lower
    // copy all the values >= pivot value to higher;
    for (i = 1; i < list.size(); i++)
    {
        if (list[i] < pivot)
        {
            lower.push_back(list[i]);
        }
        else
        {
            higher.push_back(list[i]);
        }
    }

    lower = qsort(lower);
    higher = qsort(higher);

    // copy everything back into list
    for (i = 0; i < lower.size(); i++)
    {
        list[i] = lower[i];
    }

    list[i] = pivot;
    i++;

    for (j = 0; j < higher.size(); j++)
    {
        list[i] = higher[j];
        i++;
    }

    // return the sorted list
    return list;
}
bool check(vector<int> a, int left, int right)
{
	for (int i = left; i < right - 1; i++)
		if (a[i] > a[i+1])
			return false;
	return true;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// from https://www.geeksforgeeks.org
int partition(std::vector<int> &arr, int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
 
/* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
void qsort(std::vector<int> &A, int l, int h)
{
    if (l < h) {
        /* Partitioning index */
        int p = partition(A, l, h);
        qsort(A, l, p - 1);
        qsort(A, p + 1, h);
    }
}



/*
this did not work for some data sets
void qsort(vector<int>& a, int left, int right)
{
	if (check(a, left, right))
	{
		return;
	}
	if (right - left <= 0)
		return;
	int pivotIndex, mid = (right + left) / 2;
	if (a[left] >= a[right] && a[left] >= a[mid])
		pivotIndex = left;
	else if (a[mid] >= a[left] && a[mid] >= a[right])
		pivotIndex = mid;
	else
		pivotIndex = right;
	int pivot = a[pivotIndex], index = left - 1;
	for (int i = left; i <= right; i++)
	{
		if (a[i] < pivot)
		{
			index++;
			int hold = a[i];
			a[i] = a[index];
			a[index] = hold;
		}
	}
	if (mid == left || mid == right)
		return;
	print_vector(a);
	cout << left << " " << right << endl;
	qsort(a, left, index);
	qsort(a, index, right);
}*/
int main()
{
	srand(time(NULL));
	vector<int> a;
	for (int i = 0; i < 1000000; i++)
		a.push_back(rand() % 100);
	qsort(a, 0, a.size() - 1);
	print_vector(a);
	return 0;
}
