CC=g++
FLAGS=-Wall -lwiringPi -std=c++0x


all: main

main: main.o Music.o NoMusic.o Pin.o
	$(CC) $(FLAGS) -o main main.o Music.o NoMusic.o Pin.o

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

Music.o: Music.cpp Music.h
	$(CC) $(FLAGS) -c Music.cpp

NoMusic.o: NoMusic.cpp NoMusic.h
	$(CC) $(FLAGS) -c NoMusic.cpp

Pin.o: Pin.cpp Pin.h
	$(CC) $(FLAGS) -c Pin.cpp

clean:
	rm *.o main

cleansourcedir:
	rm *.o
	mv main compiled/
