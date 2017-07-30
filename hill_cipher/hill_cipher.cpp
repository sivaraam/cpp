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

		return (val + 'A');
	}

	static void pad_with_zeros(vector<int>& vec_to_pad, size_t zero_num) {
               for(size_t i=0; i<zero_num; i++)
                       vec_to_pad.push_back(0);
	}

	// creates 1*degree matrices from the given vector of integers
	static auto int_matrices(vector<int> vals, unsigned degree) {

		// convert degree to double to trigger floating-point division
		const size_t matrix_num = ceil(vals.size() / double(degree));

		// 'matrix_num' vectors of size 'degree'
		vector< vector<int> > matrices (matrix_num);

		// pad 'vals' with zeros in case it isn't a multiple of degree
		const int missing_nums = vals.size() % degree;
		pad_with_zeros(vals, missing_nums);

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
		return (ch - 'A');
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

	// converts all character to uppercase
	static void normalize(string& input) {
		auto& facet = std::use_facet<std::ctype<char>>(std::locale());
		facet.toupper(&input[0], &input[0] + input.length());
	}

	string operator* (string plain_text, const key_matrix& kmatrix) {
		normalize(plain_text);
		auto pt_matrices = plain_text_matrices(plain_text, kmatrix.degree);


	}
}
