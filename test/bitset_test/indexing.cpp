#include <bitset>
#include <iostream>

int main() {
    std::bitset<4> bits { "1010" };
    std::cout<<"bits: "<<bits<<'\n';
    std::cout<<"bits[0]: "<<bits[0]<<'\n';
    std::cout<<"bits.to_string()[0]: "<<bits.to_string()[0]<<'\n';
}
