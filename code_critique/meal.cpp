#include "meal.h"

#include <iostream>
#include <list>

struct attendee
{
   std::string name;
   meal meals; // set of meals
};

using attendees = std::list<attendee>;

attendees get_attendees(std::istream &is)
{
  attendees result;
  std::string line;
  while (std::getline(is, line))
  {
    std::istringstream iss(line);
    std::string name;
    iss >> name;
    meal meal, meals{};
    while (iss >> meal)
      meals += meal; // add in each meal
    if (is.fail())
      throw std::runtime_error("Input error");
    result.push_back({name, meals});
  }
  return result;
}

size_t count(attendees a, meal m)
{
  size_t result{};
  for (auto &item : a)
  {
    // Check 'm' present in meals
    if ((item.meals & m) == m)
      ++result;
  }
  return result;
}

int main()
try
{
  auto attendees{ get_attendees( std::cin) };

  std::cout << "Total: " << attendees.size();
  for (auto m : {meal::breakfast, meal::lunch, meal::dinner})
  {
    std::cout << ' ' << m <<  ": " <<
      count(attendees, m);
  }
  std::cout << '\n';
}
catch (std::exception &ex)
{
  std::cout << ex.what() << '\n';
}
