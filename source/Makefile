CC=g++
FLAGS=-Wall -lwiringPi -std=c++0x


all: main

main: main.o Music.o NoMusic.o Pin.o
	$(CC) $(FLAGS) -o main main.o Music.o NoMusic.o Pin.o

main.o: main.cpp Music.o NoMusic.o Pin.o
	$(CC) $(FLAGS) main.cpp

Music.o: Music.cpp Pin.o
	$(CC) $(FLAGS) Music.cpp

NoMusic.o: NoMusic.cpp Pin.o
	&(CC) $(FLAGS) NoMusic.cpp

Pin.o: Pin.cpp
	$(CC) $(FLAGS) Pin.cpp

clean:
	rm -rf *o main
