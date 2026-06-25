#include <iostream>
#include <fstream>
#include <string>
#include "person.hpp"

int main(int c, char** v)
{
  if (c > 3) return 1;

  std::string f_in = "", f_out = "";
  bool has_in = 0, has_out = 0;

  for (int i = 1; i < c; ++i)
  {
    std::string arg = v[i];
    if (arg.substr(0, 3) == "in:" && !has_in)
    {
      f_in = arg.substr(3);
      has_in = 1;
    }
    else if (arg.substr(0, 4) == "out:" && !has_out)
    {
      f_out = arg.substr(4);
      has_out = 1;
    }
    else
    {
      return 1;
    }
  }

  std::istream* sin = &std::cin;
  std::ostream* sout = &std::cout;
  std::ifstream f1;
  std::ofstream f2;

  if (has_in)
  {
    f1.open(f_in);
    if (!f1.is_open()) return 2;
    sin = &f1;
  }

  if (has_out)
  {
    f2.open(f_out);
    if (!f2.is_open()) return 2;
    sout = &f2;
  }

  petrov::Person* arr = nullptr;
  size_t sz = 0, cap = 0;
  size_t ok = 0, err = 0;

  while (*sin)
  {
    size_t id;
    if (!(*sin >> id))
    {
      sin->clear();
      std::string s;
      if (std::getline(*sin, s))
      {
        if (s.find_first_not_of(" \t\r\n") != std::string::npos)
        {
          err++;
        }
      }
      continue;
    }
  }
  return 0;
}
