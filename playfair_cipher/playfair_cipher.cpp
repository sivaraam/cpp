#include "playfair_cipher.h"
#include "playfair_cipher_helpers.h"

namespace playfair_cipher {

	const string playfair_table::alphabets { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	void playfair_table::initialize_table(string key) {

		string alphabets_copy {alphabets};

		// fill table row(s) using given key
		size_t curr_row = 0, curr_col = 0;
		for(char key_ch : key) {
			table[curr_row][curr_col] = key_ch;

			// should have erased at least and at most one character
			alphabets_copy.erase(alphabets_copy.find(key_ch), 1);

			curr_col++;
			if(curr_col == common_degree) {
				curr_col = 0;
				curr_row++;
			}
		}

		// alphabet would consist of characters enough
		// to fill the rest of the table
		size_t alphabets_copy_index = 0;
		// fill remaining cells with the rest of the alpabets
		// leave the last alphabet that wasn't added to the table
		// to be handled by the accessor implementation
		for(; curr_row < common_degree; curr_row++) {
			for(; curr_col < common_degree; curr_col++) {
				table[curr_row][curr_col] = alphabets_copy[alphabets_copy_index++];
			}
			curr_col=0;
		}
	
	}

	playfair_table::playfair_table(const string key) : table (common_degree, common_degree) {
		initialize_table(key);
	}

	pair<char, char> get_cipher_pair(playfair_table *ptable, pair<size_t, size_t> first_index, pair<size_t, size_t>second_index) {
		auto [first_row, first_col] = first_index;
		auto [first_cipher_row, first_cipher_col] = first_index;
		auto [second_row, second_col] = second_index;
		auto [second_cipher_row, second_cipher_col] = second_index;

		const static size_t degree = playfair_table::common_degree;

		if (first_row == second_row) {
			first_cipher_col = (first_col + 1) % degree;
			second_cipher_col = (second_col + 1) % degree;
		}
		else if (first_col == second_col) {
			first_cipher_row = (first_row + 1) % degree;
			second_cipher_row = (second_row + 1) % degree;
		}
		else {
			first_cipher_col = second_col;
			second_cipher_col = first_col;
		}

		const char first_cipher_char = ptable->table[first_cipher_row][first_cipher_col];
		const char second_cipher_char = ptable->table[second_cipher_row][second_cipher_col];

		return std::make_pair(first_cipher_char, second_cipher_char);
	}

	pair<size_t, size_t> playfair_table::get_index(char ch) {
		for(size_t row=0; row<common_degree; row++) {
			for(size_t col=0; col<common_degree; col++) {
				if(table[row][col] == ch)
					return std::make_pair(row, col);
			}
		}

		// work around for an alphabet that would not
		// be present in the table
		static const size_t missing_alph_row = common_degree - 1;
		static const size_t missing_alph_col = common_degree - 1;
		if(isupper(ch))
			return std::make_pair(missing_alph_row, missing_alph_col);

		// control should not reach here if the entry is valid
		throw std::invalid_argument{"character not in table"};
	}

	pair<char, char> playfair_table::operator[] (pair<char, char> pt_pair) {
		const auto [first_ch, second_ch] = pt_pair;
		auto first_index = get_index(first_ch);
		auto second_index = get_index(second_ch);

		return get_cipher_pair(this, first_index, second_index);
	}

	string encrypt(string plain_text, string key) {
		normalize(plain_text);

		static const auto degree = playfair_table::common_degree;
		normalize(key, degree*degree);

		playfair_table ptable { key };
		vector< pair<char, char> > ct_pairs;

		auto pt_pairs = get_plain_text_pairs(plain_text);

		for(auto pt_pair : pt_pairs)
			ct_pairs.push_back(ptable[pt_pair]);

		return cipher_text(ct_pairs);
	}
}
