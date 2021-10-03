#include "melody.hpp" 

void melody::play( note_player & p ){ 
	p.play( note{ 880, 1000000 } ); 
	p.play( note{ 0, 1000000 } ); 
	p.play( note{ 880, 1000000 } ); 
	p.play( note{ 0, 1000000 } ); 
	p.play( note{ 880, 1000000 } ); 
	p.play( note{ 0, 1000000 } ); 
	p.play( note{ 880, 2000000 } ); 
	p.play( note{ 0, 1000000 } ); 
	p.play( note{ 880, 2000000 } ); 
	p.play( note{ 0, 1000000 } ); 
	p.play( note{ 880, 2000000 } ); 
	p.play( note{ 0, 1000000 } ); 
	p.play( note{ 880, 1000000 } ); 
	p.play( note{ 0, 1000000 } ); 
	p.play( note{ 880, 1000000 } ); 
	p.play( note{ 0, 1000000 } ); 
	p.play( note{ 880, 1000000 } ); 
}