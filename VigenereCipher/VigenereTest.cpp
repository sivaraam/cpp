#include <iostream>
#include "VigenereCipher.h"
using std::cout;
using std::cin;
using std::string;

int main() {
	string plain_text, key;

	cout<<"Enter the plain text: ";
	cin>>plain_text;

	cout<<"Enter the key: ";
	cin>>key;

	string encrypted = VigenereCipher::encrypt(plain_text, key);

	try {
		cout<<"Encrypted text: "<<encrypted<<'\n';
	} catch (std::invalid_argument in_arg) {
			std::cerr<<"WARNING: Plain text and key should contain only alphabets\n";
			exit(EXIT_FAILURE);
	}

	cout<<"Decrypted text: "<<VigenereCipher::decrypt(encrypted, key)<<'\n';
}
