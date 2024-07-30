## pilitez
Raspberry Pi based 8-channel direct parallel lighting console/colour organ for additional circuit.


To start run "sudo python starter.py" from the "compiled" folder.

  
The software contains functions to switch the pins on or off in certain patterns and orders.

allof:
  Initializes all pins and turns them off.
  
allon:
  Initializes all pins and turns them on.
  
testLamps:
  Initializes all pins and turns them on successively.
  
testLamps.cpp:
  Source file of testLamps
  
NoMusic.h:
  Header file for NoMusic.cpp
  
NoMusic.cpp:
  Source file which contains a class with all the functions regardless of the music
  
Music.h
  Header file for Music.cpp

Music.cpp
  Source file which contains a class with music-driven functions

Pin.h
  Header file for Pin.cpp

Pin.cpp
  Source file which contains a class representing a raspberry pi GPIO-Pin and some basic functions

main.cpp:
  Main programm
  
main:
  Compiled programm
  
  
The Wiring Pi library is required to compile PiLitez: wiringpi.com/
