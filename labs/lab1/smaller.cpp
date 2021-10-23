/*
Author: Ashfak Uddin
Course: CSCI13500
Instructor: Mike Zamansky
Assignment: Lab1A

This program takes 2 integer inputs and returns the smaller one.

*/

#include <iostream>

int main() {
  int first, second;
  std::cout << "Enter the first number: ";
  std::cin >> first;
  std::cout << "Enter the second number: ";
  std::cin >> second;
  std::cout << "The smaller of the two is " << std::min(first, second);
  return 0;
}
