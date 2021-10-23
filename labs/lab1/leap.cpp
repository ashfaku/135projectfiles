/*
Author: Ashfak Uddin
Course: CSCI-135/136
Instructor: Mike Zamansky
Assignment: Lab1C

This program takes a year input (like 2000) and says whether it's a leap year.

*/

#include <iostream>

std::string leap() {
  int yr;
  std::cout << "Enter year: ";
  std::cin >> yr;
  std::string kind;
  if (yr % 4 != 0)
    kind = "Common year";
  else if (yr % 100 != 0)
    kind = "Leap year";
  else if (yr % 400 != 0)
    kind = "Common year";
  else
    kind = "Leap year";
  return kind;
}
int main() {
  std::cout << "\n" << leap();
  return 0;
}
