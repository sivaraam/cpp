#pragma once

#include <iosfwd>
#include <sstream>
#include <string>

enum class meal : int
{
   breakfast=1, lunch=2, dinner=4,
};

// Used for name <=> value conversion
struct
{
  meal value;
  std::string name;
} names[] =
{
  { meal::breakfast, "breakfast" },
  { meal::lunch, "lunch" },
  { meal::dinner, "dinner" },
};

std::istream &operator>>(std::istream &is, 
  meal &m)
{
  std::string name;
  if (is >> name)
  {
    for (auto p : names)
    {
      if (p.name == name) {
        m = p.value;
        return is;
      }
    }
  }
  is.setstate(std::ios::failbit);
  return is;
}
   
std::ostream &operator<<(std::ostream &os, 
  meal const m)
{
  for (auto p : names)
  {
    if (p.value == m)
      os << p.name;
  }
  return os;
}

// Type-safe operations
constexpr meal operator+(meal a, meal b)
{
  return meal(int(a) + int(b));
}

meal operator+=(meal &a, meal b)
{
  a = a + b;
  return a;
}

constexpr meal operator|(meal a, meal b)
{
  return meal(int(a) | int(b));
}

constexpr meal operator&(meal a, meal b)
{
  return meal(int(a) & int(b));
}

// Check distinctness
static_assert((meal::breakfast | meal::lunch |
 meal::dinner) == (meal::breakfast +
 meal::lunch + meal::dinner), "not distinct");

