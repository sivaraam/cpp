#include <exception>
#include "hill_cipher.h"
#include "hill_cipher_helpers.h"

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
