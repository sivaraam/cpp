#include "ceaser_cipher.h"


namespace ceaser_cipher {

	static bool is_valid(char ch) {
		if(isalpha(ch))
			return true;
		return false;
	}

	//---------------- BEGIN : 'wrapping_alphabet' ------------------
	wrapping_alphabet::wrapping_alphabet() : ch('A') { }

	wrapping_alphabet::wrapping_alphabet(char ch) {
		// Always store character in uppercase
		// Initialize without check to prevent improper state of object
		this->ch = toupper(ch);

		if(!is_valid(this->ch)) {
			throw std::invalid_argument { "Not an alphabet" };
		}
	}

	char wrapping_alphabet::to_char() { return ch; }

	wrapping_alphabet& wrapping_alphabet::operator= (char ch) {
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

	wrapping_alphabet operator+(const wrapping_alphabet& old, int offset) {
		return wrapping_alphabet{get_alphabet(old.ch, offset)};
	}

	wrapping_alphabet operator-(const wrapping_alphabet& old, int offset) {
		return wrapping_alphabet{get_alphabet(old.ch, -offset)};
	}

	std::ostream& operator<<(std::ostream& out, const wrapping_alphabet& wa) {
		out<<wa.ch;
		return out;
	}
	//----------------- END : Auxiliary methods  -------------------
	//------------------ END : 'wrapping_alphabet' ------------------


	//--------------- BEGIN : 'wrapping_word' ---------------------
	wrapping_word::wrapping_word(string word) : word { word } {
		// Initialize without check to prevent improper state of object
		// It won't do much harm.
		for (char ch : this->word)
			if(!is_valid(ch))
				throw std::invalid_argument {"Word should contain only alphabets"};
	}

	string wrapping_word::to_str() { return word; }

	//------------- BEGIN : Auxiliary methods ---------------------
	wrapping_word operator+(const wrapping_word& old, int offset) {
		string wrapped {};
		wrapping_alphabet curr_ch;

		for(char ch : old.word) {
			curr_ch = ch;
			wrapped += (curr_ch+offset).to_char();
		}

		return wrapping_word {wrapped};
	}

	wrapping_word operator-(const wrapping_word& old, int offset) {
		string wrapped {};
		wrapping_alphabet curr_ch;

		for(char ch : old.word) {
			curr_ch = ch;
			wrapped += (curr_ch-offset).to_char();
		}

		// TODO : Find the reason behind the resulting output
		// obtained as a result of commenting the following
		// return statement.
		return wrapping_word {wrapped};
	}

	std::ostream& operator<<(std::ostream& out, const wrapping_word& wword) {
		out<<wword.word;
		return out;
	}

	std::istream& operator>>(std::istream& in, wrapping_word& wword) {
		string input_word;
		in>>input_word;
		wword = wrapping_word { input_word };
		return in;
	}
	//------------- END : Auxiliary methods  ----------------------
	//--------------- END : 'wrapping_word' ------------------------

	string encrypt(const string& plain_text, int key) {
		wrapping_word plain_wword {plain_text};

		return (plain_wword+key).to_str();
	}

	string decrypt(const string& encrypted_text, int key) {
		wrapping_word encrypted_wword{encrypted_text};

		return (encrypted_wword-key).to_str();
	}

}
