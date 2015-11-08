## pilitez
Turn your Raspberry Pi into a 8-channel lighting console/colour organ with an additional selfmade circuit.

On almost every major party these systems accompany the music with their light. This version uses a Raspberry Pi and an additional circuit that has to be build up either with LED's or with light bulbs in a bigger circuit.


To start it simply run "sudo python starter.py" from the "compiled" folder.
( Make sure main and allof are in the same folder. )

  
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
  

If you have done changes in the files run:
  make
  
The Wiring Pi library is required to compile PiLitez: wiringpi.com/


!!!

Please note that the binary files in the "compiled/" folder are examples and often not up to date.
If you've downloaded the repo, go to the source folder and compile it with the command above.

!!!

Contact:
  E-Mail: stadtmuellertim@gmail.com
