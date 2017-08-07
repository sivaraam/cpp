#include <iostream>
using std::cout;
/*
class test{};

class const_initializer {
  test array[10];

  const_initializer() { array[0] = test {} ;}
};

const_initializer* test_func() {}
*/
int main() {
  if(!1)
    cout<<"!1 is true!"<<'\n';
  else
    cout<<"!1 is false"<<'\n';


  cout<<"Divide by zero is undefined: "<<10/0<<std::endl;

  bool res_val = 10 / 6;
  cout<<"Storing result of division to bool is undefined: "<<res_val;

  cout<<isspace('s')<<'\n';
  cout<<isspace('\n')<<'\n';  cout<<isspace(' ')<<'\n';
  cout<<(1u << 0)<<'\n';
  cout<<1u;
  int x=10;
  cout<<!1<<'\n';
  cout<<!0<<'\n';
  cout<<"Surprise: !!"<<x<<" = "<<!!x<<'\n';
}
