#include "CeaserCipher.h"

namespace CeaserCipher {

	static char get_alphabet(char current, int offset) {
		static const size_t TOTAL_ALPHABETS=26;

		int ch_with_offset = (current-'A') + offset + ((offset < 0) ? TOTAL_ALPHABETS : 0);
		unsigned int rounded = ch_with_offset % TOTAL_ALPHABETS;

		return char(rounded+'A');
	}

	//------------- BEGIN : Auxiliary methods for 'WrappingAlphabet' -------------
	WrappingAlphabet operator+(const WrappingAlphabet& old, int offset) {
		return WrappingAlphabet{get_alphabet(old.ch, offset)};
	}

	WrappingAlphabet operator-(const WrappingAlphabet& old, int offset) {
		return WrappingAlphabet{get_alphabet(old.ch, offset)};
	}

	std::ostream& operator<<(std::ostream& out, const WrappingAlphabet& wa) {
		out<<wa.ch;
		return out;
	}
	//------------- END : Auxiliary methods for 'WrappingAlphabet' --------------



	//------------- BEGIN : Auxiliary methods for 'WrappingWord' --------------
	WrappingWord::WrappingWord() : word {} { }

	WrappingWord::WrappingWord(string word) {
		for (char ch : word)
			if(!isalpha(ch))
				throw std::invalid_argument {"Word should contain only alphabets"};

		this->word = word;
	}

	WrappingWord operator+(const WrappingWord& old, int offset) {
		string wrapped {};
	
		for(char ch : old.word) {
			WrappingAlphabet curr_ch { ch };
			wrapped += (curr_ch+offset).get_char();
		}

		return WrappingWord {wrapped};
	}

	WrappingWord operator-(const WrappingWord& old, int offset) {
		string wrapped {};
	
		for(char ch : old.word) {
			WrappingAlphabet curr_ch { ch };
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
	//------------- END : Auxiliary methods for 'WrappingWord' --------------



	string encrypt(const string& plain_text, int key) {
		string encrypted_text {};

		for(char ch : plain_text) {
			WrappingAlphabet curr_ch { ch };
			encrypted_text += (curr_ch+key).get_char();
		}

		return encrypted_text;
	}

	string decrypt(const string& encrypted_text, int key) {
		string plain_text {};

		for(char ch : encrypted_text) {
			WrappingAlphabet curr_ch { ch };
			plain_text += (curr_ch-key).get_char();
		}

		return plain_text;
	}

}
