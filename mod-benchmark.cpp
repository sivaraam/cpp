// Implementaton to be benchmarked
#include <iostream>
#include "mod-benchmark.h"

using std::cout;

const int NUM_ARGS = 3;

static void print_options() {
  cout<<"\nOptions\n";
  cout<<"-------\n";
  cout<<"1. (k-1) % num == 0\n";
  cout<<"2. k % num == 1\n";
}

// Called by main bencmark executable when
// incorrect number of arguments are received.
void print_usage() {
  cout<<"THREE parameters required for this benchmark:\n";
  cout<<"1. Choice of option\n2. Number of cases\n3. Number to use for modular arithmetic\n";
  print_options();
}

int start_benchmark(char** argv) {
  const static int CHOICE_INDEX=1;
  const static int CASE_INDEX=2;
  const static int MOD_NUM_INDEX=3;

  int ch;
  sscanf(argv[CHOICE_INDEX], "%d", &ch);
  cout<<"Chosen: "<<ch<<'\n';

  int cases;
  sscanf(argv[CASE_INDEX], "%d", &cases);
  cout<<"Number of cases: "<<cases<<'\n';

  int num;
  sscanf(argv[MOD_NUM_INDEX], "%d", &num);
  cout<<"Number: "<<num<<'\n';

  switch(ch) {
    case 1: for(int i=1; i<=cases; i++) {
              if( ((i-1) % num) == 0 )
                cout<<"";
            }
            return EXIT_SUCCESS;

    case 2: for(int i=1; i<=cases; i++) {
              if( (i % num) == 1 )
                cout<<"";
            }
            return EXIT_SUCCESS;
  }

  return EXIT_FAILURE; // Impossible
}
