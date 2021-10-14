#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Base Cases")
{
	CHECK(isPrime(-2) == false);
	CHECK(isPrime(3) == true);
}
