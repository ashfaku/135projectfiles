#pragma once

template <class T>
class MyVector
{
	public:
		MyVector();
		int size();
		int capacity();
		bool empty();
		void push_back(T i);
		void pop_back(int n);
		void pop_back();
		void clear();
		void print();
	private:
		int current, cap;
		T* nums;
};

#include "myvector.cxx"
