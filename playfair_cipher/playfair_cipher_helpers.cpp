#include <locale>
#include <algorithm>
#include "playfair_cipher_helpers.h"

namespace playfair_cipher {

	static void capitalize(string& str) {
		// capitablize the characters
		auto& facet = std::use_facet<std::ctype<char>>(std::locale());
		facet.toupper(&str[0], &str[0] + str.length());
	}

	void normalize(string& text) {
		capitalize(text);

		const static char dummy = 'A';
		if( (text.length() % 2) != 0 ) {
			text.push_back(dummy);
		}
	}

	void normalize(string& key, size_t max_length) {
		string temp { key };
		key.clear();
		
		capitalize(temp);

		// Ensure key contains no duplicate characters
		std::string::iterator iter = temp.begin();
		// for every character in key located at 'loc' tests if there are any such
		// character in range [begin, loc) and if there is the corresponding character
		// is not copied
		std::copy_if(temp.begin(), temp.end(), std::back_inserter(key),
			     [&](char c) { return !std::count(temp.begin(), iter++, c); });

		if(key.length() > max_length)
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
