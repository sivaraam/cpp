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
	cout<<"Enter the key matrix: \n";
	cin>>km;

	string plain_text;
	cout<<"Enter the plain text: ";
	cin>>plain_text;

	try {
		cout<<"Cipher text: "<<plain_text*km;
	} catch(std::invalid_argument ia) {
		cout<<ia.what();
		exit (EXIT_FAILURE);
	}

}
