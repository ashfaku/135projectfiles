#pragma once
#include <iostream>
using std::string;
class Profile
{
	private:
		string displayname;
		string username;
	public:
		// accessor functions for the current position of the particle
		string getUserName();
		string getFullName();
		void setDisplayName(string dspn);
		Profile(string u, string d);
		// Default constructor, will assume pos=(0,0), vel=(0,0)
		Profile();
};
