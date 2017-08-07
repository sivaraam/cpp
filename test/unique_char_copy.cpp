#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;

int main() {
	
	string input, normalized;
	cout<<"Enter a string (possibly with duplicated characters): ";
	cin>>input;

	cout<<"Input string: "<<input<<'\n';

	auto iter = input.begin();
	// for every character in input located at 'loc' tests if there are any such
	// character in range [begin, loc) and if there is the corresponding character
	// is not copied
	std::copy_if(input.begin(), input.end(), std::back_inserter(normalized),
		     [&](char c) { return !std::count(input.begin(), iter++, c); });
//	auto back_inserter = std::back_inserter(normalized);
//	back_inserter = 'a';

	cout<<"Normalized string: "<<normalized<<std::endl;

}
