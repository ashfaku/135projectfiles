#include "funcs.h"
#include <iostream>
char shiftChar(char o, int sh) {
  if (!isalpha(o) || sh == 0)
    return o;
  int index;
  if (sh > 0) {
    int a = isupper(o) ? (int)'A' : (int)'a';
    index = (((int)o + sh - a) % 26) + a;
  } else {
    int z = isupper(o) ? (int)'Z' : (int)'z';
    index = (((int)o + sh - z) % 26) + z;
  }
  return (char)index;
}
int charIndex(char o) {
  int ascii = (int)o - (isupper(o) ? (int)'A' : (int)'a');
  return ascii % 26;
}
