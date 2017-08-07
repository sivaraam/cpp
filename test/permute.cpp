#include <string>

using std::string;

string permute(const string& s, int k) {

  string permuted_s = s;

  for(int j = 1; j < permuted_s.length(); ++j) {
    std::swap(permuted_s[k % (j + 1)], permuted_s[j]); 
    k = k / (j + 1);
  }

  return permuted_s;                             
}


