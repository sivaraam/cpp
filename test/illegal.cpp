#include <iostream>

int main() {
  char i = 0;
  char j = 0;
  char* p = &i;
  void* q = p;
  int* pp = q;
  *pp = -1;
}
