/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab2B

This file contains the print_interval function, which prints out every number
betweeen L and U, including L, but excluding U. It will be used in main.cpp.
*/
#include <iostream>
#include "funcs.h"

void print_interval(int L, int U)
{
	for (int i = L; i < U; i++)
		std::cout << i << (i != U - 1 ? ", " : "\n");
}

