#include <vector>
#include "railfence.hpp"
#include "railfence_helpers.hpp"
using std::string;
using std::vector;

namespace railfence {

	class railfence_matrix {
		typedef vector<char> matrix_col_type;
		typedef vector<matrix_col_type> matrix_type;

		matrix_type matrix;
		bool encryption_matrix;
		size_t rows, cols;

		public:
			railfence_matrix(unsigned length, unsigned cols, bool encrypt) {
				this-> rows = length/cols;
				this->cols = cols;

				matrix = matrix_type (rows, matrix_col_type(cols));
				encryption_matrix = encrypt;
			}

			// expects that length of 'text' is  a multiple of 'cols'
			void fill_matrix (string text) {
				size_t order_1 = 0, order_2 = 0;
				if(encryption_matrix) {
					// TODO: Check for misues
					order_1 = rows;
					order_2 = cols;
				} else {
					order_2 = rows;
					order_1 = cols;
				}

				for (size_t i = 0; i<order_1; i++) {
					for (size_t j = 0; j<order_2; j++) {
						if (encryption_matrix)
							matrix[i][j] = text[i*order_2+j];
						else
							matrix[j][i] = text[i*order_2+j];
					}
				}
			}

			string get_string() {
				size_t order_1 = 0, order_2 = 0;
				string str {};

				if(encryption_matrix) {
					order_1 = cols;
					order_2 = rows;
				} else {
					order_1 = rows;
					order_2 = cols;
				}

				for (size_t i = 0; i<order_1; i++) {
					for(size_t j = 0; j<order_2; j++) {
						if(encryption_matrix)
							str.push_back(matrix[j][i]);
						else
							str.push_back(matrix[i][j]);
					}
				}

				return str;
			}
	};

	string encrypt(string p_text, unsigned group_chars) {
		normalize(p_text, group_chars);
		railfence_matrix to_encrypt { p_text.length(), group_chars, true };
		to_encrypt.fill_matrix(p_text);
		return to_encrypt.get_string();
	}

	string decrypt(string c_text, unsigned group_chars) {
		railfence_matrix to_decrypt { c_text.length(), group_chars, false };
		to_decrypt.fill_matrix(c_text);
		return to_decrypt.get_string();
	}
}
