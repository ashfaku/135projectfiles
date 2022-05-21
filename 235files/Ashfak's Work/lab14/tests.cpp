#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"
#include <iostream>
#include "myvector.h"
using std::string;

MyVector<int> v1;
MyVector<string> v2;

TEST_CASE("Default Vector")
{
    CHECK(v1.size() == 0);
    CHECK(v1.capacity() == 5);
    CHECK(v1.empty() == true);

    CHECK(v2.size() == 0);
    CHECK(v2.capacity() == 5);
    CHECK(v2.empty() == true);
}
TEST_CASE("Push Back Method")
{
	for (int i = 10; i < 22; i++)
		v1.push_back(i);
	int arr[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
	for (int i = 0; i < v1.size(); i++)
		CHECK(v1[i] == arr[i]);

	v2.push_back("Hi");
	v2.push_back("Mr.");
	v2.push_back("Zamansky");
	string name[] = {"Hi", "Mr.", "Zamansky"};
	for (int i = 0; i < v2.size(); i++)
		CHECK(v2[i] == name[i]);

}
TEST_CASE("Size and capacity")
{
	CHECK(v1.size() == 12);
	CHECK(v2.size() == 3);
	CHECK(v1.capacity() == 20);
	CHECK(v2.capacity() == 5);
}
TEST_CASE("Pop back with and without int parameter")
{
	v1.pop_back();
	v2.pop_back();
	CHECK(v1.size() == 11);
	CHECK(v2.size() == 2);
	v1.pop_back(3);	v2.pop_back(1);
	int arr[] = {10, 11, 12, 14, 15, 16, 17, 18, 19, 20};
	for (int i = 0; i < 10; i++)
		CHECK(v1[i] == arr[i]);
	string name[] = {"Hi"};
	for (int i = 0; i < 1; i++)
		CHECK(v2[i] == name[i]);

}
TEST_CASE("Clear")
{
	v1.clear();
	CHECK(v1.empty());
	v1.push_back(100);
	CHECK(v1.size() == 1);
	v2.clear();
	CHECK(v2.empty());
}
