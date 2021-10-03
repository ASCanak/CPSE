#ifndef NOTE_PLAYER_TERMINAL_HPP
#define NOTE_PLAYER_TERMINAL_HPP

#include "note_player.hpp"
#include "hwlib.hpp"

class note_player_terminal : public note_player {
public:
    void play( const note &n )override{ 
        hwlib::cout << "Frequency: " << n.frequency << "\t Duration: " << n.duration << '\n';
        hwlib::wait_ms(100);
    }
};

#endif 