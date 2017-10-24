#include "railfence_helpers.hpp"
#include <cmath>
using std::string;

namespace railfence {

	// returns the number of elements needed to be
	// added to make 'num' a multiple of 'base'
	//
	// The return value is in range [0, base)
	unsigned to_make_multiple(size_t num, unsigned base) {
		return std::ceil(float(num)/base)*base - num;
	}

	void normalize(string &str, unsigned length_should_divide) {
		const static char filler = 'x';
		unsigned length = str.length();

		unsigned to_fill = to_make_multiple(length, length_should_divide);

		while (to_fill > 0) {
			str.push_back(filler);
			to_fill--;
		}
	}
}
