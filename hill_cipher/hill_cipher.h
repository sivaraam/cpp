#include <vector>
#include <istream>
using std::string;
using std::vector;
using std::istream;

namespace hill_cipher {

	// Contract:
	//
	//	There is a contract between the methods that reference
	//	this class and the overloaded "input stream"
	//	operator.
	//
	//	Any methods that references this class must be invoked only
	//	after the "successful" invocation of the overloaded input
	//	stream operator atleast once. Else, the behaviour is "undefined".
	// 
	class key_matrix{
		vector< vector<int> > matrix;
		unsigned degree;

		public:
			// delete the unwanted defaults
			key_matrix() = delete;
			key_matrix(key_matrix&& cm) = delete;
			key_matrix(const key_matrix& cm) = delete;
			key_matrix& operator= (const key_matrix& cm) = delete;
			key_matrix& operator= (key_matrix&& cm) = delete;

			key_matrix(unsigned degree) {
				this->degree = degree;
				this->matrix = vector<vector<int>> (degree, vector<int> (degree));
			}

			// The function which should be invoked before any other
			// public method of this class; as specified in the contract.
			friend istream& operator>> (istream& is, key_matrix& cm);

			friend string operator* (string plain_text, const key_matrix& kmatrix);
	};

	// Helper methods
	// string operator* (string plain_text, const key_matrix& kmatrix);

	// Wrapper for the overloaded * operator which accepts the same parameters
	string encrypt(string plain_text, const key_matrix& kmatrix);
}
