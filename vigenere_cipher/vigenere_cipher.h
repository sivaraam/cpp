#include "../ceaser_cipher/ceaser_cipher.h"

#ifndef VIGENERE_CIPHER
#define VIGENERE_CIPHER

namespace vigenere_cipher {

	class vigenere_row : private ceaser_cipher::wrapping_word {

		private:
			static const ceaser_cipher::wrapping_word base_word;

		public:
			static const char npos;

			vigenere_row() = default;
			explicit vigenere_row(int index);

			// delete the unwanted defaults
			vigenere_row(const vigenere_row&) = delete;
			vigenere_row(vigenere_row&&) = delete;
			vigenere_row& operator=(const vigenere_row&) = delete;

			// Used at
			//
			//         this->rows[curr_row] = vigenere_row { curr_row };
			//
			vigenere_row& operator=(vigenere_row&&) = default;
			char operator[] (const char index) const;
			// find the (char-based) index of the given character in the row
			// if not found it returns vigenere_row::npos
			char find (const char ch, size_t pos=0) const;
	};

	class vigenere_table {
		private:
			const static size_t total_rows = 26;
			vigenere_row rows[total_rows];

			// Make the class singleton
			vigenere_table();

		public:
			// delete the unwanted defaults
			vigenere_table(const vigenere_table&) = delete;
			vigenere_table(vigenere_table&&) = delete;
			vigenere_table& operator=(const vigenere_table&) = delete;
			vigenere_table& operator=(vigenere_table&&) = delete;

			static const vigenere_table& getInstance();
			const vigenere_row& operator[] (char index) const;
	};

	string encrypt(string plain_text, string key);
	string decrypt(string encrypted_text, string key);

}

#endif
