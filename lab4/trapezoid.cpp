/*
Author: Ashfak Uddin
Course: CSCI-136
InstructorL Mike Zamansky
Assignment: Lab4F

This file defines the trapezoid(int, int) function that takes in a width/height and returns a string of asterisks arranged in a trapezoid or triangle.
*/

#include <iostream>
#include "trapezoid.h"
std::string trapezoid(int width, int height)
{
	std::string l = "";
	for (int i = 0; i < height; i++)
	{
		for (int s = 0; s < i; s++)
			l += " ";
		for (int j = 0; j < (width - i*2); j++)
			l += "*";
		if (width - i*2 <= 0)
			return "Impossible Shape!";
		l += i < height - 1 ? "\n" : "";
	}
	return l;
}
