/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab4C

This file defines the cross(int) function that returns a string that's a cross
of asterisks with an inputted dimension.
*/

#include "cross.h"
#include <iostream>

std::string cross(int di) {
  std::string cross = "";
  for (int i = 0; i < di; i++) {
    int s = i < di / 2 ? i : di - i - 1;
    for (int j = 0; j < s; j++)
      cross += " ";
    cross += "*";
    int num = i < di / 2 ? i + 1 : i;
    if (!(di % 2 != 0 && i == di / 2)) {
      for (int j = 0; j < abs(di - num * 2); j++)
        cross += " ";
      cross += "*";
    }
    cross += i < di - 1 ? "\n" : "";
  }
  return cross;
}
