#include "hwlib.hpp"

extern "C" char toggle_case( char c ){
   if(c >= 'A' && c <= 'Z')
      c += 32;
   else if(c >= 'a' && c <= 'z')
      c -= 32;
   return c;
}

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void print_asciz( const char * s );

extern "C" void application();	

int main( void ){	
   namespace target = hwlib::target;   
    
   // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}