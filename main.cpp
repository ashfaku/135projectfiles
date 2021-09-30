#include <iostream>
using std::cout;
using std::endl;

bool isDivisibleBy(int a, int b)
{
	return a % b == 0;
}
bool isPrime(int x)
{
	if (x <= 1)
		return false;
	for (int i = 2; i <= x/2; i++)
		if (isDivisibleBy(x, i))
      			return false;
    	return true;
}
int nextPrime(int z)
{
	while (!isPrime(++z));
	return z;
}
int countPrimes(int a, int b)
{
	int count = 0;
	for (int i = a; i <=b; i++)
		count += (isPrime(i) ? 1 : 0);
	return count;
}
bool isTwinPrime(int x)
{
	return isPrime(x) && (isPrime(x - 2) || isPrime(x + 2));
}
int nextTwinPrime(int x)
{
	while (!isTwinPrime(++x));
	return x;
}
int largestTwinPrime(int a, int b)
{
	int r = -1;
	for (int i = a; i <= b; i++)
		r = (isTwinPrime(i) ? i : r);
	return r;
}
void checkDivisibleBy(int a, int b)
{
	cout << a << " is";
	cout << (isDivisibleBy(a, b) ? "" : " not");
	cout << " divisible by " << b << endl;
}
void checkPrime(int x)
{
	cout << x << " is ";
	cout << (isPrime(x) ? "" : "not ") << "prime" << endl;
}
void checkNextPrime(int x)
{
	cout << "The next prime after " << x << " is " << nextPrime(x) << endl;
}
void checkPrimeCount(int a, int b)
{
	cout << "There are " << countPrimes(a, b) << " primes between " << a << " and " << b << endl;
}
void checkTwinPrime(int x)
{
	cout << x << " is ";
	cout << (isTwinPrime(x) ? "" : "not ") << "a twin prime" << endl;
}
void checkNextTwinPrime(int x)
{
	cout << "The next twin prime after " << x << " is " << nextTwinPrime(x) << endl;
}
void checkLargestTwinPrime(int a, int b)
{
	cout << "The largest twin prime between " << a << " and " << b << " (including the interval bounds), is " << largestTwinPrime(a, b) << endl;
}
void printTask(std::string task)
{
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << "Task " << task << ":" << endl;
}
int main()
{

	printTask("A");
	checkDivisibleBy(51, 17);
	checkDivisibleBy(20, 3);
	checkDivisibleBy(18, 5);

	printTask("B");
	checkPrime(2);
	checkPrime(51);
	checkPrime(97);

	printTask("C");
	checkNextPrime(7);
	checkNextPrime(19);
	checkNextPrime(31);

	printTask("D");
	checkPrimeCount(2, 17);
	checkPrimeCount(1, 31);
	checkPrimeCount(9, 23);

	printTask("E");
	checkTwinPrime(17);
	checkTwinPrime(23);
	checkTwinPrime(11);

	printTask("F");
	checkNextTwinPrime(19);
	checkNextTwinPrime(11);
	checkNextTwinPrime(31);

	printTask("G");
	checkLargestTwinPrime(2, 18);
	checkLargestTwinPrime(2, 41);
	checkLargestTwinPrime(3, 11);

	cout << "----------------------------------------------------------------------------------------------------" << endl;

	return 0;
}
