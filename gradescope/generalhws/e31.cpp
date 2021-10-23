#include <iostream>

using std::cin;
using std::cout;
using std::endl;
int main() {
  int i;
  cin >> i;
  cout << (i > 0 ? "Positive" : i < 0 ? "Negative" : "Zero") << endl;
  return 0;
}
