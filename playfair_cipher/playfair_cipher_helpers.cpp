#include <algorithm>
#include "playfair_cipher_helpers.h"

namespace playfair_cipher {

	static void capitalize(string& str) {
		// capitablize the characters
		std::transform(str.begin(), str.end(), str.begin(),
				[](unsigned char c) { return std::toupper(c); });
	}

	static void strip_spaces(string& str) {
		string temp { str };
		str.clear();

		std::remove_copy_if(temp.begin(), temp.end(), std::back_inserter(str),
				[](char ch) { return isspace(ch); });
	}

	void normalize(string& text) {
		strip_spaces(text);
		capitalize(text);

		const static char dummy = 'X';

		// in case of duplicate characters insert 'dummy'
		auto start = text.begin();
		do {
			auto adjacent_pos = std::adjacent_find(start, text.end());
			if(adjacent_pos != text.end()) {
				text.insert(adjacent_pos+1, dummy);
				start = adjacent_pos + 2;
			} else {
				break;
			}
		} while(true);

		// in case length is not even append a 'dummy'
		if( (text.length() % 2) != 0 ) {
			text.push_back(dummy);
		}
	}

	void normalize(string& key, size_t max_length) {
		string temp { key };
		key.clear();
		
		strip_spaces(temp);
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
	vector< pair<char, char> > get_text_pairs(const string text) {
		vector< pair<char, char> > pt_pairs;

		for(size_t ch_index = 0; ch_index < text.length(); ch_index += 2) {
			pt_pairs.push_back( std::make_pair(text[ch_index], text[ch_index+1]) );
		}

		return pt_pairs;
	}

	string cipher_text(vector< pair<char, char> > ct_pairs) {
		string cipher_text;

		for(auto ct_pair : ct_pairs) {
			auto [first_cipher_ch, second_cipher_ch] = ct_pair;
			cipher_text += first_cipher_ch;
			cipher_text += second_cipher_ch;
			cipher_text += " ";
		}

		return cipher_text;
	}

	int floor_mod(int dividend, int divisor) {
		//you can check for divisor == 0 separately and do what you want
		if(divisor < 0)
			return floor_mod(dividend, -divisor);

		int ret = dividend % divisor;
		if(ret < 0)
			ret+=divisor;
		return ret;
	}
}
