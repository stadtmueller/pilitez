CXX=g++
FLAGS=-Wall -std=c++0x
LDFLAGS=-lwiringPi

all: main

main: main.o Music.o NoMusic.o Pin.o
	$(CXX) $(FLAGS) $(LDFLAGS) -o main main.o Music.o NoMusic.o Pin.o

main.o: main.cpp
	$(CXX) $(FLAGS) -c main.cpp

Music.o: Music.cpp Music.h
	$(CXX) $(FLAGS) -c Music.cpp

NoMusic.o: NoMusic.cpp NoMusic.h
	$(CXX) $(FLAGS) -c NoMusic.cpp

Pin.o: Pin.cpp Pin.h
	$(CXX) $(FLAGS) -c Pin.cpp

clean:
	rm -f *.o main

cleansourcedir:
	rm -f *.o
	mv main compiled/
