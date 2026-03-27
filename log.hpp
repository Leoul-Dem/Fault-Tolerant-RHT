#pragma once

#include <cstdint>
#include <array>
#include <deque>
#include <mutex>
#include <optional>
#include <vector>

#include "./libs/utils.hpp"

enum class Operation : uint8_t {
    GET,
    PUT,
    PUT3,
};

// One Raft log entry: replicated state-machine command at `index` with Raft `term`.
struct Entry {
    log_index_t index;
    uint16_t term;
    Operation op;
    std::array<KVPair, 3> data;

    Entry(log_index_t index, uint16_t term, Operation op, std::array<KVPair, 3> data)
        : index(index), term(term), op(op), data(data) {}
};

class Log {
    std::deque<Entry> logs;
    std::mutex log_mtx;

public:
    Log() = default;

    std::optional<Entry> get_log(log_index_t entry_idx);
    std::optional<Entry> get_last_log();
    std::optional<std::vector<Entry>> get_logs_from(log_index_t entry_idx);

    void append_log(Entry entry);
    bool delete_logs_from(log_index_t entry_idx);

    void print_logs();
};
