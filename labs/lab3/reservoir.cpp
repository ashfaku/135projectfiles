/*
Author: Ashfak Uddin
Course: CSCI-136
Instructor: Mike Zamansky
Assignment: Lab3A

This file defines the get_east_storage function, where it takes in a date and returns that date's east storage.
*/

#include <iostream>
#include "reservoir.h"
#include <fstream>
#include <cstdlib>
#include <climits>
double get_west_storage(std::string want);
std::string compare_basins(std::string date)
{
	double west = get_west_storage(date), east = get_east_storage(date);
	std::cout << "the west basin has a storage of " << west << " and the east basin has a storage of " << east << ". ";
	return (west > east ? "West" : west < east ? "East" : "Equal");
}
double get_max_east()
{
	std::ifstream fin("Current_Reservoir_Levels.tsv");
        double max = INT_MIN;
        if (fin.fail())
        {
                 std::cerr << "File cannot be opened for reading." << std::endl;
                 exit(1);
        }
        else
        {
                std::string junk, date;
                getline(fin, junk);
                double eastSt, eastEl, westSt, westEl;
                while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
                {
                        fin.ignore(INT_MAX, '\n');
                        if (eastSt > max)
                                max = eastSt;
                }
                fin.close();
        }
        return max;
}
double get_min_east()
{
	std::ifstream fin("Current_Reservoir_Levels.tsv");
        double min = INT_MAX;
        if (fin.fail())
        {
                 std::cerr << "File cannot be opened for reading." << std::endl;
                 exit(1);
        }
        else
        {
                std::string junk, date;
                getline(fin, junk);
                double eastSt, eastEl, westSt, westEl;
                while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
                {
                        fin.ignore(INT_MAX, '\n');
			if (eastSt < min)
				min = eastSt;
                }
                fin.close();
        }
        return min;
}

double get_west_storage(std::string want)
{
	std::ifstream fin("Current_Reservoir_Levels.tsv");
        double westSt = -1.0;
        if (fin.fail())
        {
                 std::cerr << "File cannot be opened for reading." << std::endl;
                 exit(1);
        }
        else
        {
                std::string junk, date;
                getline(fin, junk);
                double eastEl, eastSt, westEl;
                while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
                {
                        fin.ignore(INT_MAX, '\n');
                        if (date == want)
                        {
                                fin.close();
                                return westSt;
                        }
                }
                fin.close();
        }
        return westSt;
}
double get_east_storage(std::string want)
{
	std::ifstream fin("Current_Reservoir_Levels.tsv");
	double eastSt = -1.0;
        if (fin.fail())
        {
                 std::cerr << "File cannot be opened for reading." << std::endl;
                 exit(1);
        }
        else
        {
                std::string junk, date;
                getline(fin, junk);
                double eastEl, westSt, westEl;
                while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
                {
                        fin.ignore(INT_MAX, '\n');
			if (date == want)
			{
				fin.close();
				return eastSt;
			}
                }
                fin.close();
        }
	return eastSt;
}
