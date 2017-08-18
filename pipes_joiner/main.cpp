#include <iostream>
#include <limits>
#include "pipe_joiner.h"

using pipe_joiner_solver::pipe_joiner;

void read_input(pipe_joiner& pj_instance) {
  do {
      std::cout<<"Enter the number of pipes followed by their lengths:"<<std::endl;
      std::cin>>pj_instance;

      if(std::cin.fail()) {
        std::cout<<"Bad input. Try again.\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // empty the current line
      }
      else {
        break;
      }
  } while(true);
}

int main() {

  pipe_joiner_solver::pipe_joiner pj_instance;

  read_input(pj_instance);

  std::cout<<"\nSolution (length of pipes joined):\n";
  std::cout<<pj_instance;

  exit(EXIT_SUCCESS);
}
