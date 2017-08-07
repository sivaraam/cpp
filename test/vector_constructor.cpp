#include <vector>
#include <iostream>

using std::vector;
using std::cout;

int main() {
  size_t size = 10;
  vector<int> v (size, 5);
  cout<<v.size()<<v[0];
}
