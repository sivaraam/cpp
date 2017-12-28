#include <iostream>

using std::cout;
using std::cin;

// Returns,
// 0 - a == b
// 1 - a > b
// -1 - a < b
int (*cmp)(int a, int b);

int asc(int a, int b) {
	if (a==b) {
		return 0;
	}
	if (a>b) {
		return 1;
	}
	return -1;
}

int desc(int a, int b) {
	if (a==b) {
		return 0;
	}
	if (a<b) {
		return 1;
	}
	return -1;
}

void ins_sort(int *begin, int *end, int (*cmp)(int a, int b)) {
	int *ptr=begin+1;
	// insertion sort
	for (; ptr != end; ptr++) {
		int *ptr_copy=ptr-1;
		int hole = *ptr;

		while ((ptr_copy>=begin) && cmp(*(ptr_copy), hole)>0) {
			*(ptr_copy+1) = *ptr_copy;
			ptr_copy--;
		}

		*(ptr_copy+1) = hole;
	}

}

void custom_sort(int *array, int size) {
	unsigned mid=size/2;
	bool is_odd=size%2;

	if(size==1)
		return;

	if(is_odd) {
		ins_sort(array, array+mid, asc);
		ins_sort(array+mid+1, array+size, desc);
	}
	else {
		ins_sort(array, array+mid, asc);
		ins_sort(array+mid, array+size, desc);
	}
}

int main() {
	int array[100];
	size_t size;

	cout<<"Enter the array size: ";
	cin>>size;

	cout<<"Enter the array: ";
	for(size_t i=0; i<size; i++) {
		cin>>array[i];
	}

//	ins_sort(array, array+size, asc);
	custom_sort(array, size);

	cout<<"Sorted array: ";
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

