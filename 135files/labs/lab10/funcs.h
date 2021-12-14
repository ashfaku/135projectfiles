#pragma once
#include "time.h"
#include "movie.h"
#include "timeslot.h"
#include <iostream>

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
std::string getMovie(Movie m);
std::string getTimeSlot(TimeSlot t);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);
std::string getTime(Time time);
