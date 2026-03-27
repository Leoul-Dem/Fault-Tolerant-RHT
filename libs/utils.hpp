#pragma once

#include <cstdint>
#include <array>

using node_idx = uint8_t;
using log_index_t = uint64_t;

using str = std::array<char, 64>;

struct KVPair {
    int key;
    str val;
};
