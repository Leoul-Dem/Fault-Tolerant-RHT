#include "./log.hpp"
#include <optional>

std::optional<Entry> Log::get_log(uint64_t entry_idx){
    return std::nullopt;
}

std::optional<Entry> Log::get_last_log(){
    return std::nullopt;
}
std::optional<std::vector<Entry>> Log::get_logs_from(uint64_t entry_idx){
    return std::nullopt;
}

void Log::append_log(uint64_t entry_idx, uint16_t term, Operation op, std::array<KVPair, 3> data){
    return;
}

void Log::append_log(Entry entry){
    return;
}

bool Log::delete_logs_from(uint64_t entry_idx){
    return false;
}

void Log::print_logs(){
    return;
}

