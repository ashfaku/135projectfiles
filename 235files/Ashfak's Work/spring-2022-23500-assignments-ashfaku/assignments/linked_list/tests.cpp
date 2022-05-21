#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OList.h"

TEST_CASE("Insert")
{
	OList *list = new OList();
	list->insert(1);
	list->insert(2);
	list->insert(3);
	list->insert(14);
	CHECK(list->toString() == "head-->1-->2-->3-->14-->nullptr");
	delete list;

	OList *list1 = new OList();
	list1->insert(-5);
	list1->insert(-4);
	list1->insert(-3);
	list1->insert(-2);
	list1->insert(0);

	CHECK(list1->toString() == "head-->-5-->-4-->-3-->-2-->0-->nullptr");
	delete list1;

	OList *list3 = new OList();
	list3->insert(12);
	list3->insert(20);
	list3->insert(100);
	list3->insert(300);
	list3->insert(500);
	list3->insert(-20);

	CHECK(list3->toString() == "head-->-20-->12-->20-->100-->300-->500-->nullptr");
	delete list3;

	OList *list5 = new OList();
	list5->insert(-14);
	list5->insert(120);
	list5->insert(5919);
	list5->insert(-69291);
	list5->insert(5000);

	CHECK(list5->toString() == "head-->-69291-->-14-->120-->5000-->5919-->nullptr");
	delete list5;
}

TEST_CASE("toString")
{
	OList *list = new OList();
	CHECK(list->toString() == "head-->nullptr");
	delete list;
}

TEST_CASE("Contains")
{
	OList *list = new OList();

	CHECK(list->contains(44) == false);
	CHECK(list->contains(0) == false);
	CHECK(list->contains(-1000) == false);
	delete list;

	OList *list1 = new OList();
	list1->insert(-1);
	list1->insert(-1);
	list1->insert(0);
	list1->insert(0);
	list1->insert(-1);

	CHECK(list->contains(23) == false);
	CHECK(list->contains(-1) == true);
	CHECK(list->contains(0) == true);
	delete list;
}

TEST_CASE("Get")
{
        OList *list1 = new OList();
	CHECK_THROWS_AS(list1->get(1), std::out_of_range); // i have no idea how to check for an actual value here
        delete list1;

        OList *list = new OList();
        list->insert(100);
        list->insert(100);
        list->insert(100);
        list->insert(100);
        list->insert(100);
        list->insert(0);
        list->insert(0);

        CHECK(list->get(0) == 0);
        CHECK(list->get(1) == 0);
        CHECK(list->get(2) == 100);
        CHECK(list->get(3) == 100);
        CHECK(list->get(4) == 100);
        CHECK(list->get(5) == 100);
        CHECK(list->get(6) == 100);
        delete list;
}

TEST_CASE("Remove")
{
        OList *list1 = new OList();
        CHECK_THROWS_AS(list1->remove(1), std::out_of_range);
        delete list1;

	OList *list = new OList();
        list->insert(120);
        list->insert(5919);
        list->insert(1);
        list->insert(8);
        list->insert(14);
        list->insert(268);

        CHECK(list->toString() == "head-->1-->8-->14-->120-->268-->5919-->nullptr");
        list->remove(1);
	CHECK(list->toString() == "head-->1-->14-->120-->268-->5919-->nullptr");
	list->remove(1);
        CHECK(list->toString() == "head-->1-->120-->268-->5919-->nullptr");
       	list->remove(1);
        CHECK(list->toString() == "head-->1-->268-->5919-->nullptr");
        list->remove(1);
        CHECK(list->toString() == "head-->1-->5919-->nullptr");
        CHECK_THROWS_AS(list->remove(-3), std::out_of_range);
        delete list;

}
