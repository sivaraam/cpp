#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::vector;
using std::string;

// sorted str of integers expected
string remove_duplicates(string str) {
	string res;

	// push first element
	res.push_back(str[0]);

	for (size_t i=1; i<str.length(); i++) {
		if (str[i] != str[i-1])
			res.push_back(str[i]);
	}

	return res;
}

int main() {
	string input;
	string integer;

	cout<<"Enter a integer value: ";
	cin>>input;

	integer = input;

	// sort the integers
	std::sort(integer.begin(), integer.end());

	// remove duplicates
	string dedup_integer = remove_duplicates(integer);

	// handle leading zero
	if (dedup_integer.length()>1 && dedup_integer[0] == '0') {
		std::swap(dedup_integer[0], dedup_integer[1]);
	}

	cout<<"Smallest number from "<<input<<" is :"<<dedup_integer;
}
