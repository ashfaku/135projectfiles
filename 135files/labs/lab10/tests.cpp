#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("minutesSinceMidnight test cases")
{
	CHECK(minutesSinceMidnight({0, 10}) == 10);
	CHECK(minutesSinceMidnight({10, 10}) == 610);
	CHECK(minutesSinceMidnight({5, 43}) == 343);
	CHECK(minutesSinceMidnight({12, 0}) == 720);
	CHECK(minutesSinceMidnight({23, 59}) == 1439);
	CHECK(minutesSinceMidnight({24, 0}) == 0);
	CHECK(minutesSinceMidnight({25, 10}) == 70);
	CHECK(minutesSinceMidnight({48, 10}) == 10);

}
TEST_CASE("minutesUntil test cases")
{
	CHECK(minutesUntil({10, 30}, {13, 40}) == 190);
	CHECK(minutesUntil({10, 30}, {10, 40}) == 10);
	CHECK(minutesUntil({0, 0}, {1, 0}) == 60);
	CHECK(minutesUntil({0, 1}, {12, 0}) == 719);
	CHECK(minutesUntil({0, 0}, {24, 0}) == 0);
	CHECK(minutesUntil({10, 1}, {10, 60}) == 59);
}
TEST_CASE("addMinutes test cases")
{
	Time i = addMinutes({8, 10}, 75);
	CHECK(i.h == 9);
	CHECK(i.m == 25);
	i = addMinutes({0, 0}, 60);
	CHECK(i.h == 1);
	CHECK(i.m == 0);
	i = addMinutes({10, 2}, 40);
	CHECK(i.h == 10);
	CHECK(i.m == 42);
	i = addMinutes({10, 10}, 0);
	CHECK(i.h == 10);
	CHECK(i.m == 10);
	i = addMinutes({20, 40}, 19);
	CHECK(i.h == 20);
	CHECK(i.m == 59);
}
TEST_CASE("getMovie() tests")
{

	Movie m  = {"Back to the future", COMEDY, 120};
	CHECK(getMovie(m) == "Back to the future COMEDY (120 min)");
	m = {"Twilight", DRAMA, 150};
	CHECK(getMovie(m) == "Twilight DRAMA (150 min)");
	m = {"Movie", ACTION, 90};
	CHECK(getMovie(m) == "Movie ACTION (90 min)");
	m = {"Black Panther", ROMANCE, 150};
	CHECK(getMovie(m) == "Black Panther ROMANCE (150 min)");
	m = {"Terminator", ACTION, 112};
	CHECK(getMovie(m) == "Terminator ACTION (112 min)");
	m = {"Ghostbusters", THRILLER, 0};
	CHECK(getMovie(m) == "Ghostbusters THRILLER (0 min)");
}
TEST_CASE("getTimeSlot() tests")
{
	Movie m  = {"Back to the Future", COMEDY, 120};
	TimeSlot t = {m, {1, 20}};
	CHECK(getTimeSlot(t) == "Back to the Future COMEDY (120 min) [starts at 1:20, ends by 3:20]");
	m = {"Twilight", DRAMA, 150};
	t = {m, {0, 48}};
	CHECK(getTimeSlot(t) == "Twilight DRAMA (150 min) [starts at 0:48, ends by 3:18]");
	m  = {"Black Panther", ROMANCE, 0};
	t = {m, {2,40}};
	CHECK(getTimeSlot(t) == "Black Panther ROMANCE (0 min) [starts at 2:40, ends by 2:40]");
	m = {"Ghostbusters", THRILLER, 100};
	t = {m, {3, 20}};
	CHECK(getTimeSlot(t)== "Ghostbusters THRILLER (100 min) [starts at 3:20, ends by 5:00]");
	m = {"Terminator", ACTION, 95};
	t = {m, {7, 00}};
	CHECK(getTimeSlot(t) == "Terminator ACTION (95 min) [starts at 7:00, ends by 8:35]");
}
TEST_CASE("scheduleAfter() tests")
{
	Movie m = {"Back to the Future", COMEDY, 116};
	Movie mv = {"Black Panther", ACTION, 134};
	TimeSlot morning = {m, {9, 15}};
	TimeSlot morning2 = {mv, {10, 30}};
	CHECK(getTimeSlot(scheduleAfter(morning, mv)) == "Black Panther ACTION (134 min) [starts at 11:11, ends by 13:25]");
	CHECK(getTimeSlot(scheduleAfter(morning2, m)) == "Back to the Future COMEDY (116 min) [starts at 12:44, ends by 14:40]");
	CHECK(getTimeSlot(scheduleAfter(morning, m)) == "Back to the Future COMEDY (116 min) [starts at 11:11, ends by 13:07]");
}
TEST_CASE("Testing timeOverlap")
{
	  Movie movie1 = {"Back to the Future", COMEDY, 116};
	  Movie movie2 = {"Black Panther", ACTION, 134};
	  TimeSlot morning = {movie1, {9, 15}};
	  TimeSlot morning2 = {movie2, {10, 30}};
	  CHECK(timeOverlap(morning, morning2));
	  morning.startTime = {4, 4};
	  CHECK(!timeOverlap(morning, morning2));
	  morning2.startTime = {6, 0};
	  CHECK(!timeOverlap(morning, morning2));
}
