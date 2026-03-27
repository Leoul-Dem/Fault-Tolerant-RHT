

#include <cstdint>

class Voter{
    struct vote_request{
        uint8_t candidate_idx;
        uint16_t term;
        uint64_t last_log_index;
        uint64_t last_log_term;
        
        void request_vote();
        void recieve_vote();        
    };
    
    struct vote_respose{
        uint8_t voter_idx;
        uint16_t term;
        bool vote_granted; 
        
        void send_vote();
    };
    
    void election_timeout();
    
public:
    bool start_election();
    
};
