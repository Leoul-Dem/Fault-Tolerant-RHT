#pragma once

#include <cstdint>
#include <optional>
#include <vector>

#include "./libs/net/networking.hpp"
#include "./libs/utils.hpp"
#include "./log.hpp"
#include "./raft_rpc.hpp"
#include "./request_vote.hpp"

class Node {
public:
    enum class Role : uint8_t {
        Follower,
        Candidate,
        Leader,
    };

private:
    Role role{Role::Follower};
    uint16_t current_term{0};
    std::optional<node_idx> voted_for{};

    uint64_t commit_index{0};
    uint64_t last_applied{0};

    // Leader only: resize to (peers in this Raft group) when you parse membership.
    std::vector<log_index_t> next_index;
    std::vector<log_index_t> match_index;

    Connection conn;
    Voter voter;
    Log log;

    // Heartbeats are AppendEntries with no new entries (see `AppendEntriesRequest` in `raft_rpc.hpp`).
    void receive_append_entries();
    void send_append_entries();

    void apply_log();

public:
    explicit Node(int argc, char** argv);

    std::optional<str> get(int key);
    bool put(KVPair input);
    bool put3(KVPair input1, KVPair input2, KVPair input3);

    void run();
};
