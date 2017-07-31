#include <vector>
#include <tuple>
#include <string>
using std::vector;
using std::tuple;
using std::string;

namespace playfair_cipher {

	vector< tuple<char, char> > get_plain_text_tuples(const string plain_text);

}
