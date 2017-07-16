#include "CeaserCipher.h"

namespace CeaserCipher {

	static bool is_valid(char ch) {
		if(isalpha(ch))
			return true;
		return false;
	}

	//---------------- BEGIN : 'WrappingAlphabet' ------------------
	WrappingAlphabet::WrappingAlphabet() : ch('A') { }

	WrappingAlphabet::WrappingAlphabet(char ch) {
		// Always store character in uppercase
		// Initialize without check to prevent improper state of object
		this->ch = toupper(ch);

		if(!is_valid(this->ch)) {
			throw std::invalid_argument { "Not an alphabet" };
		}
	}

	char WrappingAlphabet::get_char() { return ch; }

	WrappingAlphabet& WrappingAlphabet::operator= (char ch) {
		char upper_ch = toupper(ch);
		if (!is_valid(upper_ch))
			throw std::invalid_argument { "Not an alphabet" };

		this->ch = upper_ch;
		return *this;
	}

	//---------------- BEGIN : Auxiliary methods ------------------
	static char get_alphabet(char current, int offset) {
		static const size_t TOTAL_ALPHABETS=26;

		int ch_with_offset = (current-'A') + offset + ((offset < 0) ? TOTAL_ALPHABETS : 0);
		unsigned int rounded = ch_with_offset % TOTAL_ALPHABETS;

		return char(rounded+'A');
	}

	WrappingAlphabet operator+(const WrappingAlphabet& old, int offset) {
		return WrappingAlphabet{get_alphabet(old.ch, offset)};
	}

	WrappingAlphabet operator-(const WrappingAlphabet& old, int offset) {
		return WrappingAlphabet{get_alphabet(old.ch, -offset)};
	}

	std::ostream& operator<<(std::ostream& out, const WrappingAlphabet& wa) {
		out<<wa.ch;
		return out;
	}
	//----------------- END : Auxiliary methods  -------------------
	//------------------ END : 'WrappingAlphabet' ------------------


	//--------------- BEGIN : 'WrappingWord' ---------------------
	WrappingWord::WrappingWord() : word {} { }

	WrappingWord::WrappingWord(string word) {
		for (char ch : word)
			if(!is_valid(ch))
				throw std::invalid_argument {"Word should contain only alphabets"};

		this->word = word;
	}

	//------------- BEGIN : Auxiliary methods ---------------------
	WrappingWord operator+(const WrappingWord& old, int offset) {
		string wrapped {};
		WrappingAlphabet curr_ch;

		for(char ch : old.word) {
			curr_ch = ch;
			wrapped += (curr_ch+offset).get_char();
		}

		return WrappingWord {wrapped};
	}

	WrappingWord operator-(const WrappingWord& old, int offset) {
		string wrapped {};
		WrappingAlphabet curr_ch;

		for(char ch : old.word) {
			curr_ch = ch;
			wrapped += (curr_ch-offset).get_char();
		}

		return WrappingWord {wrapped};
	}

	std::ostream& operator<<(std::ostream& out, const WrappingWord& wword) {
		out<<wword.word;
		return out;
	}

	std::istream& operator>>(std::istream& in, WrappingWord& wword) {
		string input_word;
		in>>input_word;
		wword = WrappingWord { input_word };
	}
	//------------- END : Auxiliary methods  ----------------------
	//--------------- END : 'WrappingWord' ------------------------

	string encrypt(const string& plain_text, int key) {
		string encrypted_text {};
		WrappingAlphabet curr_ch;

		for(char ch : plain_text) {
			curr_ch = ch;
			encrypted_text += (curr_ch+key).get_char();
		}

		return encrypted_text;
	}

	string decrypt(const string& encrypted_text, int key) {
		string plain_text {};
		WrappingAlphabet curr_ch;

		for(char ch : encrypted_text) {
			curr_ch = ch;
			plain_text += (curr_ch-key).get_char();
		}

		return plain_text;
	}

}
