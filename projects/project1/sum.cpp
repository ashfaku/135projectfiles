/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Project1A
Takes in a txt file with numbers and outputs their sum.
*/

#include <iostream>

int main()
{
	int sum = 0, x;
	while (std::cin >> x)
		sum += x;
	std::cout << sum << std::endl;
}

