/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab4G

This file defines the threexthreeboard(int, int) function that takes in a
width/height and prints out a checkerboard of 3x3 squares, and works for
dimensions not divisible by 3.
*/

#include <iostream>

std::string threexthreeboard(int w, int h) {
  std::string b = "";
  bool row, col = true;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j == 0)
        row = col;
      b += (row ? "*" : " ");
      if ((j + 1) % 3 == 0)
        row = !row;
    }
    if ((i + 1) % 3 == 0)
      col = !col;
    b += (i < h - 1 ? "\n" : "");
  }
  return b;
}
