#include <fstream>
#include <iostream>

int main() {
  std::ofstream outputFile;
  outputFile.open("hello.txt", std::ios::out);
  outputFile << "Hello, World!";
  outputFile.close();

  std::ifstream inputFile;
  inputFile.open("hello.txt", std::ios::in);
  std::string fileMessage = "";
  char c = '\0';
  while (inputFile.get(c))
    fileMessage += c;

  std::cout << fileMessage << std::endl;
  return 0;
}
