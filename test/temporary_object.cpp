#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::string;

void take_up_memory(int n) {
  if(n==0)
    return;
  return take_up_memory(n-1);
}

void f(const string& s1, const string& s2, const string& s3)
{
  const char* cs = (s1+s2).c_str();
  cout << cs <<std::endl;
  if (std::strlen(cs=(s2+s3).c_str())<8 && cs[0]=='a') {
    // cs used here
    // take_up_memory(10000);
    cout<<cs<<std::endl;
  }
}

int main() {
    f("HELLO", "and", "or");
}
