#include "CeaserCipher.h"
#include <iostream>
using CeaserCipher::WrappingWord;
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
	
	WrappingWord word {};
	cout<<"Enter plain text: ";
	cin>>word;

	unsigned int key = get_key();

	//string encrypted = CeaserCipher::encrypt(plain_text, key);
	//string decrypted = CeaserCipher::decrypt(encrypted, key);

	WrappingWord encrypted = word + key;
	WrappingWord decrypted = encrypted - key;

	cout<<"Encrypted Text: "<<encrypted<<'\n';
	cout<<"Decrypted Text: "<<decrypted<<'\n';
}
