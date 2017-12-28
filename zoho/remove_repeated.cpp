#include <iostream>

using std::cout;
using std::cin;

int pow(int base, int pow) {
	long int res=1;
	for (; pow>0; pow--) {
		res *= base;
	}
	return res;
}

// cout<<"DEBUG: ";
unsigned length(int n) {
	unsigned len=0;
	while (n>0) {
		len++;
		n/=10;
	}
	return len;
}

// returns ith last digit
// (1234, 0) => 4
int get_digit(int n, int i) {
	if (i==0)
		return n%10;
	else
		return ((n%pow(10, i+1))-(n%pow(10,i)))/pow(10,i);
}

void remove_digit(int &n, int index) {
	int lead=(index==length(n))?0:(n/pow(10,index+1));
	int trail=(index==0)?0:n%pow(10, index);
	n=(lead*pow(10,index))+trail;
}

int main() {
	int num;

	cout<<"Enter a number: ";
	cin>>num;

	int len = length(num);

//	remove_digit(num,2);
//	cout<<num;
	for (int i=length(num)-2; i>=0; i--) {
		int j=i+1;
		while(j<length(num)) {
			if (get_digit(num, i)==get_digit(num, j)) {
				cout<<"Removing "<<get_digit(num, i)<<" from position "<<len-i<<'\n';
				remove_digit(num, i);
			}
			j++;
		}
	}

	cout<<"Result: "<<num;
}
//
//#include <cstring>
//#include <algorithm>
//#include <string>
//#include <cmath>
//
//using std::cout;
//using std::cin;
//using std::vector;
//using std::string;

