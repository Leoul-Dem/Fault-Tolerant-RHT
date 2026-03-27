#include "./networking.hpp"

void Connection::parse_node_addrs(int argc, const char** argv) {
    (void)argc;
    (void)argv;
}

void Connection::establish_conns(int my_idx) {
    (void)my_idx;
}

void Connection::create_server(int port) {
    (void)port;
}

void Connection::broadcast_cluster(RpcKind kind) {
    (void)kind;
}

void Connection::recv_cluster(RpcKind& kind) {
    kind = RpcKind::RequestVote;
}

void Connection::send_cluster_leader() {}

void Connection::recv_cluster_leader() {}
