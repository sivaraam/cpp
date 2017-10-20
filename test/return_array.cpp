#include <iostream>

int* get_arr() {
    int a[] = { 10, 20, 30, 50};
    return a;
}

int main() {
    int* arr = get_arr();

    for(size_t i=0; i<4; i++)
      std::cout<<*(arr+i);
}
