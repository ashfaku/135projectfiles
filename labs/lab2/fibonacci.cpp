/*
	Author: Ashfak Uddin
	Course: CSCI-136
	Instructor: Mike Zamansky
	Assignment: Lab2D
	This file prints out a fibonacci array.
	Numbers go into the negatives sometimes because they exceed the maximum value of an int.
*/
#include <iostream>
int main()
{
	int data[60];
	data[0] = 0;
	data[1] = 1;
	std::cout << data[0] << std::endl;
	std::cout << data[1] << std::endl;
	for (int i = 2; i < 60; i++)
	{
	     data[i] = data[i-1] + data[i - 2];
	     std::cout << data[i] << std::endl;
	}
	return 0;
}
