#include <iostream>
#include <fstream>
int main()
{
	std::ifstream f;
	f.open("data.txt");
	std::string s;
	while (getline(f, s))
		std::cout << s << std::endl;
	f.close();
	return 0;
}
