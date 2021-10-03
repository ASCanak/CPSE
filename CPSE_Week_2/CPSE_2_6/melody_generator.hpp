#ifndef MELODY_GENERATOR_HPP
#define MELODY_GENERATOR_HPP

#include "note_player.hpp"
#include <fstream>

std::ofstream melody_cpp;

class melody_generator : public note_player {
public:
    void open(){
        melody_cpp.open("melody.cpp");
        melody_cpp << "#include \"melody.hpp\" \n\n"
                   << "void melody::play( note_player & p ){ \n";
    }

    void play( const note &n )override{ 
        melody_cpp << "\tp.play( note{ " << n.frequency << ", " << n.duration << " } ); \n";
    }

    void close(){
        melody_cpp << "}"; 
        melody_cpp.close();
    }
};

#endif 