#include <vector>
#include <mutex>
#include <cstdint>

#include "./asio/include/asio.hpp"
#include "../utils.hpp"

class Connection {
    static constexpr int CONNS_PER_PEER = 4;
    
    std::vector<asio::ip::tcp::endpoint> all_nodes;
    
    std::vector<std::array<std::unique_ptr<asio::ip::tcp::socket>, CONNS_PER_PEER>> conns;
    std::vector<std::array<std::mutex, CONNS_PER_PEER>> conn_mtx;
    std::vector<std::atomic<uint32_t>> conn_rr;

    int PORT;

    asio::io_context io_ctx;

    std::unique_ptr<asio::ip::tcp::acceptor> acceptor;
    
    node_idx NUM_NODES;

    node_idx my_idx;  
    node_idx cluster_leader;
    node_idx global_leader;
    
    void parse_node_addrs(const int argc, const char** argv);
    void establish_conns(int myIdx);
    void create_server(const int port);
    
    void broadcast_cluster(Message &msg);
    void recv_cluster(Message &msg);
    
    void send_cluster_leader();
    void recv_cluster_leader();
    
    
};