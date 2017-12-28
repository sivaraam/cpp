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

void set_digit(int &n, int index, int val) {
	int trail=(index==0)?0:n%pow(10, index);
	int lead=(index==length(n))?0:(n/pow(10,index+1));
	val=(index==0)?val:val*pow(10,index);
	n= (lead*pow(10,index+1))+val+	trail;
}

// n>0
// ascending insrtion sort
void sort_nums(int &n) {
	int len=length(n);

	for (int i=len-2; i>=0; i--) {
		int hole = get_digit(n, i);
		int j=i+1;
		while(j<len && get_digit(n,j)>hole) {
			set_digit(n,j-1,get_digit(n,j));
			j++;
		}
		set_digit(n, j-1, hole);
//		cout<<n;
	}
}

void dedup(int &n) {
	int res=get_digit(n,length(n)-1);
	for (int i=length(n)-2; i>=0; i--) {
//		cout<<n;
		if (get_digit(n, i)!=get_digit(n, i+1)) {
			res = res*10+get_digit(n,i);
		}
	}
	n=res;
}

int find_odds(int n) {
	int ret=0;
	while (n>0)	 {
		int last=n%10;
		if (last%2==1) {
			ret = ret*10+last;
		}
		n/=10;
	}

	return ret;
}

int find_evens(int n) {
	int ret=0;
	while (n>0)	 {
		int last=n%10;
		if (last%2==0) {
			ret = ret*10+last;
		}
		n/=10;
	}

	return ret;
}

int main() {
	int num=0;

	cout<<"Enter a number: ";
	cin>>num;

	if (num<0)
		cout<<"Invalid input!";

	sort_nums(num);
//	cout<<num;

	dedup(num);
//	cout<<'\n'<<num;

	int odds=find_odds(num);
	int evens=find_evens(num);
	cout<<"Largest sum: "<<odds+evens<<" ("<<odds<<'+'<<evens<<')';

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

