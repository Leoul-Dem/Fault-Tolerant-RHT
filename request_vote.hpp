#pragma once

#include <cstdint>

// Election / vote logic lives here; wire types are `RequestVoteRequest` / `RequestVoteReply`
// in `raft_rpc.hpp` (send/serialize those from your networking layer).

class Voter {
public:
    void election_timeout();
    bool start_election();
};
