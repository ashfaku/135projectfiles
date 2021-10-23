#include <iostream>

using std::cin;
using std::endl;
int main() {
  int arr[3];
  cin >> arr[0];
  cin >> arr[1];
  cin >> arr[2];
  if (arr[0] < arr[1] && arr[1] < arr[2])
    std::cout << "increasing" << endl;
  else if (arr[0] > arr[1] && arr[1] > arr[2])
    std::cout << "decreasing" << endl;
  else
    std::cout << "neither" << endl;
  return 0;
}
