#ifndef SET_H
#define SET_H

#include <array>
#include <sstream>
#include <iostream>

template< typename dataType, int N >
class set{
private:
    std::array< dataType, N > collection = {};
    unsigned int index = 0;

public:
    set(){}

    void add( dataType x ){
        if( index < N && !contains( x ) )
            collection[index++] = x;
    }

    void remove( dataType x ){
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

    bool contains( dataType x ){
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

    dataType max(){
        dataType max = collection[0];
        for(unsigned int i = 1; i < index; i++){
            if(collection[i] > max)
                max = collection[i];
        }
        return max;
    }
};

#endif