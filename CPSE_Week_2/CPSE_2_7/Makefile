#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)
HEADERS := fur_elise.hpp melody.hpp note.hpp note_player.hpp note_player_gpio.hpp note_player_terminal.hpp rtttl_player.hpp melody_generator.hpp
SOURCES := note_player_gpio.cpp rtttl_player.cpp melody.cpp

melody.cpp : generator.cpp
	make -f maakfile melody.cpp

# other places to look for files for this project
SEARCH  := 

SERIAL_PORT := /dev/ttyACM0
# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := ../$(RELATIVE)../
include $(RELATIVE)Makefile.due