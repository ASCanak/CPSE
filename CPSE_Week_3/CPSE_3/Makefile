#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := 

# header files in this project
HEADERS := calc.h lookup.h display.h

# other places to look for files for this project
SEARCH  := headers

SERIAL_PORT := /dev/ttyACM0
# set RELATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := ../$(RELATIVE)../
include $(RELATIVE)Makefile.due