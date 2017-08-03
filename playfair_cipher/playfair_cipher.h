#include <string>
#include <vector>
#include <utility>
#include <boost/numeric/mtl/mtl.hpp>

using std::vector;
using std::string;
using std::pair;

namespace playfair_cipher {

	class playfair_matrix {

		const static string alphabets;

		// the table itself
		mtl::dense2D<char> table;

		// used to initalize the table's contents
		void initialize_table(string key);

		// returns the index(row, col) of the given character
		// until ch is a valid matrix entry else throws an exception
		pair<size_t, size_t> get_index(char ch);

		public:
			const static size_t common_degree = 5;

			// delete the unnecessary defaults
			playfair_matrix() = delete;
			playfair_matrix(const playfair_matrix&) = delete;
			playfair_matrix(playfair_matrix&&) = delete;
			playfair_matrix& operator= (const playfair_matrix&) = delete;
			playfair_matrix& operator= (playfair_matrix&&) = delete;

			playfair_matrix(const string key);
			pair <char, char> operator[] (pair<char, char> pt_pair);
			
			friend pair<char, char> get_cipher_pair(playfair_matrix *ptable, pair<size_t, size_t> first_index, pair<size_t, size_t>second_index);

	};

	string encrypt(string plain_text, string key);
	string decrypt(string cipher_text, string key);

}
