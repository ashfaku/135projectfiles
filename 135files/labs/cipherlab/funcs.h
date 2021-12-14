#pragma once
#include <vector>
std::vector<double> getLetterFreqs(std::string input);
std::string encryptCaesar(std::string o, int shift);
char shiftChar(char o, int sh);
int charIndex(char o);
std::string solve(std::string encrypted_string);
