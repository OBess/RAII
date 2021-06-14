// C++
#include <iostream>

// Custom
#include "include/c_file.hpp"

void WriteToFile(const std::string &message)
{
   c_file file("test.txt");
   file << message;
}

int main()
{
   WriteToFile("Hello ");
   WriteToFile("World!");
   WriteToFile("!");
   return EXIT_SUCCESS;
}