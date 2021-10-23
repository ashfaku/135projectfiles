#include "funcs.h"
#include <iostream>

bool isDivisibleBy(int a, int b) {
  if (b == 0)
    return 0;
  return a % b == 0;
}
bool isPrime(int x) {
  if (x <= 1)
    return false;
  for (int i = 2; i <= x / 2; i++)
    if (isDivisibleBy(x, i))
      return false;
  return true;
}
int nextPrime(int z) {
  while (!isPrime(++z))
    ;
  return z;
}
int countPrimes(int a, int b) {
  int count = 0;
  for (int i = a; i <= b; i++)
    count += (isPrime(i) ? 1 : 0);
  return count;
}
bool isTwinPrime(int x) {
  return isPrime(x) && (isPrime(x - 2) || isPrime(x + 2));
}
int nextTwinPrime(int x) {
  while (!isTwinPrime(++x))
    ;
  return x;
}
int largestTwinPrime(int a, int b) {
  for (int i = b; i >= a; i--)
    if (isTwinPrime(i))
      return i;
  return -1;
}
