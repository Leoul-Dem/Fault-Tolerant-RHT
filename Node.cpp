#include "./Node.hpp"

Node::Node(int argc, char** argv) {
    (void)argc;
    (void)argv;
}

void Node::receive_append_entries() {}

void Node::send_append_entries() {}

void Node::apply_log() {}

std::optional<str> Node::get(int key) {
    (void)key;
    return std::nullopt;
}

bool Node::put(KVPair input) {
    (void)input;
    return false;
}

bool Node::put3(KVPair input1, KVPair input2, KVPair input3) {
    (void)input1;
    (void)input2;
    (void)input3;
    return false;
}

void Node::run() {}
