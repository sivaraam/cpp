#include "../CeaserCipher/CeaserCipher.h"

#ifndef VIGENERE_CIPHER
#define VIGENERE_CIPHER

namespace VigenereCipher {

	class VigenereRow : private CeaserCipher::WrappingWord {

		private:
			static const CeaserCipher::WrappingWord base_word;

		public:
			static const char npos;

			VigenereRow() = default;
			explicit VigenereRow(int index);

			// delete the unwanted defaults
			VigenereRow(const VigenereRow&) = delete;
			VigenereRow(VigenereRow&&) = delete;
			VigenereRow& operator=(const VigenereRow&) = delete;
			
			// Used at
			//
			//         this->rows[curr_row] = VigenereRow { curr_row };
			//
			VigenereRow& operator=(VigenereRow&&) = default;
			char operator[] (const char index) const;
			// find the (char-based) index of the given character in the row
			// if not found it returns VigenereRow::npos
			char find (const char ch, size_t pos=0) const;
	};

	class VigenereTable {
		private:
			const static size_t total_rows = 26;
			VigenereRow rows[total_rows];

			// Make the class singleton
			VigenereTable();

		public:
			// delete the unwanted defaults
			VigenereTable(const VigenereTable&) = delete;
			VigenereTable(VigenereTable&&) = delete;
			VigenereTable& operator=(const VigenereTable&) = delete;
			VigenereTable& operator=(VigenereTable&&) = delete;

			static const VigenereTable& getInstance();
			const VigenereRow& operator[] (char index) const;
	};

	string encrypt(string plain_text, string key);
	string decrypt(string encrypted_text, string key);

}

#endif
