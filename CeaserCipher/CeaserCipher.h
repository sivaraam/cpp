#include <iostream>
#include <locale>
using std::string;

#ifndef CEASER_CIPHER
#define CEASER_CIPHER

namespace CeaserCipher {
	class WrappingAlphabet {
		private:
			char ch;

		public:
			WrappingAlphabet();
			explicit WrappingAlphabet(char ch);

			char get_char();

			// increment operators
			WrappingAlphabet& operator++ ();  //pre-increment operator
			WrappingAlphabet& operator++ (int); //post-increment operator

			//decrement operators
			WrappingAlphabet& operator-- (); //pre-decrement operator
			WrappingAlphabet& operator-- (int); //post-decrement operator

			friend WrappingAlphabet operator+(const WrappingAlphabet& old, int offset);
			friend WrappingAlphabet operator-(const WrappingAlphabet& old, int offset);
			friend std::ostream& operator<<(std::ostream& out, const WrappingAlphabet& wa);
	};


	class WrappingWord {
		protected:
			string word;
		public:
			WrappingWord();
			explicit WrappingWord(string word);

			friend WrappingWord operator+(const WrappingWord& old, int offset);
			friend WrappingWord operator-(const WrappingWord& old, int offset);
			friend std::ostream& operator<<(std::ostream& out, const WrappingWord& wa);
			friend std::istream& operator>>(std::istream& in, WrappingWord& wword);
	};

//	WrappingAlphabet operator+(const WrappingAlphabet& old, int offset);       Works without these
//	std::ostream& operator<<(std::ostream& out, const WrappingAlphabet& wa);

//	string encrypt(const string& plain_text, int key);
//	string decrypt(const string& encrypted_text, int key);

}

#endif
