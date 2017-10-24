#include "railfence_helpers.hpp"
using std::string;

namespace railfence {
	void normalize(string &str, unsigned length_should_divide) {
		const static char filler = 'x';
		int length = str.length();

		// TODO : fix unwatned padding
		unsigned to_fill = length_should_divide - (str.length() % length_should_divide);

		while (to_fill > 0) {
			str.push_back(filler);
			to_fill--;
		}
	}
}
