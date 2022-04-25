#ifndef LOOKUP_H
#define LOOKUP_H

#include "calc.h"
#include <array>

template< int N, typename T >

class lookup{
private:
    std::array< T, N > values={};

public: 
    
    template< typename F >

    constexpr lookup( F function )
        {   
        for( int i = 0; i < N; ++i ){
            values[ i ] = function( i );
        }
    }

    constexpr int get( int n ) const {
        return values[ n ];    
    }
};

#endif