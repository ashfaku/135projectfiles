/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab3A

This file uses the get_east_storage, get_min_east, get_max_east, and
compare_basins functions from the reservoir.cpp file, and uses the reverse_order
function from reverseorder.cpp.
*/

#include "reservoir.h"
#include "reverseorder.h"
#include <iostream>
int main() {
  std::string l = "The east storage for the date ";
  std::cout << l << "01/01/2018 is " << get_east_storage("01/01/2018")
            << std::endl;
  std::cout << l << "03/30/2018 is " << get_east_storage("03/30/2018")
            << std::endl;
  std::cout << l << "05/15/2018 is " << get_east_storage("05/15/2018")
            << std::endl;
  std::cout << l << "08/09/2018 is " << get_east_storage("08/09/2018")
            << std::endl;
  std::cout << l << "12/30/2018 is " << get_east_storage("12/30/2018")
            << std::endl;
  std::cout << "The minimum east storage is " << get_min_east() << std::endl;
  std::cout << "The maximum east storage is " << get_max_east() << std::endl;
  std::cout << "At 01/01/2018, " << compare_basins("01/01/2018")
            << " basin has a greater storage" << std::endl;
  std::cout << "At 03/03/2018, " << compare_basins("03/03/2018")
            << " basin has a greater storage" << std::endl;
  std::cout << "At 05/05/2018, " << compare_basins("05/05/2018")
            << " basin has a greater storage" << std::endl;
  std::cout << "Storages between 02/15/2018 and 01/01/2018" << std::endl;
  reverse_order("01/01/2018", "02/15/2018");
  std::cout << "Storages between 05/15/2018 and 05/01/2018" << std::endl;
  reverse_order("05/01/2018", "05/15/2018");
  return 0;
}
