#include <cstdint>
#include <iostream>

#include "record.h"
#include "escaped.h"

using namespace util;

template <typename K, typename V>
void output(K key, V value)
{
    std::cout << escaped_text(key) << ": "
          << escaped_text(value) << '\n';
}

int main(int argc, char **argv)
{
    static uint64_t first_id{1000};
    for (int idx = 1; idx != argc; ++idx)
    {
        Record r{++first_id, argv[idx]};
        output(idx, r);
    }
}
