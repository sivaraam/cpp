#include <iostream>

using std::cout;
using std::cin;

// cout<<"DEBUG: ";
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

void set_digit(int &n, int index, int val) {
	int trail=(index==0)?0:n%pow(10, index);
	int lead=(index==length(n))?0:(n/pow(10,index+1));
	val=(index==0)?val:val*pow(10,index);
	n= (lead*pow(10,index+1))+val+	trail;
}

int find_odd(int n, int start_index) {
	for (int i=start_index; i>=0; i--) {
		if (get_digit(n,i)%2==1) {
			return i;
		}
	}

	return -1;
}

int find_even(int n, int start_index) {
	for (int i=start_index; i>=0; i--) {
//		cout<<"DEBUG: "<<i<<'\n';
		if (get_digit(n,i)%2==0) {
			return i;
		}
	}

	return -1;
}

void swap_digits(int &n, int src, int dest) {
	int temp = get_digit(n, src);
	set_digit(n, src, get_digit(n, dest));
	set_digit(n, dest, temp);
}

int main() {
	int num;

	cout<<"Enter a number: ";
	cin>>num;

	int len = length(num);
	if (len==1) {
		cout<<num;
		return 0;
	}

	bool odd_elem=get_digit(num, len-1)&1;

	for (int i=len-2; i>0; i--) {
		if (get_digit(num, i+1)&1) {
			// i+1 is odd
			int even_index=find_even(num, i);
//			cout<<"DEBUG: "<<i<<' '<<even_index<<'\n';
			if (even_index == -1) {
				cout<<"Cannot construct the pattern";
				return 1;
			}
			odd_elem=false;
			swap_digits(num, i, even_index);
		}
		else {
			int odd_index = find_odd(num, i);
			if (odd_index == -1) {
				cout<<"Cannot construct the pattern";
				return 1;
			}
			odd_elem=true;
			swap_digits(num, i, odd_index);
		}
	}

	if (odd_elem && (get_digit(num, 0)%2==1) ||
		!odd_elem && (get_digit(num, 0)%2==0)) {
			cout<<"Cannot construct the pattern";
			return 1;
	}

	cout <<"Result: "<<num;
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

