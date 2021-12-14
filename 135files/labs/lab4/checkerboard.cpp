/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab4B

This file defines the printCheckerBoard(int, int) function that returns a string that's a checkerboard of asterisks, with an inputted width/height
*/

#include <iostream>
#include "checkerboard.h"

bool isEven(int x)
{
	return x % 2 == 0;
}
std::string printCheckerBoard(int width, int height)
{
	std::string board = "";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			board += (isEven(i) ? isEven(j) ? "*" : " " : isEven(j) ? " " : "*");
		}
		board += (i < height - 1 ? "\n" : "");
	}
	return board;
}

