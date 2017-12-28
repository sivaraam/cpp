#include <iostream>

using std::cout;
using std::cin;

unsigned length(int n) {
	unsigned len=0;
	while (n>0) {
		len++;
		n/=10;
	}
	return len;
}

int circular_shift(int n) {
	int last = n%10;
	int rest = n/10;
	int rest_len = length(rest);

	for (int zeros=rest_len; zeros>0; zeros--)
		last *= 10;

	return	last+rest;
}

int main() {
	int num1=0, num2=0;

	// get the input
	cout<<"Enter two numbers: ";
	cin>>num1>>num2;

	unsigned num1_len = length(num1);
	unsigned num2_len = length(num2);

	if (num1_len != num2_len) {
		cout<<"No";
		return 0;
	}

	int len = num1_len;

	for (unsigned i=0; i<len; i++) {
		num2 = circular_shift(num2);

		if(num2 == num1) {
			cout<<"Yes";
			return 0;
		}
	}

	cout<<"No";
}
