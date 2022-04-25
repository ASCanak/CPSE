#ifndef DISPLAY_H
#define DISPLAY_H

#include "hwlib.hpp"
#include "lookup.h"

class clock{
private:
    hwlib::xy centre;

    hwlib::window& OLED;

    hwlib::pin_in& minute_button;
    hwlib::pin_in& hour_button;

    unsigned int hours = 0, minutes = 0, seconds = 0;
    unsigned int time_check = 0;

public: 
    clock(const hwlib::xy centre, hwlib::window& OLED, hwlib::pin_in& minute_button, hwlib::pin_in& hour_button):
        centre(centre),
        OLED(OLED),
        minute_button(minute_button), hour_button(hour_button)
    {}

    void start(const auto& sines, const auto& cosines){
        for(;;)
            update(sines, cosines);
    }

    void update(const auto& sines, const auto& cosines)
    {
        if( time_check + 1'000'000 < hwlib::now_us() )
        {            
            time_check = hwlib::now_us();

            if(!hour_button.read()){
                if(hours == 11)
                    hours = 0;
                else 
                    hours++;
            }

            if(!minute_button.read()){
                if(minutes == 59){
                    minutes = 0;
                    hours++;
                }
                else 
                    minutes++;
            }

            if(seconds == 59){
                seconds = 0;

                if(minutes == 59){
                    minutes = 0;
                    
                    if(hours == 11)
                        hours = 0;
                    else 
                        hours++;
                }
                else 
                    minutes++;
            }
            else
                seconds++;

            draw(sines, cosines);
        }
    }

    void draw(const auto& sines, const auto& cosines){
        OLED.clear();
            for( int i = 0; i < 360; i += 30 )
                hwlib::circle( hwlib::xy( sines.get( i ), cosines.get( i ) ), 2 ).draw(OLED);
            hwlib::circle(hwlib::xy(centre), 3).draw(OLED);

            hwlib::line( centre, hwlib::xy( sines.get( seconds * 6 ),  cosines.get( seconds * 6 ))).draw(OLED);
            hwlib::line( centre, hwlib::xy( sines.get( minutes * 6 ),  cosines.get( minutes * 6 ))).draw(OLED);
            hwlib::line( centre, hwlib::xy( sines.get( hours   * 30 ), cosines.get( hours   * 30 ))).draw(OLED);
        OLED.flush();
    }
};

#endif