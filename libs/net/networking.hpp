#pragma once

#include <array>
#include <atomic>
#include <cstdint>
#include <memory>
#include <mutex>
#include <vector>

#include "./asio/include/asio.hpp"
#include "../../raft_rpc.hpp"

class Connection {
public:
    static constexpr int CONNS_PER_PEER = 4;

    Connection() = default;

    std::vector<asio::ip::tcp::endpoint> all_nodes;

    std::vector<std::array<std::unique_ptr<asio::ip::tcp::socket>, CONNS_PER_PEER>> conns;
    std::vector<std::array<std::mutex, CONNS_PER_PEER>> conn_mtx;
    std::vector<std::atomic<uint32_t>> conn_rr;

    int PORT{};

    asio::io_context io_ctx;

    std::unique_ptr<asio::ip::tcp::acceptor> acceptor;

    node_idx NUM_NODES{};
    node_idx my_idx{};
    node_idx cluster_leader{};
    node_idx global_leader{};

    void parse_node_addrs(int argc, const char** argv);
    void establish_conns(int my_idx);
    void create_server(int port);

    void broadcast_cluster(RpcKind kind);
    void recv_cluster(RpcKind& kind);

    void send_cluster_leader();
    void recv_cluster_leader();
};
