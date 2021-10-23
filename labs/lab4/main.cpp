#include "box.h"
#include "checkerboard.h"
#include "checkerboard3x3.h"
#include "cross.h"
#include "lower.h"
#include "trapezoid.h"
#include "upper.h"
#include <iostream>
using std::cout;
using std::endl;
void printBox(int width, int height);
void printCheckers(int width, int height);
void printCross(int d);
void printLowerHalf(int d);
void printUpperHalf(int d);
void printTrapezoid(int width, int height);
void print3x3(int width, int height);
int main() {
  cout << "Task A" << endl;
  printBox(4, 5);
  printBox(6, 7);
  printBox(9, 10);
  cout << "Task B" << endl;
  printCheckers(15, 10);
  printCheckers(11, 6);
  printCheckers(5, 15);
  cout << "Task C" << endl;
  printCross(5);
  printCross(4);
  printCross(9);
  cout << "Task D" << endl;
  printLowerHalf(10);
  printLowerHalf(5);
  printLowerHalf(3);
  cout << "Task E" << endl;
  printUpperHalf(10);
  printUpperHalf(5);
  printUpperHalf(3);
  cout << "Task F" << endl;
  printTrapezoid(12, 5);
  printTrapezoid(5, 3);
  printTrapezoid(12, 7);
  cout << "Task G" << endl;
  print3x3(16, 11);
  print3x3(27, 27);
  print3x3(8, 5);
  return 0;
}
void print3x3(int width, int height) {
  cout << "3x3 board with a width of " << width << " and a height of " << height
       << endl;
  cout << threexthreeboard(width, height) << endl;
  cout << "--------------------------------------------------------------------"
          "---"
       << endl;
}
void printTrapezoid(int width, int height) {
  cout << "Trapezoid with a width of " << width << " and a height of " << height
       << endl;
  cout << trapezoid(width, height) << endl;
  cout << "--------------------------------------------------------------------"
          "---"
       << endl;
}
void printUpperHalf(int d) {
  cout << "Upper half with dimension " << d << endl;
  cout << upperhalf(d) << endl;
  cout << "--------------------------------------------------------------------"
          "---"
       << endl;
}
void printLowerHalf(int d) {
  cout << "Lower half with dimension " << d << endl;
  cout << lowerhalf(d) << endl;
  cout << "--------------------------------------------------------------------"
          "---"
       << endl;
}
void printCross(int d) {
  cout << "Cross with dimension " << d << endl;
  cout << cross(d) << endl;
  cout << "--------------------------------------------------------------------"
          "---"
       << endl;
}
void printCheckers(int width, int height) {
  cout << "Checkerboard with width " << width << " and height " << height
       << ": " << endl;
  cout << printCheckerBoard(width, height) << endl;
  cout << "--------------------------------------------------------------------"
          "---"
       << endl;
}
void printBox(int width, int height) {
  cout << "Box with width " << width << " and height " << height << ": "
       << endl;
  cout << box(width, height) << endl;
  cout << "--------------------------------------------------------------------"
          "---"
       << endl;
}
