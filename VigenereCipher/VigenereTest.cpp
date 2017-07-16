#include "VigenereCipher.h"
#include <iostream>
using VigenereCipher::VigenereTable;
using std::string;
using std::cout;
using std::cin;

int main() {
	string plain_text, key;

	cout<<"Enter the plain text: ";
	cin>>plain_text;

	cout<<"Enter the key: ";
	cin>>key;

	try {
		cout<<"Encrypted text: "<<VigenereCipher::encrypt(plain_text, key)<<'\n';
	} catch (std::invalid_argument in_arg) {
			std::cerr<<"WARNING: Plain text and key should contain only alphabets\n";
			exit(EXIT_FAILURE);
	}
}
