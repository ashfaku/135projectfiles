#include "caesar.h"
#include "funcs.h"
#include <iostream>
std::string encryptCaesar(std::string o, int shift) {
  std::string s = "";
  int index = -1;
  while (o[++index])
    s += shiftChar(o[index], shift);
  return s;
}
