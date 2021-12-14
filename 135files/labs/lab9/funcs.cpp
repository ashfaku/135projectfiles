#include <iostream>
#include "funcs.h"
#include "coord3d.h"
#include <cmath>

using std::cout;
using std::endl;

double length(Coord3D* p)
{
	Coord3D h = *p;
	return sqrt(pow(h.x, 2) + pow(h.y, 2) + pow(h.z, 2));
}
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
	Coord3D one = *p1, two = *p2;
	return (length(&one) > length(&two) ? p1 : p2);
}
void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
	(*ppos).x += (*pvel).x * dt;
	(*ppos).y += (*pvel).y * dt;
	(*ppos).z += (*pvel).z * dt;
}
Coord3D* createCoord3D(double x, double y, double z)
{
	Coord3D *p = new Coord3D();
	p->x = x;
	p->y = y;
	p->z = z;
	return p;
}
void deleteCoord3D(Coord3D *p)
{
	delete p;
}
