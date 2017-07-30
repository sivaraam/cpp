#include <cmath>
#include <locale>
#include "hill_cipher_helpers.h"

namespace hill_cipher {

	const static char reference_val = 'A';

	static bool is_valid(int val) {
		if(val>=0 && val<26)
			return true;

		return false;
	}

	// converts value in range [0,26) to the correspondinng uppercase character
	static char value(int val) {
		if(!is_valid(val)) {
			throw new std::invalid_argument{"Not a valid char value\n"
							"Only values in range [0, 26) are valid"};
		}

		return (val + reference_val);
	}

	static string get_cipher_text(vector<int> ct_matrix) {
		string partial_cipher_text;

		for(int i_val : ct_matrix) {
			partial_cipher_text += value(i_val);
		}

		return partial_cipher_text;
	}

	string cipher_text(vector< vector<int> > ct_matrices) {
		string cipher_text;

		for(auto ct_matrix : ct_matrices) {
			cipher_text += get_cipher_text(ct_matrix);
		}

		return cipher_text;
	}

	// multiples the given plain text (P) matrix and the key matrix (K) as follows:
	//
	// 	(E * P) % total_chars
	//
	// i.e., values of the resultant matrix is in range [0, total_chars)
	//
	// Assumptions:
	//	* kmatrix is a square matrix of order 'degree*degree'
	//	* pt_matrix is of order '1*degree'
	vector<int> mat_multiply(const vector<int>& pt_matrix, const vector< vector<int> >& kmatrix, unsigned degree) {
		vector<int> ct_matrix (degree);
		const static int total_chars = 26;

		for(size_t km_col=0; km_col<degree; km_col++) {
			for(size_t inter=0; inter<degree; inter++) {
				ct_matrix[km_col] += pt_matrix[inter] * kmatrix[inter][km_col];
			}
			ct_matrix[km_col] %= total_chars;
		}

		return ct_matrix;
	}

	// creates 1*degree matrices from the given vector of integers
	static auto int_matrices(vector<int> vals, unsigned degree) {

		// convert degree to double to trigger floating-point division
		const size_t matrix_num = ceil(vals.size() / double(degree));

		// 'matrix_num' vectors
		vector< vector<int> > matrices (matrix_num);

		for(size_t curr_int_matrix=0; curr_int_matrix < matrix_num; curr_int_matrix++) {

			for(size_t curr_int=0; curr_int < degree; curr_int++) {

				size_t val_index = curr_int_matrix * degree + curr_int;
				matrices[curr_int_matrix].push_back(vals[val_index]);

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
			throw new std::invalid_argument{"Not a valid character\n"
							"Only uppercase alphabets are valid"};
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
	vector< vector<int> > plain_text_matrices(string plain_text, unsigned degree) {
		// get the int values of characters
		vector<int> int_vals = int_values(plain_text);

		return int_matrices(int_vals, degree);
	}

	// 1. converts all character to uppercase
	// 2. further, pad plain_text with 'reference_val' in case it's
	//    length isn't a multiple of degree
	void normalize(string& input, unsigned degree) {
		auto& facet = std::use_facet<std::ctype<char>>(std::locale());
		facet.toupper(&input[0], &input[0] + input.length());

		const int missing_nums = (degree * ceil( input.length()/double(degree) ) - input.length());;
		for(size_t i=0; i<missing_nums; i++)
			input += reference_val;
	}

}
