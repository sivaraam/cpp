#include "hill_cipher.h"
#include <vector>
#include <cmath>
#include <exception>
#include <locale>

namespace hill_cipher {

	istream& operator>> (istream& is, key_matrix& kmatrix) {
		// throw exception in case of failure.
		// to halt or alter flow of program
		is.exceptions(std::ios_base::failbit);
		for (size_t i=0; i<kmatrix.degree; i++) {
			for (size_t j=0; j<kmatrix.degree; j++) {
				is>>kmatrix.matrix[i][j];
			}
		}

		return is;
	}


	const static char reference_val = 'A';

	static bool is_valid(int val) {
		if(val>=0 && val<26)
			return true;

		return false;
	}

	// converts value in range [0,26) to the correspondinng uppercase character
	static char value(int val) {
		if(!is_valid(val)) {
			throw new std::invalid_argument("Not a valid char value\n"
							"Only values in range [0, 26) are valid");
		}

		return (val + reference_val);
	}

	// creates 1*degree matrices from the given vector of integers
	static auto int_matrices(vector<int> vals, unsigned degree) {

		// convert degree to double to trigger floating-point division
		const size_t matrix_num = ceil(vals.size() / double(degree));

		// 'matrix_num' vectors of size 'degree'
		vector< vector<int> > matrices (matrix_num);

		for(size_t curr_matrix_index=0; curr_matrix_index < matrix_num; curr_matrix_index++) {

			for(size_t curr_val_index=0; curr_val_index < degree; curr_val_index++) {

				size_t val_index = curr_matrix_index * degree + curr_val_index;
				matrices[curr_matrix_index].push_back(vals[val_index]);

			}

		}

		return matrices;
	}

	static bool is_valid(char ch) {
		if(isalpha(ch) && isupper(ch))
			return true;

		return false;
	}

	// converts uppercase alphabet to a value in range [0, 26)
	static int value(char ch) {
		if(!is_valid(ch))
			throw new std::invalid_argument("Not a valid character\n"
							"Only uppercase alphabets are valid");
		return (ch - reference_val);
	}

	// returns a vector of int values for the characters in 'input'
	// the input is expected to be "normalized"
	static vector<int> int_values(string input) {
		const size_t vector_size = input.length();
		vector<int> int_vals (vector_size);

		for(size_t i=0; i<vector_size; i++)
			int_vals[i] = value(input[i]);

		return int_vals;
	}

	// creates a 1*degree matrices from the given plain_text
	// all characters of plaint text are expected to be "normalized"
	static auto plain_text_matrices(string plain_text, unsigned degree) {
		// get the int values of characters
		vector<int> int_vals = int_values(plain_text);

		return int_matrices(int_vals, degree);
	}

	// 1. converts all character to uppercase
	// 2. further, pad plain_text with 'reference_val' in case it's
	//    length isn't a multiple of degree
	static void normalize(string& input, unsigned degree) {
		auto& facet = std::use_facet<std::ctype<char>>(std::locale());
		facet.toupper(&input[0], &input[0] + input.length());

		const int missing_nums = (degree * ceil( input.length()/double(degree) ) - input.length());;
		for(size_t i=0; i<missing_nums; i++)
			input += reference_val;
	}

	string operator* (string plain_text, const key_matrix& kmatrix) {
		normalize(plain_text, kmatrix.degree);
		auto pt_matrices = plain_text_matrices(plain_text, kmatrix.degree);


	}
}
