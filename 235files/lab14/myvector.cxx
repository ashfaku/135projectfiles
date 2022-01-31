#include "myvector.h"
#include <iostream>
using std::cout;
using std::endl;
template <class T>
MyVector<T>::MyVector()
{
	current = 0;
	cap = 5;
	nums = new T[cap];
}
template <class T>
int MyVector<T>::size()
{
	return current;
}
template <class T>
int MyVector<T>::capacity()
{
	return cap;
}
template <class T>
bool MyVector<T>::empty()
{
	return size == 0;
}
template <class T>
void MyVector<T>::print()
{
	for (int i = 0; i < current; i++)
		std::cout << nums[i] << " ";
	std::cout << std::endl;
}
template <class T>
void MyVector<T>::push_back(T i)
{
	if (cap <= current)
	{
		cap *= 2;
		T* data = new T[current];
		for (int i = 0; i < current; i++)
			data[i] = nums[i];
		nums = new T[cap];
		for (int i = 0; i < current; i++)
			nums[i] = data[i];
	}
	nums[current++] = i;
}
template <class T>
void MyVector<T>::pop_back()
{
	if (current > 0)
	{
		T* data = new T[current];
		for (int i = 0; i < current - 1; i++)
			data[i] = nums[i];
		nums = new T[--current];
		for (int i = 0; i < current; i++)
			nums[i] = data[i];
	}
	else
	{
		current = 0;
		cap = 5;
		nums = new T[cap];
	}
}
template <class T>
void MyVector<T>::pop_back(int n)
{
	cout << current << endl;
	if (current > 0)
	{
		T* left = new T[n];
		T* right = new T[current - n - 1];
		for (int i = 0; i < n; i++)
			left[i] = nums[i];
		for (int i = n + 1; i < current; i++)
			right[i - n - 1] = nums[i];
		nums = new T[--current];
		for (int i = 0; i < n; i++)
			cout << left[i] << endl;
		cout << "-----" << endl;
		for (int i = 0; i < current - n; i++)
			cout << right[i] << endl;
		for (int i = 0; i < n; i++)
			nums[i] = left[i];
		for (int i = n; i < current; i++)
			nums[i] = right[i - n];
	}
}
template <class T>
void MyVector<T>::clear()
{
	current = 0;
	cap = 5;
	nums = new T[cap];
}
