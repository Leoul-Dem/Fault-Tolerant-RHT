#include "./libs/net/networking.hpp"
#include "./libs/utils.hpp"
#include "./log.hpp"
#include "./request_vote.hpp"
#include <optional>

class Node{
    bool is_leader;
    
    Connection conn;
    
    Voter voter;
    
    Log log;
    
    
    void recieve_heart_beat();
    
    void send_heart_beat(); 
    
public:
    Node(const int argc, const char** argv);
    
    std::optional<str> get(int key);
    
    bool put(KVPair input);
    
    bool put3(KVPair input, KVPair input2, KVPair input3);    
    
    void run();
};