/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab4E

This file defines the upperhalf(int) function that returns a string that's the upper half of a square of asterisks with an inputted dimension.
*/
#include <iostream>
#include "upper.h"
std::string upperhalf(int d)
{
	std::string l = "";
	for (int i = d; i > 0; i--)
	{
		for (int s = 0; s < d - i; s++)
			l += " ";
		for (int j = i; j > 0; j--)
			l += "*";
		l += i > 1 ? "\n" : "";
	}
	return l;
}
