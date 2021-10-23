#include <iostream>

void printString(std::string s)
{
    int i = -1;
    while (s[++i])
         std::cout << s[i] << " " << (int) s[i] << std::endl;
}
void printTest(std::string s)
{
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "String is \"" << s <<  "\"" << std::endl;
	printString(s);
}
int main()
{
	printTest("cat and dog");
	printTest("Dog and car");
	printTest("Lab six");
	return 0;
}
