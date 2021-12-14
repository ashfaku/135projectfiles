#include "profile.h"
#include <iostream>

using std::string;
Profile::Profile()
{
	username = "";
	displayname = "";
}
Profile::Profile(string u, string d)
{
	username = u;
	displayname = d;
}
string Profile::getUserName()
{
	return username;
}
string Profile::getFullName()
{
	return username + " (@" + displayname + ")";
}
void Profile::setDisplayName(string d)
{
	displayname = d;
}
