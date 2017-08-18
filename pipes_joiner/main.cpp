#include <iostream>
#include "pipe_joiner.h"

int main() {

  pipe_joiner_solver::pipe_joiner pj_instance;

  std::cout<<"Enter the number of pipes followed by their lengths:\n";
  std::cin>>pj_instance;

  std::cout<<"\nSolution (length of pipes joined):\n";
  std::cout<<pj_instance;
}
