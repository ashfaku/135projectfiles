/*
Author: Ashfak Uddin
Course: CSCI13500
Instructor: Mike Zamansky
Assignment: Lab1B

This program takes 3 integer inputs and returns the smallest one.

*/

#include <iostream>

int main() {
	int first, second, third;
	std::cout << "Enter the first number: ";
	std::cin >> first;
	std::cout << "Enter the second number: ";
	std::cin >> second;
	std::cout << "Enter the third number: ";
	std::cin >> third;
	std::cout << "The smaller of the three is " << std::min(first, std::min(second, third));
	return 0;
}
