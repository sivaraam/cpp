#include <iostream>
#include "ceaser_cipher.h"
//using ceaser_cipher::WrappingWord;
using std::string;
using std::cout;
using std::cin;

unsigned int get_key() {
	int key;
	cout<<"Enter key (> 0): ";
	cin>>key;
	if(key < 0) {
		std::cerr<< "Key must be positive\n";
		exit(1);
	}
	return key;
}

int main() {
	
//	WrappingWord word {};
	string plain_text;
	cout<<"Enter plain text: ";
	cin>>plain_text;

	unsigned int key = get_key();

	string encrypted = ceaser_cipher::encrypt(plain_text, key);
	string decrypted = ceaser_cipher::decrypt(encrypted, key);

	cout<<"Encrypted Text: "<<encrypted<<'\n';
	cout<<"Decrypted Text: "<<decrypted<<'\n';
}
