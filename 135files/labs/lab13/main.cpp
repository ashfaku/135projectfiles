#include "funcs.h"
#include <iostream>
using std::cout;
using std::endl;
void rangePrint(int a, int b)
{
	cout << "Numbers between " << a << " and " << b << " printed recursively: " << printRange(a, b) << endl;
}
void rangeSum(int a, int b)
{
	cout << "Sum of numbers between " << a << " and " << b << " calculated recursively: " << sumRange(a, b) << endl;
}
void arraySum(int *arr, int s)
{
	cout << "The sum of the array before index " << s << " is " << sumArray(arr, s) << endl;
}
void printAlphaNumeric(string s)
{
	cout << "The word " << s << " is" << (isAlphaNumeric(s) ? "" : " not") << " alpha-numeric" << endl;
}
void printNestedParens(string s)
{
	cout << "The character sequence of " << s << " is" << (nestedParens(s) ? "" : " not") << " a sequence of nested parentheses" << endl;
}
int main()
{
	cout << "Task A: printRange()" << endl;
	rangePrint(-2, 10);
	rangePrint(0, 17);
	rangePrint(10, 0);

	cout << "Task B: sumRange()" << endl;
	rangeSum(1, 4);
	rangeSum(-5, 5);
	rangeSum(10, 20);
	cout << "Task C: sumArray()" << endl;
	int *arr = new int[10];
	arr[0] = 12;
	arr[1] = 17;
	arr[2] = -5;
	arr[3] = 3;
	arr[4] = 7;
	arr[5] = -15;
	arr[6] = 27;
	arr[7] = 5;
	arr[8] = 13;
	arr[9] = -21;
	arraySum(arr, 10);
	arraySum(arr, 0);
	arraySum(arr, 7);
	cout << "Task D: isAlphaNumeric()" << endl;
	printAlphaNumeric("TestCase1");
	printAlphaNumeric("calculator");
	printAlphaNumeric("!true");
	cout << "Task E: nestedParens()" << endl;
	printNestedParens("(())");
	printNestedParens("(((((())))))");
	printNestedParens("(((((((((((((");
	printNestedParens(")))))))(");
	printNestedParens("()()()()()()()()");
	return 0;
}
