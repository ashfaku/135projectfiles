#pragma once
#include <iostream>
using std::string;
enum Genre
{
	ACTION, COMEDY, DRAMA, ROMANCE, THRILLER
};
class Movie
{
	public:
		string title;
		Genre genre;     // only one genre per movie
		int duration;    // in minutes
};
