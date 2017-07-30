#include <iostream>
#include "hill_cipher.h"
using hill_cipher::key_matrix;
using std::cout;
using std::cin;

int main() {
	unsigned degree;
	cout<<"Enter the degree of the matrix: ";
	cin>>degree;

	key_matrix km {degree};
	try {
		cout<<"Enter the key matrix: \n";
		cin>>km;
	} catch (std::ios_base::failure fo) {
		cout<<fo.what()<<std::endl;
		exit(EXIT_FAILURE);
	}

	string plain_text;
	cout<<"Enter the plain text: ";
	cin>>plain_text;

	try {
		cout<<"Cipher text: "<<encrypt(plain_text, km);
	} catch(std::invalid_argument ia) {
		cout<<ia.what();
		exit(EXIT_FAILURE);
	}

}
