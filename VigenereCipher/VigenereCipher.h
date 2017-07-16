#include "../CeaserCipher/CeaserCipher.h"

#ifndef VIGENERE_CIPHER
#define VIGENERE_CIPHER

namespace VigenereCipher {

	class VigenereRow : private CeaserCipher::WrappingWord {

		private:
			static const CeaserCipher::WrappingWord base_word;
			static const char npos;

		public:
			VigenereRow();
			explicit VigenereRow(int index);
			
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
			VigenereTable(VigenereTable const&) = delete;
			void operator=(VigenereTable const&) = delete;

			static const VigenereTable& getInstance();

			const VigenereRow& operator[] (char index) const;
	};

	string encrypt(string plain_text, string key);

}

#endif
