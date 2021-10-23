#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  double gasInTank, fuelEfficiency, pricePerGallon;
  cin >> gasInTank;
  cin >> fuelEfficiency;
  cin >> pricePerGallon;
  cout << pricePerGallon * 100.00 / fuelEfficiency << endl;
  cout << gasInTank * fuelEfficiency << endl;
  return 0;
}
