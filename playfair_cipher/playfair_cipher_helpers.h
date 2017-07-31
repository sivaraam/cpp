#include <vector>
#include <tuple>
#include <string>
using std::vector;
using std::tuple;
using std::string;

namespace playfair_cipher {

	// in case the length of string isn't a multiple of 2
	// add a dummy character to make it so
	//
	// returns 'true' if normalization was done
	bool normalize(string& str);

	// remove duplicate chars and ensure it
	// contains no more than 'max_size' chars
	void normalize(string& str, size_t max_size);

	vector< tuple<char, char> > get_plain_text_tuples(const string plain_text);

}
