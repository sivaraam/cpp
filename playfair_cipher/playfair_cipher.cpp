#include "playfair_cipher.h"
#include "playfair_cipher_helpers.h"

namespace playfair_cipher {

	const string alphabets { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	void playfair_table::initialize_table(string key) {

		normalize(key, table_degree*table_degree);

		// fill table row(s) using given key
		size_t curr_row = 0, curr_col = 0;
		for(char key_ch : key) {
			table[curr_row][curr_col] = key_ch;

			// should have erased at least and at most one character
			alphabets.erase(alphabets.find(key_ch));

			curr_col++;
			if(curr_col == table_degree) {
				curr_col = 0;
				curr_row++;
			}
		}

		// alphabet would consist of characters enough
		// to fill the rest of the table
		size_t alphabets_index = 0;
		// fill remaining cells with the rest of the alpabets
		// leave the last alphabet that wasn't added to the table
		// to be handled by the accessor implementation
		for(; curr_row < table_degree; curr_row++) {
			for(; curr_col < table_degree; curr_col++) {
				table[curr_row][curr_col] = alphabets[alphabets_index++];
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
