#include <iostream>

int main() {
  int x = 0, sum = 0;
  char op;
  std::cin >> x;
  sum += x;
  while (std::cin >> op) {
    std::cin >> x;
    if (op == '+')
      sum += x;
    else if (op == '-')
      sum -= x;
  }
  std::cout << sum << std::endl;
  return 0;
}
