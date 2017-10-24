#include <iostream>
#include "railfence.hpp"
using std::string;
using std::cin;
using std::cout;

int main() {
	string input {};
	unsigned group_chars;

	cout<<"Enter the plain text: ";
	cin>>input;
	cout<<"Enter the number of characters in group: ";
	cin>>group_chars;

	string encrypted = railfence::encrypt(input, group_chars);

	cout<<"Encrypted text: "<<encrypted<<std::endl;
	cout<<"Decrypted text: "<<railfence::decrypt(encrypted, group_chars)<<std::endl;
}
