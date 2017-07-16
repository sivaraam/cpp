#include "VigenereCipher.h"

namespace VigenereCipher {

	static bool is_valid_index (char index) {
		if (isalpha(index))
			return true;
		return false;
	}

	// --------------- VigenereRow -------------------
	const CeaserCipher::WrappingWord VigenereRow::base_word { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	VigenereRow::VigenereRow() { }
	VigenereRow::VigenereRow(int index) : WrappingWord(base_word + index) { }

	char VigenereRow::operator[] (const char index) const {
		if (!is_valid_index(index)) {
			throw std::invalid_argument { "Index should be an alphabet" };
		}

		size_t original_index = toupper(index) - 'A';
		return word[original_index];
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
		if (!is_valid_index(index))
			throw std::invalid_argument { "Index should be an alphabet" };

		size_t original_index = toupper(index) - 'A';
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
}
