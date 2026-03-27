#include <cstdint>
#include <array>
#include <deque>
#include <mutex>
#include <optional>
#include <vector>

#include "./libs/utils.hpp"


enum Operation{
    GET,
    PUT,
    PUT3
}; 

struct Entry{
    uint64_t entry_idx;
    uint16_t term;
    Operation op;
    std::array<KVPair, 3> data;
    
    Entry(uint64_t entry_idx, uint16_t term, 
          Operation op, std::array<KVPair, 3> data): 
        entry_idx(entry_idx), 
        term(term), 
        op(op), 
        data(data)
    {}     
};

class Log{
    std::deque<Entry> logs;
    std::mutex log_mtx;

public:
    Log();
    
    std::optional<Entry> get_log(uint64_t entry_idx);
    std::optional<Entry> get_last_log();
    std::optional<std::vector<Entry>> get_logs_from(uint64_t entry_idx);
    
    void append_log(uint64_t entry_idx, uint16_t term, Operation op, std::array<KVPair, 3> data);
    void append_log(Entry entry);
    
    bool delete_logs_from(uint64_t entry_idx);

    void print_logs();
};