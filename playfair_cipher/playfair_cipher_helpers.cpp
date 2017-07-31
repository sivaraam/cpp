#include <algorithm>
#include "playfair_cipher_helpers.h"

namespace playfair_cipher {

	bool normalize(string& text) {
		const static char dummy = 'A';
		if( (text.length() % 2) != 0 ) {
			text.push_back(dummy);
			return true;
		}
		return false;
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
	vector< tuple<char, char> > get_plain_text_tuples(const string plain_text) {
		vector< tuple<char, char> > pt_tuples;

		for(size_t ch_index = 0; ch_index < plain_text.length(); ch_index += 2) {
			pt_tuples.push_back( std::make_tuple(plain_text[ch_index], plain_text[ch_index+1]) );
		}

		return pt_tuples;
	}
}
