/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab3D

This file defines the reverse_order function, where it takes in 2 dates and
prints out the west elevation of those dates, in reverse chronological order.
*/
#include "reverseorder.h"
#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
void reverse_order(std::string date1, std::string date2) {
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  bool c = false;
  double data[365];
  std::string dates[365];
  int counter = 0;
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1);
  } else {
    std::string junk, date;
    getline(fin, junk);
    double eastSt, eastEl, westSt, westEl;
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
      fin.ignore(INT_MAX, '\n');
      if (date == date1)
        c = true;
      if (c) {
        data[counter] = westEl;
        dates[counter] = date;
        counter++;
      }
      if (date == date2)
        c = false;
    }
    fin.close();
    for (int i = counter - 1; i > -1; i--)
      std::cout << dates[i] << " " << data[i] << " ft" << std::endl;
  }
}
