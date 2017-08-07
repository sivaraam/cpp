#include <iostream>
#include <algorithm>

int main() {
	std::string text;
	std::cout<<"Enter text: ";
	std::cin>>text;

	auto start = text.begin();
	const char dummy = 'X';
	do {
		auto adjacent_pos = std::adjacent_find(start, text.end());
		if(adjacent_pos != text.end()) {
			text.insert(adjacent_pos+1, dummy);
			start = adjacent_pos + 2;
		} else {
			break;
		}

	}while(true);

	std::cout<<"Result: "<<text<<std::endl;
	
}
