#include <bitset>
#include <iostream>

int main() {
  std::bitset<8> bits { "10111000" };
  std::bitset<8> higher_bits_mask { "11110000" };
  std::bitset<8> lower_bits_mask { "00001111" };
  std::bitset<4> higher_bits (bits & higher_bits_mask);
  std::cout<<higher_bits<<'\n';
  std::size_type n = 10;
  std::cout<<(bits & lower_bits_mask)<<'\n';
}
