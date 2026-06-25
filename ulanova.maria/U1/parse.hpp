#ifndef PARSE_HPP
#define PARSE_HPP

#include "io.hpp"

#include <iostream>

namespace ulanova
{
  size_t ignored = 0;

  Array< Person > readPersons(std::istream & in);
}

#endif
