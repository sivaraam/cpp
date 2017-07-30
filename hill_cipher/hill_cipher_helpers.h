#include <vector>
#include <string>
using std::string;
using std::vector;

namespace hill_cipher {

	void normalize(string& input, unsigned degree);
	
	vector< vector<int> > plain_text_matrices(string plain_text, unsigned degree);
	
	vector<int> mat_multiply(const vector<int>& pt_matrix, const vector< vector<int> >& kmatrix, unsigned degree);

	string cipher_text(vector< vector<int> > ct_matrices);

}
