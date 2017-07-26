#include "vigenere_cipher.h"

namespace vigenere_cipher {

	static const char reference_ch = 'A';

	static bool is_valid_index (char index) {
		if (isalpha(index))
			return true;
		return false;
	}

	// --------------- vigenere_row -------------------
	const ceaser_cipher::wrapping_word vigenere_row::base_word { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	const char vigenere_row::npos = -1;

	vigenere_row::vigenere_row(int index) : wrapping_word{base_word + index} { }

	char vigenere_row::operator[] (const char index) const {
		const char corrected_index = toupper(index);
		if (!is_valid_index(corrected_index))
			throw std::invalid_argument { "Index should be an alphabet" };

		size_t original_index = corrected_index - reference_ch;
		return word[original_index];
	}

	char vigenere_row::find (const char ch, size_t pos) const {
		size_t max = word.length();  // max is always 26
		for(int index=pos; index<max; index++)
			if(word[index] == ch)
				return (index+reference_ch);
		return npos;
	}
	// ------------- END : vigenere_row ----------------

	// -------------- vigenere_table --------------------
	vigenere_table::vigenere_table() {
		for (int curr_row=0; curr_row<total_rows; curr_row++)
			this->rows[curr_row] = vigenere_row { curr_row };
	}

	const vigenere_table& vigenere_table::getInstance() {
		//The sole instance of this class
		static vigenere_table sole_instance { };
		return sole_instance;
	}

	const vigenere_row& vigenere_table::operator[] (char index) const {
		const char corrected_index = toupper(index);
		if (!is_valid_index(corrected_index))
			throw std::invalid_argument { "Index should be an alphabet" };

		size_t original_index = corrected_index - reference_ch;
		return rows[original_index];
	}
	// --------------- END : vigenere_table -------------

	string encrypt(string plain_text, string key) {
		string encrypted_text;
		size_t key_index = 0, key_length = key.length();
		const vigenere_table& vtable = vigenere_table::getInstance();

		for(char curr_text_ch : plain_text) {
			char curr_key_ch = key[key_index];
			encrypted_text += vtable[curr_text_ch][curr_key_ch];
			key_index = (key_index + 1)%key_length;
		}
		return encrypted_text;
	}

	// The Vigenere table is a symmetric matrix thus easing the implementation
	string decrypt(string encrypted_text, string key) {
		string plain_text;
		size_t key_index = 0, key_length = key.length();
		const vigenere_table& vtable = vigenere_table::getInstance();

		for(char curr_enc_ch : encrypted_text) {
			char curr_key_ch = key[key_index];
			char plain_ch = vtable[curr_key_ch].find(curr_enc_ch);

			// This shouldn't happen. Just in case.
			if (plain_ch == vigenere_row::npos)
				throw std::invalid_argument("Encrypted text contains invalid characters");

			plain_text += plain_ch;
			key_index = (key_index + 1)%key_length;
		}
		return plain_text;
	}

}
