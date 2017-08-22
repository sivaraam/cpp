#include <iostream>

int main() {
    int read_octal = 0;
    int in_octal = 020;
    std::cin>>read_octal;
    std::cout<<(read_octal & in_octal)<<'\n';
    std::cout<<read_octal<<'\n'<<in_octal<<'\n';
}
