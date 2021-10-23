#include <iostream>
int main() {
  std::cout << "Hello! Please enter a number. ";
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cout << "I love C++" << std::endl;
  return 0;
}
