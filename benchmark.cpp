#include <iostream>
#include "mod-benchmark.h"

auto validate_args(int argc) {
  if(argc < NUM_ARGS) {
    print_usage();
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char** argv) {
  validate_args(argc);
  return start_benchmark(argv);
}
