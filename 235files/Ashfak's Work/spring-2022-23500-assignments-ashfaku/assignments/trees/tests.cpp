#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "BSTree.h"
#include <iostream>

using std::cout;
using std::endl;

BSTree *tree = new BSTree();

TEST_CASE("Tree rinsert")
{
	CHECK(tree->getRoot() == nullptr);
	tree->rinsert(1);
	CHECK(tree->getRoot()->getData() == 1);
	tree->rinsert(10);
	CHECK(tree->getRoot()->getRight()->getData() == 10);
	tree->rinsert(2);
	CHECK(tree->getRoot()->getRight()->getLeft()->getData() == 2);
	tree->rinsert(-5);
	CHECK(tree->getRoot()->getLeft()->getData() == -5);
	tree->rinsert(-2);
	CHECK(tree->getRoot()->getLeft()->getRight()->getData() == -2);
	tree->rinsert(-1);
	CHECK(tree->getRoot()->getLeft()->getRight()->getRight()->getData() == -1);
	tree->rinsert(11);
	CHECK(tree->getRoot()->getRight()->getRight()->getData() == 11);
	tree->rinsert(1);
	CHECK(tree->getRoot()->getData() == 1);
	tree->rinsert(13);
	CHECK(tree->getRoot()->getRight()->getRight()->getRight()->getData() == 13);
	tree->rinsert(12);
	CHECK(tree->getRoot()->getRight()->getRight()->getRight()->getLeft()->getData() == 12);
}
TEST_CASE("Tree rsearch")
{
	CHECK(tree->rsearch(1) == 1);
	CHECK(tree->rsearch(10) == 10);
	CHECK(tree->rsearch(2) == 2);
	CHECK(tree->rsearch(-5) == -5);
	CHECK(tree->rsearch(-2) == -2);
	CHECK(tree->rsearch(-1) == -1);
	CHECK(tree->rsearch(11) == 11);
	CHECK(tree->rsearch(13) == 13);
	CHECK(tree->rsearch(12) == 12);

	CHECK_THROWS_AS(tree->rsearch(15), int);
	CHECK_THROWS_AS(tree->rsearch(-15), int);
	CHECK_THROWS_AS(tree->rsearch(3), int);
}
TEST_CASE("Tree deletion")
{
        BSTree* t = new BSTree();
        t->rinsert(15);
        t->rinsert(10);
        t->rinsert(20);
        t->rinsert(17);
        t->rinsert(12);
        t->deleteNode(15);
        CHECK(t->getRoot()->getData() == 17);
	t->deleteNode(10);
	CHECK(t->getRoot()->getLeft()->getData() == 12);
	CHECK(t->getRoot()->getRight() != nullptr);
	t->deleteNode(20);
	CHECK(t->getRoot()->getRight() == nullptr);
	CHECK(t->getRoot()->getLeft() != nullptr);
	t->deleteNode(12);
	CHECK(t->getRoot()->getLeft() == nullptr);
	t->deleteNode(17);
	CHECK(t->getRoot() == nullptr);
	try
	{
		t->deleteNode(1);
	}
	catch (int e)
	{
		CHECK(e == 1);
	}
	t->rinsert(20);
	try
	{
		t->deleteNode(17);
	}
	catch (int e)
	{
		CHECK(e == 1);
	}
	t->rinsert(50);
	t->rinsert(0);
	t->rinsert(25);
	t->rinsert(10);
	t->deleteNode(10);
	CHECK(t->getRoot()->getLeft()->getRight() == nullptr);
	t->deleteNode(50);
	CHECK(t->getRoot()->getRight()->getData() == 25);
	t->deleteNode(20);
	CHECK(t->getRoot()->getData() == 25);
}
//								10
//				-10								30
//		-15				-5				25				35
//			-6
TEST_CASE("Tree countleaves")
{
	BSTree* t = new BSTree();
	t->rinsert(10);
	CHECK(t->countLeaves() == 1);
	t->rinsert(30);
	t->rinsert(-10);
	CHECK(t->countLeaves() == 2);
	t->rinsert(25);
	t->rinsert(35);
	t->rinsert(-5);
	t->rinsert(-15);
	CHECK(t->countLeaves() == 4);
	t->deleteNode(-5);
	CHECK(t->countLeaves() == 3);
	t->rinsert(-5);
	t->rinsert(-6);
	CHECK(t->countLeaves() == 4);
}

//								10
//				-10								30
//										15				35
//								14
TEST_CASE("Tree height")
{
	BSTree* t = new BSTree();
	CHECK(t->height() == 0);
	t->rinsert(10);
	CHECK(t->height() == 1);
	t->rinsert(30);
	CHECK(t->height() == 2);
	t->rinsert(-10);
	CHECK(t->height() == 2);
	t->rinsert(15);
	CHECK(t->height() == 3);
	t->rinsert(14);
	CHECK(t->height() == 4);
	t->rinsert(40);
	CHECK(t->height() == 4);

}

