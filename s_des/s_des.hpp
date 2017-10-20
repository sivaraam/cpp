#include <bitset>
using std::bitset;

namespace s_des {

    static const size_t key_size = 10, pt_size = 8;
    typedef bitset<key_size> key_type;
    typedef bitset<pt_size> pt_type;
    typedef pt_type ct_type;

    ct_type encrypt(pt_type, key_type);

    void generate_subkey(key_type key);
}
