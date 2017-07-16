#include "../CeaserCipher/CeaserCipher.h"

#ifndef VIGENERE_CIPHER
#define VIGENERE_CIPHER

namespace VigenereCipher {

	class VigenereRow : private CeaserCipher::WrappingWord {

		private:
			static const CeaserCipher::WrappingWord base_word;

		public:
			VigenereRow();
			explicit VigenereRow(int index);
			
			char operator[] (const char index) const;
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
