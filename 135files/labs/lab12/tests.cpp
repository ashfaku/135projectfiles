#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctest.h"
#include <iostream>
using std::string;
string toString(const vector<int> &v)
{
	string s = "";
	for (int i : v)
		s += std::to_string(i);
	return s;
}
TEST_CASE("Task A makeVector")
{
	vector<int> a = makeVector(10), b = makeVector(15), c = makeVector(19);
	for (int i = 0; i < 10; i++)
		CHECK(a[i] == i);
	for (int i = 0; i < 15; i++)
		CHECK(b[i] == i);
	for (int i = 0; i < 19; i++)
		CHECK(c[i] == i);
}
TEST_CASE("Task B goodVibes")
{
	vector<int> a{1,2,3,4,5,-1,-2,-3}, a1 = goodVibes(a), ac{1,2,3,4,5};
	CHECK(toString(a1) == toString(ac));
	vector<int> b{-2,3,-4,5,-10,8,-9}, b1 = goodVibes(b), bc{3,5,8};
	CHECK(toString(b1) == toString(bc));
	vector<int> c{-9,-8,-7,-8,-9};
	CHECK(toString(goodVibes(c)) == "");
	vector<int> d{-9,8}, d1 = goodVibes(d);
	CHECK(toString(d1) == "8");
}
TEST_CASE("Task C gogeta")
{
	vector<int> a{1,2,3,4,5,-1,-2,-3}, ac{1,2,3,4,5};
	gogeta(a, ac);
	CHECK(toString(ac) == "");
	CHECK(toString(a) == "12345-1-2-312345");
	vector<int> c{2,3,4,5,6,6,7,-1}, b{2,3,4};
	gogeta(c, b);
	CHECK(toString(b) == "");
	CHECK(toString(c) == "2345667-1234");
	vector<int> d{1,2,3}, e{4,5,6};
	gogeta(d, e);
	CHECK(toString(e) == "");
	CHECK(toString(d) == "123456");
}
TEST_CASE("Task D sumPairWise")
{
	vector<int> a{1,2,3}, b{4,5};
	CHECK(toString(sumPairWise(a, b)) == "573");
	vector<int> c{4,5,6}, d{0};
	CHECK(toString(sumPairWise(c, d)) == "456");
	vector<int> e{4,5,6,7}, f{};
	CHECK(toString(sumPairWise(e, f)) == "4567");
	vector<int> g{1,2}, h{2,3,4,6};
	CHECK(toString(sumPairWise(g, h)) == "3546");
}
