/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab4D

This file defines the lowerhalf(int) function that returns a string that's the
lower half of a square with an inputted dimension.
*/
#include "lower.h"
#include <iostream>
std::string lowerhalf(int d) {
  std::string l = "";
  for (int i = 1; i <= d; i++) {
    for (int j = 0; j < i; j++)
      l += "*";
    l += i < d ? "\n" : "";
  }
  return l;
}
