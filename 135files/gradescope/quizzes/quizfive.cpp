#include <iostream>
#include <fstream>
int main()
{
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 5; j++)
			std::cout << "*" << (j < 4 ? " " : "\n");
	return 0;
}
