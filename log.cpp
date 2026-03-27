#include "./log.hpp"

#include <optional>

std::optional<Entry> Log::get_log(log_index_t entry_idx) {
    return std::nullopt;
}

std::optional<Entry> Log::get_last_log() {
    return std::nullopt;
}

std::optional<std::vector<Entry>> Log::get_logs_from(log_index_t entry_idx) {
    return std::nullopt;
}

void Log::append_log(Entry entry) {
    (void)entry;
}

bool Log::delete_logs_from(log_index_t entry_idx) {
    (void)entry_idx;
    return false;
}

void Log::print_logs() {}
