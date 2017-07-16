#include "VigenereCipher.h"

namespace VigenereCipher {

	static const char reference_ch = 'A';

	static bool is_valid_index (char index) {
		if (isalpha(index))
			return true;
		return false;
	}

	// --------------- VigenereRow -------------------
	const CeaserCipher::WrappingWord VigenereRow::base_word { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	const char VigenereRow::npos = -1;

	VigenereRow::VigenereRow() { }
	VigenereRow::VigenereRow(int index) : WrappingWord(base_word + index) { }

	char VigenereRow::operator[] (const char index) const {
		const char corrected_index = toupper(index);
		if (!is_valid_index(corrected_index))
			throw std::invalid_argument { "Index should be an alphabet" };

		size_t original_index = corrected_index - reference_ch;
		return word[original_index];
	}

	char VigenereRow::find (const char ch, size_t pos) const {
		size_t max = word.length();  // max is always 26
		for(int index=pos; index<max; index++)
			if(word[index] == ch)
				return (index+reference_ch);
		return npos;
	}
	// ------------- END : VigenereRow ----------------

	// -------------- VigenereTable --------------------
  
	VigenereTable::VigenereTable() {
		for (int curr_row=0; curr_row<total_rows; curr_row++)
			this->rows[curr_row] = VigenereRow { curr_row };
	}

	const VigenereTable& VigenereTable::getInstance() {
		//The sole instance of this class
		static VigenereTable sole_instance { };
		return sole_instance;
	}

	const VigenereRow& VigenereTable::operator[] (char index) const {
		const char corrected_index = toupper(index);
		if (!is_valid_index(corrected_index))
			throw std::invalid_argument { "Index should be an alphabet" };

		size_t original_index = corrected_index - reference_ch;
		return rows[original_index];
	}
	// --------------- END : VigenereTable -------------

	string encrypt(string plain_text, string key) {
		string encrypted_text;
		size_t key_index = 0, key_length = key.length();
		const VigenereTable& vtable = VigenereTable::getInstance();

		for(char curr_text_ch : plain_text) {
			char curr_key_ch = key[key_index];
			encrypted_text += vtable[curr_text_ch][curr_key_ch];
			key_index = (key_index + 1)%key_length;
		}
		return encrypted_text;
	}

	// The VigenereTable is a symmetric matrix thus easing the implementation
	string decrypt(string encrypted_text, string key) {
		string plain_text;
		size_t key_index = 0, key_length = key.length();
		const VigenereTable& vtable = VigenereTable::getInstance();

		for(char curr_enc_ch : encrypted_text) {
			char curr_key_ch = key[key_index];
			char plain_ch = vtable[curr_key_ch].find(curr_enc_ch);

			// This shouldn't happen. Just in case.
			if (plain_ch == VigenereRow::npos)
				throw std::invalid_argument("Encrypted text contains invalid characters");

			plain_text += plain_ch;
			key_index = (key_index + 1)%key_length;
		}
		return plain_text;
	}
}
