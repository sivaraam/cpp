#include "hill_cipher.h"
#include <vector>
#include <cmath>
#include <exception>
#include <locale>

namespace hill_cipher {

	istream& operator>> (istream& is, key_matrix& kmatrix) {
		for (size_t i=0; i<kmatrix.degree; i++) {
			for (size_t j=0; j<kmatrix.degree; j++) {
				is>>kmatrix.matrix[i][j];
				// throw exception in case of failure.
				// to halt or alter flow of program
				if(is.fail())
					throw new std::ios_base::failure{"Failed to read the key matrix"};
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

	static string cipher_text(vector< vector<int> > ct_matrices) {
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
	static auto mat_multiply(const vector<int>& pt_matrix, const vector< vector<int> >& kmatrix, unsigned degree) {
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
		unsigned original_length = plain_text.length();
		normalize(plain_text, kmatrix.degree);
		auto pt_matrices = plain_text_matrices(plain_text, kmatrix.degree);
		vector< vector<int> > ct_matrices ;

		for(auto pt_matrix : pt_matrices) {
			ct_matrices.push_back(mat_multiply(pt_matrix, kmatrix.matrix, kmatrix.degree));
		}

		// reduce the size of cipher text to the original length of plain text
		return cipher_text(ct_matrices).substr(0, original_length);
	}

	string encrypt (string plain_text, const key_matrix& kmatrix) {
		return plain_text * kmatrix;
	}
}
