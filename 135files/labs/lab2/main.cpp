/*
	Author: Ashfak Uddin
	Course: CSCI-136
	Instructor: Mike Zamansky
	Assignment: Lab2B

	This file's main method uses funcs.cpp's print_interval method.
*/

#include <iostream>
#include "funcs.h"
int main()
{
	std::cout << "Interval 1 to 10: ";
	print_interval(1, 10);
	std::cout << "Interval -5 to 15: ";
	print_interval(-5, 15);
	std::cout << "Interval 2 to 20: ";
	print_interval(2, 20);
	return 0;
}

