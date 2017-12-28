#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cout;
using std::cin;
using std::vector;

int find_closest_mid(vector<int> v, int find) {
	size_t low=0, high=v.size();
//	cout<<"DEBUG: "<<v.size()<<'\n';
	size_t mid=(low+high)/2;

	while(low<high) {
		if(v[mid] == find)
			return mid;
		else if(find<v[mid])
				high= mid-1;
			 else if(v[mid] < find)
			 		low=mid+1;
			 	  else
			 	  	cout<<"BUG!";
		mid=(low+high)/2;
//		cout<<"\nDEBUG: "<<mid;
	}

//	cout<<"\nDEBUG: "<<mid;
	return mid;
}

int main() {
	size_t num;

	// get number of elements in array
	cout<<"Enter the number of elements in array: ";
	cin>>num;

	vector<int> array(num);

	// get the input array
	cout<<"Enter the arrray elements: ";
	for (size_t i=0; i<num; i++) {
		cin>>array[i];
	}

	// find the average
	int average=0;
	for (size_t i=0; i<num; i++) {
		average+=array[i];
	}
	average /= num;

	cout<<"Average is: "<<average<<'\n';

	// find the closest element to average
	//std::vector<int>::iterator = array.begin();
	std::sort(array.begin(), array.end());

//	for(size_t i=0; i<num; i++)
//		cout<< array[i]<<' ';
//
	int closest=0;
	size_t mid = find_closest_mid(array, average);
	int abs_previous_diff = abs(array[mid-1]-average);
	int abs_mid_diff = abs(array[mid]-average);
	int abs_next_diff = abs(array[mid+1]-average);

	if(abs_mid_diff < abs_next_diff && abs_mid_diff < abd_previous_diff)
		closest=array[mid];
	else if (abs_previous_diff<abs_next_diff)
			closest = array[mid-1];
		else
			closest = array[mid+1];

	cout<<"Array element closest to the average is: "<<closest;
}
