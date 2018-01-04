
# 
build: main.o parent.o child.o
	g++ -std=c++11 main.o parent.o child.o -o main

#
main.o: main.cpp
	g++ -std=c++11 main.cpp -c 

# 
parent.o: parent.cpp
	g++ -std=c++11 -c parent.cpp

#
child.o: child.cpp
	g++ -std=c++11 -c child.cpp

#
clean:
	rm ./*o

#
run:
	./main