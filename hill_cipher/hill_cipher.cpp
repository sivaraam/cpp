#include "hill_cipher.h"
#include <vector>
#include <cmath>
#include <exception>

namespace hill_cipher {

	istream& operator>> (istream& is, cipher_matrix& cmatrix) {

		for (int i=0; i<cmatrix.degree; i++) {
			for (int j=0; j<cmatrix.degree; j++) {
				is>>cmatrix.matrix[i][j];
				/* TODO	
				if(is::fail) {
					throw new std::exception("Could not read the cipher matrix");
				}*/
			}

		}

		return is;
	}

	static bool is_valid(char ch) {

		if(isalpha(ch) && isupper(ch))
			return true;

		return false;

	}

	// converts uppercase alphabet to a value iin range [0, 26)
	static int value(char ch) {

		if(!is_valid(ch))
			throw new std::invalid_argument("Not a valid character\n"
								  "Only uppercase alphabets are valid");
		return (ch - 'A');

	}

	static bool is_valid(int val) {

		if(val>=0 && val<26)
			return true;

		return false;

	}

	// converts value in range [0,26) to the correspondinng uppercase character
	static char value(int val) {

		// TODO check 'expected type_specifier' ans 'std' doesn't name a type
		if(!is_valid(val)) {
			throw new std::invalid_argument { "Not a valid char value\n"
								    "Only values in range [0, 26) are valid" };
		}

		return (val + 'A');

	}

	// TODO
	// converts all character to uppercase
	static void normalize(string& input) {
		
	}

	// returns a vector of int values for the characters in 'input'
	// the input is expected to be "normalized"
	static vector<int> int_values(string input) {

		const size_t vector_size = input.length();
		vector<int> int_vals (vector_size);

		for(char ch : input)
			int_vals.push_back(value(ch));

		return int_vals;

	}

	// creates 1*degree matrices from the given vector of integers
	static auto int_matrices(vector<int> vals, int degree) {

		// convert degree to double to trigger floating-point division
		const size_t matrix_num = ceil(vals.size() / double(degree));

		// 'matrix_num' vectors of size 'degree'
		vector< vector<int> > matrices (matrix_num, vector<int>(degree));

		for(int curr_matrix_index=0; curr_matrix_index < matrix_num; curr_matrix_index++) {
			for(int curr_val_index=0; curr_val_index < degree; curr_val_index++) {
				int val_index = curr_matrix_index * degree + curr_val_index;

				matrices[curr_matrix_index].push_back(vals[val_index]);
			}
		}

		return matrices;

	}

	// creates a 1*degree matrices from the given plain_text
	// all characters of plaint text are expected to be "normalized"
	static auto plain_text_matrices(string plain_text, int degree) {
		// get the int values of characters
		vector<int> int_vals = int_values(plain_text);

		return int_matrices(int_vals, degree);
		
	}

	string operator* (string plain_text, const cipher_matrix& matrix) {
		normalize(plain_text);

		auto pt_matrices = plain_text_matrices(plain_text, matrix.degree);
	}
}
