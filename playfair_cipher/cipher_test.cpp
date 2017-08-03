#include <iostream>
#include "playfair_cipher.h"
using std::cin;
using std::cout;
using std::string;

int main() {
	string plain_text, key;

	cout<<"Enter the key: ";
	cin>>key;

	cout<<"Enter the plain text: ";
	cin>>plain_text;

	cout<<"Cipher Digrams: "<<playfair_cipher::encrypt(plain_text, key)<<std::endl;
}
