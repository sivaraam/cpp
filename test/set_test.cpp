#include <iostream>
#include <set>
using std::cin;
using std::cout;

int main() {
  std::set<int> x;
  x.insert(10);
  x.insert(5);
  x.insert(2);
  auto first_val = *x.begin();
  x.erase(x.begin());
  auto second_val = *x.begin();
  x.erase(x.begin());
  cout<<first_val<<' '<<second_val;
  x.insert(first_val+second_val);
  for(auto val : x)
    cout<<val;
}
