#include <iostream>
#include "profile.h"
using std::string;
class Network
{
	private:
		static const int MAX_USERS = 20; // max number of user profiles
		int numUsers;                    // number of registered users
		Profile profiles[MAX_USERS];     // user profiles array
		// mapping integer ID -> Profile
		// Returns user ID (index in the 'profiles' array) by their username
		// (or -1 if username is not found)
		int findID (string usrn);
		bool following[MAX_USERS][MAX_USERS];
	public:
		// Constructor, makes an empty network (numUsers = 0)
		Network();
		// Attempts to sign up a new user with specified username and displayname
		// return true if the operation was successful, otherwise return false
		bool addUser(string usrn, string dspn);
		bool follow(string usrn1, string usrn2);
		void printDot();
};
