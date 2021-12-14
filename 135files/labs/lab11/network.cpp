#include "network.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
Network::Network()
{
	numUsers = 0;
	for (int i = 0; i < MAX_USERS; i++)
		for (int j = 0; j < MAX_USERS; j++)
			following[i][j] = false;
}
int Network::findID(string usrn)
{
	for (int i = 0; i < numUsers; i++)
		if (profiles[i].getUserName() == usrn)
			return i;
	return -1;
}
bool Network::addUser(string usrn, string dspn)
{
	if (numUsers >= MAX_USERS)
		return false;
	profiles[numUsers++] = {usrn, dspn};
	return true;
}
bool Network::follow(string usrn1, string usrn2)
{
	int one = findID(usrn1), two = findID(usrn2);
	if (one != -1 && two != -1 && usrn1 != usrn2)
		following[one][two] = true;
	return following[one][two];
}
void Network::printDot()
{
	cout << "digraph {" << endl;
	for (int i = 0; i < numUsers; i++)
		cout << "\t\"@" << profiles[i].getUserName() << "\"" << endl;
	cout << endl;
	for (int i = 0; i < numUsers; i++)
	{
		for (int j = 0; j < numUsers; j++)
		{
			if (following[i][j])
				cout << "\t\"@" << profiles[i].getUserName() << "\" -> \"@" << profiles[j].getUserName() << "\"" << endl;
		}
	}
	cout << "}" << endl;
}
