#include "hwlib.hpp"
#include "headers/lookup.h"
#include "headers/display.h"

int main(){
    constexpr auto sines   = lookup< 360, int >( scaled_sine_from_degrees );
    constexpr auto cosines = lookup< 360, int >( scaled_cosine_from_degrees ); 
    
    namespace target = hwlib::target;

    auto scl = target::pin_oc(target::pins::scl);
    auto sda = target::pin_oc(target::pins::sda);
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
    auto OLED = hwlib::glcd_oled( i2c_bus, 0x3c );

    auto black_Switch = hwlib::target::pin_in( hwlib::target::pins::d22 );
    auto white_Switch = hwlib::target::pin_in( hwlib::target::pins::d23 );

    clock c( hwlib::xy( 128/2, 64/2 ), OLED, black_Switch, white_Switch );
    c.start(sines, cosines);
    
    return 0;
}