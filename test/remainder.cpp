#include <iostream>
#include <cmath>

void print(std::string expr, int res) {
	std::cout << expr << " : " << res << std::endl;
}
int main() {
	print("-1 % 5", -1%5);
	print("std::remainder(-1, 5)", std::remainder(-1, 5));
}
