#include <iostream>
using namespace std;
void remove_e(string& sentence)
{
	for (int i = sentence.length() - 1; i > -1; i--)
		if (sentence[i] == 'e')
		    sentence.erase(i, 1);
}
