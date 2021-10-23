/*
Author: Ashfak Uddin
Course: CSCI-135/136
Instructor: Mike Zamansky
Assignment: Lab1D

This program takes a year input (like 2000)
and a month input, and says how many days that
month has, including leap years.
*/

#include <iostream>
//#include "leap.cpp"

bool leap() {
  int yr;
  std::cout << "Enter year: ";
  std::cin >> yr;
  bool kind;
  if (yr % 4 != 0)
    kind = false;
  else if (yr % 100 != 0)
    kind = true;
  else if (yr % 400 != 0)
    kind = false;
  else
    kind = true;
  return kind;
}
int main() {
  bool l = leap();
  int month, days;
  std::cout << "Enter month: ";
  std::cin >> month;
  if (month == 2)
    days = l == 1 ? 29 : 28;
  else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
           month == 10 || month == 12)
    days = 31;
  else
    days = 30;
  std::cout << "\n" << days << " days";
  return 0;
}
