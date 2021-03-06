#include <iostream>

using std::cout;
using std::cin;

void custom_reverse(int *array, int size) {
	if (size <= 3)
		return;

	int first_odd = 1;
	int last_odd = ((size-1)%2)?size-1:size-2;

//	cout<<"DEBUG: "<<first_odd<<' '<<last_odd;

	int f_index = first_odd, l_index = last_odd;
	int inc=2;

	while (f_index<l_index) {
//		cout<<"DEBUG: "<<f_index<<' '<<l_index;

		int temp = array[f_index];
		array[f_index] = array[l_index];
		array[l_index] = temp;

		f_index+=inc;
		l_index-=inc;
	}
}

int main() {
	unsigned size=0;
	int array[100];

	cout<<"Enter the array size: ";
	cin>>size;


	cout<<"Enter the array: ";
	for(size_t i=0; i<size; i++) {
		cin>>array[i];
	}

	custom_reverse(array, size);

	cout<<"Custom array: ";
	for(size_t i=0; i<size; i++) {
		cout<<array[i]<<' ';
	}
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

