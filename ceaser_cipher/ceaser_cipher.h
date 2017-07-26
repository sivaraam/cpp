#include <iostream>
#include <locale>
using std::string;

#ifndef CEASER_CIPHER
#define CEASER_CIPHER

namespace ceaser_cipher {
	class wrapping_alphabet {
		private:
			char ch;

		public:
			wrapping_alphabet();
			explicit wrapping_alphabet(char ch);

			// Used at
			//
			//		return wrapping_alphabet{get_alphabet(old.ch, offset)};
			//	and
			//		return wrapping_alphabet{get_alphabet(old.ch, -offset)};
			//
			wrapping_alphabet(wrapping_alphabet&&) = default;

			// delete the unwanted defaults
			wrapping_alphabet(const wrapping_alphabet&) = delete;
			wrapping_alphabet& operator= (const wrapping_alphabet&) = delete;
			wrapping_alphabet& operator= (wrapping_alphabet&&) = delete;

			char to_char();
			wrapping_alphabet& operator= (char ch);

			friend wrapping_alphabet operator+(const wrapping_alphabet& old, int offset);
			friend wrapping_alphabet operator-(const wrapping_alphabet& old, int offset);
			friend std::ostream& operator<<(std::ostream& out, const wrapping_alphabet& wa);
	};


	class wrapping_word {
		protected:
			string word;
		public:
			wrapping_word() = default;
			explicit wrapping_word(string word);

			// Used at
			//
			//		VigenereRow::VigenereRow(int index) : wrapping_word (base_word + index) { }
			// and
			//		return wrapping_word {wrapped};
			//
			wrapping_word(wrapping_word&&) = default;


			// delete the unwanted defaults
			wrapping_word(const wrapping_word&) = delete;
			wrapping_word& operator= (const wrapping_word&) = delete;


			// Used as 'VigenereRow' requires move assignment
			// Used at
			//
			//		this->rows[curr_row] = VigenereRow { curr_row };
			//
			wrapping_word& operator= (wrapping_word&&) = default;

			string to_str();

			friend wrapping_word operator+(const wrapping_word& old, int offset);
			friend wrapping_word operator-(const wrapping_word& old, int offset);
			friend std::ostream& operator<<(std::ostream& out, const wrapping_word& wa);
			friend std::istream& operator>>(std::istream& in, wrapping_word& wword);
	};

//	wrapping_alphabet operator+(const wrapping_alphabet& old, int offset);       Works without these
//	std::ostream& operator<<(std::ostream& out, const wrapping_alphabet& wa);

	string encrypt(const string& plain_text, int key);
	string decrypt(const string& encrypted_text, int key);

}

#endif
