#include <cstdint>
#include <array>

using node_idx = uint8_t;
using entry_idx = uint32_t;

enum Message{
    HeartBeat,
    AppendEntry,
    AppendEntryList,
    CommFromLeader,
    CommToLeader,
    CommFromFollower
};

struct HeartBeat{
    
};

struct AppendEntry{
    
};

struct AppendEntryList{
    
};

struct CommFromLeader{

};

struct CommToLeader{
    
};

struct CommFromFollower{
    
};

struct LeaderComm{
    
};

using str = std::array<char, 64>;

struct KVPair{
    int key;
    str val;
};