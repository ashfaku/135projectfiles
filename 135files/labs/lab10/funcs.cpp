#include "time.h"
#include <string>
#include "movie.h"
#include "timeslot.h"
int minutesSinceMidnight(Time time)
{

	int r = 0;
	time.h %= 24;
	time.h += (time.m / 60);
	r += time.h * 60;
	r += time.m;
	return r;
}
int minutesUntil(Time earlier, Time later)
{
	int bh = earlier.h, bm = earlier.m, lh = later.h, lm = later.m;
	int m = lm - bm, h = (lh - bh) % 24 + m/60;
	return h * 60 + (m % 60);
}
Time addMinutes(Time time0, int min)
{
	int m = min % 60, h = min / 60;
	return {time0.h + h, time0.m + m};
}
std::string getMovie(Movie m)
{
	string g;
	switch (m.genre)
	{
		case ACTION:
			g = "ACTION";
			break;
		case COMEDY:
			g = "COMEDY";
			break;
		case DRAMA:
			g = "DRAMA";
			break;
		case ROMANCE:
			g = "ROMANCE";
			break;
		case THRILLER:
			g = "THRILLER";
			break;
	}
	return m.title + " " + g + " (" + std::to_string(m.duration) + " min)";
}
std::string getTime(Time time)
{
	time.h += time.m / 60;
	time.m %= 60;
	return std::to_string(time.h) + ":" + (time.m < 10 && time.m > 0 ? "0" : "") + std::to_string(time.m) + (time.m == 60 || time.m == 0 ? "0" : "");
}
std::string getTimeSlot(TimeSlot t)
{
	string r = getMovie(t.movie);
	Time tm = addMinutes(t.startTime, t.movie.duration);
	r += " [starts at " + getTime(t.startTime) + ", ends by " + getTime(tm);
	return r + "]";
}
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
	Time time = ts.startTime;
	TimeSlot t = {nextMovie, {time.h + ts.movie.duration / 60, time.m + ts.movie.duration % 60}};
	return t;
}
bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
	Time first = ts1.startTime, second = ts2.startTime;
	int firstDuration = ts1.movie.duration, secondDuration = ts2.movie.duration, minutes = minutesUntil(first, second);
//	std::cout << minutes << " " << firstDuration << " " << secondDuration << std::endl;
	if (minutes > 0)
	{
		if (minutes < firstDuration)
			return true;
	}
	else if (abs(minutes) < secondDuration)
		return true;
	return false;
}
