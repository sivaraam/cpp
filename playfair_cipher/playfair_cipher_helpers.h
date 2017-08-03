#include <vector>
#include <string>
#include <utility>
using std::vector;
using std::pair;
using std::string;

namespace playfair_cipher {

	// convert all chars to uppercase
	// in case the length of string isn't a multiple of 2
	// add a dummy character to make it so
	void normalize(string& str);

	// remove duplicate chars and ensure it
	// contains no more than 'max_size' chars
	void normalize(string& str, size_t max_size);

	vector< pair<char, char> > get_text_pairs(const string text);

	string cipher_text(vector< pair<char, char> > cipher_char_pairs);

	int floor_mod(int dividend, int divisor);
}
