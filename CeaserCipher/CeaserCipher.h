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

			// Used at
			//
			//		return WrappingAlphabet{get_alphabet(old.ch, offset)};
			//	and
			//		return WrappingAlphabet{get_alphabet(old.ch, -offset)};
			//
			WrappingAlphabet(WrappingAlphabet&&) = default;

			// delete the unwanted defaults
			WrappingAlphabet(const WrappingAlphabet&) = delete;
			WrappingAlphabet& operator= (const WrappingAlphabet&) = delete;
			WrappingAlphabet& operator= (WrappingAlphabet&&) = delete;

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
			WrappingWord() = default;
			explicit WrappingWord(string word);

			// Used at
			//
			//		VigenereRow::VigenereRow(int index) : WrappingWord (base_word + index) { }
			// and
			//		return WrappingWord {wrapped};
			//
			WrappingWord(WrappingWord&&) = default;


			// delete the unwanted defaults
			WrappingWord(const WrappingWord&) = delete;
			WrappingWord& operator= (const WrappingWord&) = delete;


			// Used as 'VigenereRow' requires move assignment
			// Used at
			//
			//		this->rows[curr_row] = VigenereRow { curr_row };
			//
			WrappingWord& operator= (WrappingWord&&) = default;

			string to_str();

			friend WrappingWord operator+(const WrappingWord& old, int offset);
			friend WrappingWord operator-(const WrappingWord& old, int offset);
			friend std::ostream& operator<<(std::ostream& out, const WrappingWord& wa);
			friend std::istream& operator>>(std::istream& in, WrappingWord& wword);
	};

//	WrappingAlphabet operator+(const WrappingAlphabet& old, int offset);       Works without these
//	std::ostream& operator<<(std::ostream& out, const WrappingAlphabet& wa);

	string encrypt(const string& plain_text, int key);
	string decrypt(const string& encrypted_text, int key);

}

#endif
