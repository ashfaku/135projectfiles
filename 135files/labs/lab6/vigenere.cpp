#include <iostream>
#include "funcs.h"
#include "vigenere.h"
std::string encryptVigenere(std::string o, std::string keyword)
{
	std::string r = "";
	int i = -1;
	int index = -1;
	while (o[++i])
	{
		if (!isalpha(o[i]))
		{
			r += o[i];
		}
		else
		{
			r += shiftChar(o[i], charIndex(keyword[++index % keyword.length()]));
		}
	}
	return r;
}
