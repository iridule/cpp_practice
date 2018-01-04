
#
build: main.o vector.o
	g++ -std=c++11 main.o vector.o -o main

#
main.o: main.cpp
	g++ -std=c++11 -c main.cpp

#
vector.o: vector.cpp vector.h
	g++ -std=c++11 -c vector.cpp

#
run:
	./main

