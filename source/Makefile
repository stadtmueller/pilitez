CC=g++
FLAGS=-Wall -lwiringPi -std=c++0x


all: main

main: main.o Music.o NoMusic.o Pin.o
	$(CC) $(FLAGS) -o main main.o Music.o NoMusic.o Pin.o

main.o: main.cpp Pin.cpp Music.cpp NoMusic.cpp
	$(CC) $(FLAGS) -c main.cpp Pin.cpp Music.cpp NoMusic.cpp

Music.o: Music.cpp Pin.cpp
	$(CC) $(FLAGS) -c Music.cpp Pin.cpp

NoMusic.o: NoMusic.cpp Pin.cpp
	&(CC) $(FLAGS) -c NoMusic.cpp Pin.cpp

Pin.o: Pin.cpp Pin.h
	$(CC) $(FLAGS) -c Pin.cpp

cleanO:
	rm *.o
