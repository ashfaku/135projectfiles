#include "movie.h"
#include "timeslot.h"
#include "time.h"
#include "funcs.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	cout << "Task A: minutesSinceMidnight" << endl;
	cout << "Time 00:39: " << minutesSinceMidnight({0, 39}) << endl;
	cout << "Time 01:20: " << minutesSinceMidnight({1, 20}) << endl;
	cout << "Time 2:40: " << minutesSinceMidnight({2, 40}) << endl;

	cout << "Task A: minutesUntil" << endl;
	cout << "Between times 00:00 and 01:00, there are " << minutesUntil({0,0},{1,0}) << " minutes" << endl;
	cout << "Between times 02:40 and 04:20, there are " << minutesUntil({2, 40}, {4, 20}) << " minutes" << endl;
	cout << "Between times 12:40 and 14:30, there are " << minutesUntil({12, 40}, {14, 30}) << " minutes" << endl;

	cout << "Task B: addMinutes()" << endl;
	cout << "Time 00:00, add 61 minutes: " << getTime(addMinutes({0,0}, 61)) << endl;
	cout << "Time 02:20, add 39 minutes: " << getTime(addMinutes({2, 40}, 39)) << endl;
	cout << "Time 04:00, add 120 minutes: " << getTime(addMinutes({4, 0}, 120)) << endl;

	cout << "Task C: getMovie()" << endl;
	cout << getMovie({"Back to the future", COMEDY, 120}) << endl;;
	cout << getMovie({"Twilight", DRAMA, 150}) << endl;
        cout << getMovie({"Movie", ACTION, 90}) << endl;

	cout << "Task C: getTimeSlot()" << endl;
 	Movie m  = {"Back to the Future", COMEDY, 120};
        TimeSlot t = {m, {1, 20}};
        cout << getTimeSlot(t) << endl;
        m = {"Twilight", DRAMA, 150};
        t = {m, {0, 48}};
        cout << getTimeSlot(t) << endl;
        m  = {"Black Panther", ROMANCE, 0};
        t = {m, {2,40}};
        cout << getTimeSlot(t) << endl;

	cout << "Task D: scheduleAfter() - and getTimeSlot(), becuase cannot be tested without that" << endl;
	m = {"Back to the Future", COMEDY, 116};
        Movie mv = {"Black Panther", ACTION, 134};
        TimeSlot morning = {m, {9, 15}};
        TimeSlot morning2 = {mv, {10, 30}};
        cout << getTimeSlot(scheduleAfter(morning, mv)) << endl;
        cout << getTimeSlot(scheduleAfter(morning2, m)) << endl;
        cout << getTimeSlot(scheduleAfter(morning, m)) << endl;

	cout << "Task E: timeOverlap()" << endl;

	Movie movie1 = {"Back to the Future", COMEDY, 116};
        Movie movie2 = {"Black Panther", ACTION, 134};
        morning = {movie1, {9, 15}};
        morning2 = {movie2, {10, 30}};
        cout << "TimeSlots " << getTimeSlot(morning) << " and " << getTimeSlot(morning2) << " do " << (timeOverlap(morning, morning2) ? "overlap" : "not overlap") << endl;
        morning.startTime = {4, 4};
        cout << "TimeSlots " << getTimeSlot(morning) << " and " << getTimeSlot(morning2) << " do " << (timeOverlap(morning, morning2) ? "overlap" : "not overlap") << endl;
        morning2.startTime = {6, 0};
        cout << "TimeSlots " << getTimeSlot(morning) << " and " << getTimeSlot(morning2) << " do " << (timeOverlap(morning, morning2) ? "overlap" : "not overlap") << endl;
	return 0;
}
