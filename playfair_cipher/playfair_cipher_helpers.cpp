#include "playfair_cipher_helpers.h"

namespace playfair_cipher {

	// in case the length isn't a multiple of 2
	// add a dummy character to make it so
	// returns 'true' if normalization was done
	bool normalize(string& text) {
		const static char dummy = 'A';
		if( (text.length() % 2) != 0 ) {
			text.push_back(dummy);
			return true;
		}
		return false;
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
