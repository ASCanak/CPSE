#include "melody.hpp" 

void melody::play( note_player & p ){ 
	p.play( note{ 1318, 150000 } ); 
	p.play( note{ 1174, 300000 } ); 
	p.play( note{ 1046, 600000 } ); 
	p.play( note{ 1318, 150000 } ); 
	p.play( note{ 1568, 300000 } ); 
	p.play( note{ 1760, 300000 } ); 
	p.play( note{ 1568, 300000 } ); 
	p.play( note{ 1568, 150000 } ); 
	p.play( note{ 1568, 300000 } ); 
	p.play( note{ 1318, 300000 } ); 
	p.play( note{ 1174, 150000 } ); 
	p.play( note{ 1046, 300000 } ); 
	p.play( note{ 880, 150000 } ); 
	p.play( note{ 784, 300000 } ); 
	p.play( note{ 1318, 600000 } ); 
	p.play( note{ 0, 600000 } ); 
	p.play( note{ 1318, 300000 } ); 
	p.play( note{ 1318, 150000 } ); 
	p.play( note{ 1396, 300000 } ); 
	p.play( note{ 1318, 300000 } ); 
	p.play( note{ 1318, 300000 } ); 
	p.play( note{ 1174, 300000 } ); 
	p.play( note{ 0, 150000 } ); 
	p.play( note{ 1318, 150000 } ); 
	p.play( note{ 1174, 150000 } ); 
	p.play( note{ 1174, 300000 } ); 
	p.play( note{ 1046, 1200000 } ); 
}