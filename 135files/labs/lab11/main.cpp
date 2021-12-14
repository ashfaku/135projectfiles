#include "network.h"
#include "profile.h"
#include <iostream>
using std::endl;
using std::cout;
int main()
{
	cout << "Task A" << endl;
	Profile person = {"Bob", "bobDis"};
	cout << "This person's username is " << person.getUserName() << "and their full name is " << person.getFullName() << endl;
	person.setDisplayName("newBobDis");
	cout << "Their new full name is " << person.getFullName() << endl;

	cout << "Task B" << endl;
	Network n;

	for (int i = 0; i < 25; i++)
	{
		cout << "A profile with the username " << "user" << std::to_string(i) << " and the display name of ";
		cout << "id" + std::to_string(i) << " was"
		<< (n.addUser("user" + std::to_string(i), "id" + std::to_string(i)) ? "" : " not able to be")
		<< " added" << endl;
	}
	cout << "printDot():" << endl;
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

	// add a user who does not follow others
	nw.addUser("wario", "Wario");

	// add clone users who follow @mario
	for(int i = 2; i < 6; i++)
	{
		string usrn = "mario" + std::to_string(i);
		string dspn = "Mario " + std::to_string(i);
		nw.addUser(usrn, dspn);
		nw.follow(usrn, "mario");
	}
	// additionally, make @mario2 follow @luigi
	nw.follow("mario2", "luigi");

	nw.printDot();
}
