/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab4A

This file defines the box(int, int) function that returns a string that's a box
of asterisks with an inputted width/height.
*/

#include "box.h"
#include <iostream>
std::string box(int width, int height) {
  std::string box = "";
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      box += "*";
      box += (j < width - 1 ? " " : i < height - 1 ? "\n" : "");
    }
  }
  return box;
}
