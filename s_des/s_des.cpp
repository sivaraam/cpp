#include <vector>
#include <tuple>
#include <climits>
#include "s_des.hpp"
using std::pair;
using std::vector;

// Indexing behaviour:
// b : 100010
// b[0] : 0
//
// b_str = b.to_string()
// b_str[0] : 1
namespace s_des {

    const size_t half_key_size = key_size/2;
    const size_t half_pt_size = pt_size/2;

    typedef bitset<half_pt_size> half_pt_type;
    typedef bitset<half_key_size> half_key_type;
    typedef bitset<pt_size> sub_key_type;

    // The sub keys used for encryption
    //
    // Note: Do not modify the sub key without purpose.
    sub_key_type sub_key1, sub_key2;

    template <size_t N>
    inline bitset<N> rol(bitset<N> val) {
        return (val << 1) | (val >> (N-1));
    }

    inline static auto
    get_half_keys(key_type key) {
        return std::make_pair(half_key_type(permuted_key_string, 0, key_size/2),
                              half_key_type(permuted_key_string, key_size/2));

    }

    // Generates the subkeys and stores it in the global
    // variables sub_key1 and sub_key2.
   void generate_subkey(key_type key) {
	const key_type zero(0);

        static const vector<size_t> key_permutation { 2, 4, 1, 6, 3, 9, 0, 8, 7, 5 };
        key_type permuted_key;

        // Initially permute the key
        for (size_t i=0; i<key_size; i++)
              permuted_key[i] = key[key_permutation[i]];

        const auto permuted_key_string = permuted_key.to_string();
        auto [key_left_half, key_right_half] = get_half_keys(permuted_key);
	key_left_half = rol<half_key_size>(key_left_half);
        key_right_half = rol<half_key_size>(key_right_half);

    }

    /* The main function that performs the "core" computation
    static auto round_function(pt_left_half lh_bits, pt_right_half rh_bits) {

    }
    */

    ct_type encrypt(pt_type pt_bits, key_type key) {

    }

}
