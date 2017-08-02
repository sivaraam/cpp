#include <locale>
#include <algorithm>
#include "playfair_cipher_helpers.h"

namespace playfair_cipher {

	void normalize(string& text) {
		// capitablize the characters
		auto& facet = std::use_facet<std::ctype<char>>(std::locale());
		facet.toupper(&text[0], &text[0] + text.length());

		const static char dummy = 'A';
		if( (text.length() % 2) != 0 ) {
			text.push_back(dummy);
		}
	}

	void normalize(string& key, size_t max_length) {
		string temp = key;
		std::string::iterator iter = key.begin();

		// for every character in key located at 'loc' tests if there are any such
		// character in range [begin, loc) and if there is the corresponding character
		// is not copied
		std::copy_if(key.begin(), key.end(), temp.begin(),
			     [&](char c) { return !std::count(key.begin(), iter++, c); });

		key = temp;
		key.resize(max_length);
	}

	// the string's length must be an order of 2
	vector< pair<char, char> > get_plain_text_pairs(const string plain_text) {
		vector< pair<char, char> > pt_pairs;

		for(size_t ch_index = 0; ch_index < plain_text.length(); ch_index += 2) {
			pt_pairs.push_back( std::make_pair(plain_text[ch_index], plain_text[ch_index+1]) );
		}

		return pt_pairs;
	}

	string cipher_text(vector< pair<char, char> > ct_pairs) {
		string cipher_text;

		for(auto ct_pair : ct_pairs) {
			auto [first_cipher_ch, second_cipher_ch] = ct_pair;
			cipher_text += first_cipher_ch;
			cipher_text += second_cipher_ch;
		}

		return cipher_text;
	}
}
