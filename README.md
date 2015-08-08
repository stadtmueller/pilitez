# pilitez
Turn your Raspberry Pi into a 8-channel lighting console/colour organ with an additional selfmade circuit.

On almost every major party these systems accompany the music with their light. This version uses a Raspberry Pi and an additional circuit that has to be build up either with LED's or with light bulbs in a bigger circuit.

The required software contains functions to switch the pins on or off in certain patterns and orders.

allof
  Initializes all pins and turns them off.
  
allon
  Initializes all pins and turns them on.
  
testLamps
  Initializes all pins and turns them on successively.
  
testLamps.cpp
  Source file of testLamps
  
functions.h
  Header file for functions.cpp
  
functions.cpp
  Source file which contains all the functions
  
main.cpp
  Main programm
  
main
  Compiled programm
  

If you have done changes in the files run
  g++ -Wall -o main main.cpp functions.cpp -lwiringPi -std=c++0x
  
The Wiring Pi library is required: wiringpi.com/
