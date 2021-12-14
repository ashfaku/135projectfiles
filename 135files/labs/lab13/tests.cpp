#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctest.h"
using std::string;

TEST_CASE("Task A printRange")
{
	CHECK(printRange(1, 10) == "1 2 3 4 5 6 7 8 9 10");
	CHECK(printRange(10, 1) == "");
	CHECK(printRange(-2, 5) == "-2 -1 0 1 2 3 4 5");
	CHECK(printRange(-5, 5) == "-5 -4 -3 -2 -1 0 1 2 3 4 5");
	CHECK(printRange(10, 20) == "10 11 12 13 14 15 16 17 18 19 20");
}
TEST_CASE("Task B sumRange")
{
	CHECK(sumRange(1, 4) == 10);
	CHECK(sumRange(-5, 5) == 0);
	CHECK(sumRange(10, 20) == 165);
	CHECK(sumRange(0,0) == 0);
	CHECK(sumRange(-10, -8) == -27);
}
TEST_CASE("Task C sumArray")
{
	int *arr = new int[10]; // allocate array dynamically
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

	CHECK(sumArray(arr, 10) == 43);
	CHECK(sumArray(arr, 5) == 34);
	CHECK(sumArray(arr, -1) == 0);
	CHECK(sumArray(arr, 0) == 0);
	CHECK(sumArray(arr, 9) == 64);
	// wasn't too sure how i could test size > 10, since that just goes into bad memory
	// and the function can't really know the max size of the pointer
	delete[] arr;
	arr = nullptr;
}
TEST_CASE("Task D isAlphaNumeric")
{
	CHECK(!isAlphaNumeric("Mike Zamansky"));
	CHECK(!isAlphaNumeric("@(*$#$&Hi"));
	CHECK(isAlphaNumeric("Universities"));
	CHECK(isAlphaNumeric("FinalLab"));
	CHECK(isAlphaNumeric("ofthissemester"));
	CHECK(!isAlphaNumeric("@@@##$$$)(#!@*&$#("));
}
