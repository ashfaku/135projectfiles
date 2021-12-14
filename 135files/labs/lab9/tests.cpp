#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
double fixLength(double l, int precision)
{
	double p = pow(10, precision);
	return ((int)(l*p)) / p;
}

TEST_CASE("Testing length(Coord3D* p) function")
{
	Coord3D p = {10, 20, 30};
	CHECK(fixLength(length(&p), 3) == 37.416);
	p = {0,0,0};
	CHECK(fixLength(length(&p), 3) == 0.000);
	p = {20, 50, 100};
	CHECK(fixLength(length(&p), 3) == 113.578);
	p = {-100, 10, 20};
	CHECK(fixLength(length(&p), 3) == 102.469);
	p = {40, -25, 50};
	CHECK(fixLength(length(&p), 3) == 68.738);
	p = {1, 0, 0};
	CHECK(fixLength(length(&p), 3) == 1.000);
}
TEST_CASE("Testing fartherFromOrigin(Coord3D* p1, Coord3D* p2) function")
{
	Coord3D p = {10, 20, 30}, o = {0,0,0};
	CHECK(fartherFromOrigin(&p, &o) == &p);
	p = {20, 50, 100};
	o = {-100, 10, 20};
	CHECK(fartherFromOrigin(&p, &o) == &p);
	p = {1, 0, 0};
	o = {40, -25, 50};
	CHECK(fartherFromOrigin(&p, &o) == &o);
	p = {10, 20, 30};
	o = {20, 50, 100};
	CHECK(fartherFromOrigin(&p, &o) == &o);
	p = {-100, 10, 20};
	o = {40, -25, 50};
	CHECK(fartherFromOrigin(&p, &o) == &p);
}
TEST_CASE("Testing move(Coord3D *ppos, Coord3D *pvel, double dt) function")
{
	Coord3D pos = {0, 0, 100.0};
	Coord3D vel = {1, -5, 0.2};
 	move(&pos, &vel, 2.0);
	CHECK(pos.x == 2);
	CHECK(pos.y == -10);
	CHECK(pos.z == 100.4);
	pos = {1,1,1};
	vel = {.1, .2, .3};
	move(&pos, &vel, 10);
	CHECK(pos.x == 2);
	CHECK(pos.y == 3);
	CHECK(pos.z == 4);
	pos = {100, 400, 300};
	vel = {10, 20, 30};
	move (&pos, &vel, .5);
	CHECK(pos.x == 105);
	CHECK(pos.y == 410);
	CHECK(pos.z == 315);
	pos = {49, 18, 20};
	vel = {1,1,1};
	move(&pos, &vel, 23);
	CHECK(pos.x == 72);
	CHECK(pos.y == 41);
	CHECK(pos.z == 43);
}
TEST_CASE("Checking createCoord3D")
{
	Coord3D *temp = createCoord3D(20, 40, 59);
	CHECK(temp->x == 20);
	CHECK(temp->y == 40);
	CHECK(temp->z == 59);
	Coord3D *temp1 = createCoord3D(9, 8, 7);
	CHECK(temp1->x == 9);
	CHECK(temp1->y == 8);
	CHECK(temp1->z == 7);
	deleteCoord3D(temp);// can't really test deletion
	deleteCoord3D(temp1);
}
