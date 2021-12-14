#include <iostream>
#include "funcs.h"
#include <vector>
#include <math.h>
#include <stdio.h>
#include <fstream>
int charIndex(char o)
{
        int ascii = (int) o - (isupper(o) ? (int) 'A' : (int) 'a');
        return ascii % 26;
}
char shiftChar(char o, int sh)
{
        if (!isalpha(o) || sh == 0)
                return o;
        int index;
        if (sh > 0)
        {
                int a = isupper(o) ? (int) 'A' : (int) 'a';
                index = (((int) o + sh - a) % 26) + a;
        }
        else
        {
                int z = isupper(o) ? (int) 'Z' : (int) 'z';
                index = (((int) o + sh - z) % 26) + z;
        }
        return (char) index;
}
std::string encryptCaesar(std::string o, int shift)
{
	std::string s = "";
	int index = -1;
	while (o[++index])
		s += shiftChar(o[index], shift);
	return s;
}
std::string decryptCaesar(std::string e, int sh)
{
        std::string r = "";
        int index = -1;
        while (e[++index])
                r += shiftChar(e[index], -sh);
        return r;
}
std::vector<double> getLetterFreqs(std::string input)
{
	std::vector<double> ints;
	int letters = 0;
	while (ints.size() < 26)
		ints.push_back(0.0);
	for (int i = 0; i < input.length(); i++)
	{
		if (isalpha(input[i]))
		{
			ints.at(charIndex(input[i]))++;
			letters++;
		}
	}
	for (int j = 0; j < ints.size(); j++)
		ints.at(j) /= letters;
	return ints;
}
double distance(std::vector<double> a, std::vector<double> b)
{
        double d = 0.0;
        for (int i = 0; i < a.size(); i++)
        {
                if (a.at(i) > b.at(i))
                        d += sqrt(pow(a.at(i), 2) - pow(b.at(i), 2));
                else
                        d += sqrt(pow(b.at(i), 2) - pow(a.at(i), 2));
        }
        return d / 26.0;
}
std::string solve(std::string encrypted_string)
{
        std::string text = "", s;
        std::ifstream o("english.txt");
        while (getline(o, s))
                text += s;
        std::vector<double> e = getLetterFreqs(text);
        double min = 100000000, index;
        for (int i = 0; i < 26; i++)
        {
                std::vector<double> check;
                while (check.size() < 26)
                        check.push_back(0.0);
                int letters = 0;
                for (int p = 0; p < encrypted_string.length(); p++)
                {
                        if (isalpha(encrypted_string[p]))
                        {
                                int hold = charIndex(encrypted_string[p]) + i;
                                check.at(hold % 26)++;
                                letters++;
                        }
                }
                for (int p = 0; p < check.size(); p++)
                        check.at(p) /= letters;
                double d = distance(check, e);
                if (d < min)
                {
                        index = i;
                        min = d;
                }
        }
        return decryptCaesar(encrypted_string, 26 - index);
}
