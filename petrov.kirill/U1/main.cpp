#include <iostream>
#include <fstream>
#include <string>
#include "person.hpp"

int main(int argc, char* argv[])
{
  if (argc > 3)
  {
    return 1;
  }

  std::string file_in = "";
  std::string file_out = "";

  for (int i = 1; i < argc; ++i)
  {
    std::string arg = argv[i];
    if (!arg.find("in:"))
    {
      file_in = arg.substr(3);
    }
    else if (!arg.find("out:"))
    {
      file_out = arg.substr(4);
    }
    else
    {
      return 1;
    }
  }

  std::istream* in = &std::cin;
  std::ostream* out = &std::cout;
  std::ifstream fin;
  std::ofstream fout;

  if (file_in != "")
  {
    fin.open(file_in);
    if (!fin.is_open())
    {
      return 2;
    }
    in = &fin;
  }

  if (file_out != "")
  {
    fout.open(file_out);
    if (!fout.is_open())
    {
      return 2;
    }
    out = &fout;
  }
  return 0;
}
