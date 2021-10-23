#include <iostream>
using namespace std;

int main() {
  std::string s;
  int sum = 0, input;
  char op;
  cin >> input;
  sum += input;
  while (cin >> op) {
    if (op == ';') {
      cout << sum << endl;
      cin >> input;
      sum = input;
    } else {
      cin >> input;
      if (op == '+')
        sum += input;
      else if (op == '-')
        sum -= input;
    }
  }
  return 0;
}
