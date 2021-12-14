#include <iostream>
#include "coord3d.h"
#include "funcs.h"
using std::cout;
using std::endl;
int main()
{
	Coord3D a = {10, 20, 30};
	Coord3D b = {-3, -4, -5};
	Coord3D c = {-5, 12, -13};
	Coord3D d = {0,0,0};
	cout << "Coord3D a is (" << a.x << ", " << a.y << ", " << a.z << ")" << endl;
	cout << "Distance for point (10,20,30) is " << length(&a) << endl;
	cout << "Distance for point (-3,-4,-5) is " << length(&b) << endl;
	cout << "Distance for point (-5,12,-13) is " << length(&c) << endl;
	cout << "Distance for point (0,0,0) is " << length(&d) << endl;

	Coord3D * outcome = fartherFromOrigin(&a, &b);
	cout << "Farther distance between a (10,20,30) and b (-3,-4,-5) is point " << (outcome == &a ? "A" : "B") << endl;
	outcome =  fartherFromOrigin(&b, &d);
	cout << "Farther distance between b (-3,-4,-5) and point d (0,0,0) is point " << (outcome == &b ? "B" : "D") << endl;
	outcome =  fartherFromOrigin(&b, &c);
	cout << "Farther distance between b (-3,-4,-5) and point c (-5,12,-13) is point " << (outcome == &c ? "C": "B") << endl;

	Coord3D posA = {0, 0, 100.0};
	Coord3D velA = {1, -5, 0.2};
	move(&posA, &velA, 2.0);
	cout << "Point A (0,0,100.0) with velocity (1,-5, 0.2) and dt = 2.0 updates point A to (" << posA.x << "," << posA.y << "," << posA.z << ")" << endl;


	Coord3D *temp = createCoord3D(20, 40, 59);
	cout << "Dynamically created Coord3D is (" << temp->x << ", " << temp->y << ", " << temp->z << ")" << endl;
	deleteCoord3D(temp); // can't really test
	return 0;
}
