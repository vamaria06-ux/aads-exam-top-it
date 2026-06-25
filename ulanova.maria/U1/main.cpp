#include "io.hpp"
#include "parse.hpp"

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char * argv[])
{
  std::string inFile;
  std::string outFile;
  for (int i = 1; i < argc; ++i)
  {
    const std::string arg(argv[i]);
    if (arg.size() > 3 && std::string(arg.begin(), arg.begin() + 3) == "in:")
    {
      if (!inFile.empty())
      {
        std::cerr << "Duplicate input file argument\n";
        return 1;
      }
      inFile = std::string(arg.begin() + 3, arg.end());
    }
    else if (arg.size() > 4 && std::string(arg.begin(), arg.begin() + 4) == "out:")
    {
      if (!outFile.empty())
      {
        std::cerr << "Duplicate output file argument\n";
        return 1;
      }
      outFile = std::string(arg.begin() + 4, arg.end());
    }
    else
    {
      std::cerr << "Unknown argument: " << arg << "\n";
      return 1;
    }
  }
  if (argc > 3)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }

  std::ifstream in;
  if (!inFile.empty())
  {
    in.open(inFile);
    if (!in.is_open())
    {
      std::cerr << "Cannot open input file: " << inFile << "\n";
      return 2;
    }
  }

  std::ofstream out;
  if (!outFile.empty())
  {
    out.open(outFile);
    if (!out.is_open())
    {
      std::cerr << "Cannot open output file: " << outFile << "\n";
      return 2;
    }
  }

  std::istream & in = inFile.empty() ? std::cin : in;
  std::ostream & out = outFile.empty() ? std::cout : out;

  ulanova::Array< ulanova::Person > arr = ulanova::readPersons(in);
  ulanova::printPersons(arr, out);
  std::cerr << arr.size << " " << ulanova::ignored << "\n";
  ulanova::clear(arr);
  return 0;
}
