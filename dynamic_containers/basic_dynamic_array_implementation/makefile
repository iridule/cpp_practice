### a more advanced makefile
#\
	objectives for future\
		-	go through gnu make manual\
		-	implement a tree structure for the directories
#\

# 
build: main.o
	g++ -std=c++11 main.o -o main
	
# to target the specific file we need to produce - use .o as the target name
main.o: vector.hpp main.cpp
	g++ -std=c++11 -c main.cpp

#
clean:
	rm ./*.o

# 
run:	
	./main