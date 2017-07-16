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

			char to_char();
			WrappingAlphabet& operator= (char ch);

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

			string to_str();

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
