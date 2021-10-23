#include <iostream>
#include "funcs.h"
std::string decryptCaesar(std::string e, int sh)
{
	std::string r = "";
	int index = -1;
	while (e[++index])
		r += shiftChar(e[index], -sh);
	return r;
}
std::string decryptVigenere(std::string e, std::string key)
{
	std::string r = "";
	int i = -1;
	int index = -1;
	while (e[++i])
	{
		if (!isalpha(e[i]))
			r += e[i];
		else
			r += shiftChar(e[i], -charIndex(key[++index % key.length()]));
	}
	return r;
}
