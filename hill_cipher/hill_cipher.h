#include <istream>
#include <vector>
using std::string;
using std::istream;
using std::vector;

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
	class cipher_matrix{
		vector< vector<int> > matrix;
		int degree;

		public:
			// delete the unwanted defaults
			cipher_matrix() = delete;
			cipher_matrix(cipher_matrix&& cm) = delete;
			cipher_matrix(const cipher_matrix& cm) = delete;
			cipher_matrix& operator= (const cipher_matrix& cm) = delete;
			cipher_matrix& operator= (cipher_matrix&& cm) = delete;

			cipher_matrix(int degree) {
				this->degree = degree;
				// TODO how to create multiple vectors ?
				this->matrix = vector<vector<int>> { vector<int> { degree } };
			}

			// The function which should be invoked before any other
			// public method of this class; as specified in the contract.
			friend istream& operator>> (istream& is, cipher_matrix& cm);

			friend string operator* (string plain_text, const cipher_matrix& matrix);
	};

	// Helper methods
	// string operator* (const cipher_matrix& matrix, const string& plain_text);

	// Wrapper for the overloaded * operator which accepts the same parameters
	string encrypt(const cipher_matrix& matrix, const string& plaint_text);
}
