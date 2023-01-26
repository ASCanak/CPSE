#ifndef SET_H
#define SET_H

#include <array>
#include <sstream>
#include <iostream>

class set{
private:
    std::array< int, 10 > collection = {};
    unsigned int index = 0;

public:
    set(){}

    void add( int x ){
        if( index < 10 && !contains( x ) )
            collection[index++] = x;
    }

    void remove( int x ){
        for( unsigned int i = 0; i < index; i++ ){
            if(collection[i] == x){
                for(unsigned int j = i + 1; j < index;){
                    collection[i++] = collection[j++];
                }
                collection[i] = 0;
                index--;
                return;
            }
        }
    }

    bool contains( int x ){
        for( auto item : collection ){
            if( item == x ) 
                return true;
        }
        return false;
    }

    friend std::ostream& operator<<( std::ostream& lhs, const set& rhs ){ 
        std::string delimiter = "[";

        for( auto const item : rhs.collection ){
            lhs << delimiter << item;
            delimiter = ", ";
        }
        lhs << "]\n";
        return lhs;
    }
};

#endif