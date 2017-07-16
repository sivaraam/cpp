#include <iostream>
#include "VigenereCipher.h"
using std::cout;
using std::cin;
using std::string;

int main() {
	string plain_text, key, encrypted;

	cout<<"Enter the plain text: ";
	cin>>plain_text;

	cout<<"Enter the key: ";
	cin>>key;

	try {
		encrypted = VigenereCipher::encrypt(plain_text, key);
	} catch (std::invalid_argument in_arg) {
			std::cerr<<"WARNING: Plain text and key should contain only alphabets\n";
			exit(EXIT_FAILURE);
	}

	cout<<"Encrypted text: "<<encrypted<<'\n';
	cout<<"Decrypted text: "<<VigenereCipher::decrypt(encrypted, key)<<'\n';
}
