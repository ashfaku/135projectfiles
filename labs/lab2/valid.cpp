/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab2A

This program takes in an integer between 0 and 100 exclusive, asks the user repeatedly
for a valid input (within the range), until they give one, and then prints out
the square of that input.
*/
#include <iostream>
#include <cmath>

//using namespace std;

int main()
{
	int n;
	std::cout << "Please enter an integer: ";
	std::cin >> n;
	while (n < 1 || n > 99)
	{
		std::cout << "Please re-enter: ";
		std::cin >> n;
	}
	std::cout << "\n" << "Number squared is "  << pow(n, 2) << std::endl;
	return 0;
}
