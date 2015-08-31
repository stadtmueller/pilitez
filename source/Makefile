CC=g++
FLAGS=-Wall -lwiringPi -std=c++0x


all: main

main: main.o Music.o NoMusic.o Pin.o
	$(CC) main.o Music.o NoMusic.o Pin.o -o main

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

Music.o: Music.cpp
	$(CC) $(FLAGS) Music.cpp

NoMusic.o: NoMusic.cpp
	$(CC) $(FLAGS) NoMusic.cpp

Pin.o: Pin.cpp
	$(CC) $(FLAGS) Pin.cpp

clean:
	rm -rf *o main
