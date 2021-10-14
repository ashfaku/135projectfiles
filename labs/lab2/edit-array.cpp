
/*
	Author: Ashfak Uddin
	Course: CSCI-136
	Instructor: Mike Zamansky
	Assignment: Lab2C

	This file lets a user edit an array with a length of 10 by inputting indicies and values, untl they enter an invalid index.

*/
#include <iostream>
void print(int a[], int size)
{
	for (int i = 0; i < size; i++)
  		std::cout << a[i] << (i != size - 1? ", " : "\n");
}
bool isValidIndex(int a, int lowerBound, int upperBound)
{
	return a >= lowerBound && a < upperBound;
}
int main()
{
	int data[10];
	for (int i = 0; i < 10; i++)
	     data[i] = 1;
	print(data, 10);
	int index, value;
	std::cout << "Input index: ";
	std::cin >> index;
	std::cout << "Input value: ";
	std::cin >> value;
	while (isValidIndex(index, 0, 10))
	{
		data[index] = value;
		print(data, 10);
		std::cout << "Input index: ";
		std::cin >> index;
		std::cout << "Input value: ";
		std::cin >> value;
	}
	std::cout << "Index out of range. Exit." << std::endl;
	return 0;
}

