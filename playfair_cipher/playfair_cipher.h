#include <string>
#include <vector>
#include <utility>
#include <boost/numeric/mtl/mtl.hpp>

using std::vector;
using std::string;
using std::pair;

namespace playfair_cipher {

	class playfair_table {

		// the table itself
		mtl::dense2D<char> table;
		const static size_t table_degree = 5;

		// the state of this object is not defined after
		// the invocation of initialize_table
		static string alphabets;	
	
		// used to initalize the table's contents
		void initialize_table(string key);

		public:
			// delete the unnecessary defaults
			playfair_table() = delete;
			playfair_table(const playfair_table&) = delete;
			playfair_table(playfair_table&&) = delete;
			playfair_table& operator= (const playfair_table&) = delete;
			playfair_table& operator= (playfair_table&&) = delete;

			playfair_table(const string key);
	};

	string encrypt(const string plain_text, const string key);

}
