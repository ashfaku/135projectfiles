/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Project1D

This file takes in a stream of input with numbers, a ^ operator sometimes to
show that the number is squared, and +- operators to calculate a sum of multiple
expressions, separated by a semi-colon.
*/
#include <iostream>
using namespace std;
// Main method
int main() { // extra comment
  std::string s;
  int sum = 0, input;
  char op;
  cin >> input;
  char v = cin.peek();
  if (v == '^')
    input *= input;
  sum += input;
  if (v == '^')
    cin >> op;
  // extra comment 2
  while (cin >> op) {
    if (op == ';') {
      cout << sum << endl;
      sum = 0;
      cin >> input;
      char v = cin.peek();
      if (v == '^')
        input *= input;
      sum += input;
      if (v == '^')
        cin >> op;
    } else {
      cin >> input;
      char check = cin.peek();
      bool c = (check == '^');
      if (c)
        input *= input;
      if (op == '+')
        sum += input;
      else if (op == '-')
        sum -= input;
      if (c)
        cin >> op;
    }
  }
  return 0;
}
