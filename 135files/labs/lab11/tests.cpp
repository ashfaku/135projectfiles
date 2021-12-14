#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "profile.h"
#include "doctest.h"
#include "network.h"
#include <iostream>
using std::cout;
using std::endl;
TEST_CASE("Task A Profile class")
{
	Profile p = {};
	CHECK(p.getUserName() == "");
	CHECK(p.getFullName() == " (@)");
	p = {"Bob Ross", "bob"};
	CHECK(p.getUserName() == "Bob Ross");
	CHECK(p.getFullName() == "Bob Ross (@bob)");
	p.setDisplayName("newBob");
	CHECK(p.getFullName() == "Bob Ross (@newBob)");
}
TEST_CASE("Task B Network class addUser")
{
	Network n;
	for (int i = 0; i < 21; i++)
		CHECK(n.addUser("bob" + std::to_string(i), "ross") == (i < 20));
}
TEST_CASE("Task C follow")
{
	Network nw;
	// add three users
	nw.addUser("mario", "Mario");
	nw.addUser("luigi", "Luigi");
	nw.addUser("yoshi", "Yoshi");

	// make them follow each other
	nw.follow("mario", "luigi");
	nw.follow("mario", "yoshi");
	nw.follow("luigi", "mario");
	nw.follow("luigi", "yoshi");
	nw.follow("yoshi", "mario");
	nw.follow("yoshi", "luigi");

	CHECK(!nw.follow("mario", "mario"));
	CHECK(nw.follow("mario", "luigi"));
	CHECK(nw.follow("luigi", "yoshi"));
	CHECK(nw.follow("yoshi", "luigi"));
	CHECK(nw.follow("yoshi", "mario"));
}
