#include "playfair_cipher.h"
#include "playfair_cipher_helpers.h"

namespace playfair_cipher {

	const string alphabets { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	void playfair_table::initialize_table(string key) {

		// remove duplicate chars
		normalize(key);

		// fill table row(s) using given key
		// fill remaining cells with the rest of the alpabets
		// leave the last alphabet that wasn't added to the table
		// to be handled by the accessor implementation
		const key_length = key.length();
		for(size_t curr_row = 0; curr_row < table_degree; curr_row++) {
			for(size_t curr_col = 0; curr_col < table_degree; curr_col++) {
				const size_t key_index = curr_row * table_degree + curr_col;
				if(key_index < key_length) {
					const char key_ch = key[key_index];
					table[curr_row][curr_col] = key_ch;
					alphabets.remove(key_ch);
				}
				else {
					static size_t alphabets_index = 0;
					if(alphabets_index < alphabets.length()) {
						char remaining_alphabet = alphabets[alphabets_index++];
						table[curr_row][curr_col] = remaining_alphabet;
					}
				}
			}
		}
	
	}

	playfair_table::playfair_table(const string key) : table(table_degree, vector<char>(table_degree)) {
		initialize_table(key);
	}

	string encrypt(string plain_text, string key) {
		playfair_table ptable { key };
		vector< tuple<char, char> > ct_tuples;
		bool normalized = normalize(plain_text);
		auto pt_tuples = get_plain_text_tuples(plain_text);

		for(auto pt_tuple : pt_tuples)
			ct_tuples.push_back(ptable(pt_tuple));

		return cipher_text(ct_tuples, normalized);
	}
}
