#pragma once

#include <cstdint>
#include <vector>

#include "./libs/utils.hpp"
#include "./log.hpp"

// Discriminator for on-the-wire messages (you will serialize the matching struct next).
enum class RpcKind : uint8_t {
    RequestVote,
    RequestVoteReply,
    AppendEntries,
    AppendEntriesReply,
    // Optional hooks for multi-cluster / client routing (fill in as you go):
    CommFromLeader,
    CommToLeader,
    CommFromFollower,
};

struct RequestVoteRequest {
    uint16_t term{};
    node_idx candidate_id{};
    uint64_t last_log_index{};
    uint64_t last_log_term{};
};

struct RequestVoteReply {
    uint16_t term{};
    bool vote_granted{};
};

// Heartbeats are AppendEntries with `entries` empty.
struct AppendEntriesRequest {
    uint16_t term{};
    node_idx leader_id{};
    uint64_t prev_log_index{};
    uint64_t prev_log_term{};
    uint64_t leader_commit{};
    std::vector<Entry> entries;
};

struct AppendEntriesReply {
    uint16_t term{};
    bool success{};
};
