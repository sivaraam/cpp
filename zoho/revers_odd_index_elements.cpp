#include <iostream>

using std::cout;
using std::cin;

void custom_reverse(int *array, int size) {
	if (size <= 3)
		return;

	int first_odd=1;
	int inc=2;

	for (int i=first_odd+inc; i<size; i+=inc) {
		for (int j=i-inc; j>=first_odd; j-=inc) {
			// swap j and next element
			int temp = array[j];
			array[j] = array[j+inc];
			array[j+inc] = temp;
		}
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

