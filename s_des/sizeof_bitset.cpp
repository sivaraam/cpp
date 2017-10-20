#include <iostream>
#include <bitset>

int main() {
	std::bitset<100> bits;
	std::cout<<sizeof(bits)<<'\n';
	std::cout<<"bits.size(): "<<bits.size();
}
