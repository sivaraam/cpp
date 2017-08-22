#include <iostream>
#include "string_reverse.h"

using std::string;

int main() {
  string str;
  std::cout<<"Enter a string: ";
  std::cin>>str;

  std::cout<<"Reversed string: "<<unique::reverse(str);
}
