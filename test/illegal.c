#include <stdio.h>

int main() {
  char i = 0;
  char j = 0;
  char* p = &i;
  void* q = p;
  int* pp = q;
  *pp = -1;
  printf("i: %c j: %c\n", i, j);
  printf("sizeof(char): %zd sizeof(int): %zd\n", sizeof(char), sizeof(int));
}
