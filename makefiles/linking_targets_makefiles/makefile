# example makefile
# here the makefiles will only compile
# if any of the object files change - then
# they will be compiled


# this is the main output
build: main.o message.o
	g++ main.o  message.o -o main

# create a target for the main file
main: main.cpp
	g++ -c main.cpp

# manage the message file
# here if any of the dependencies here change 
# then only they are compiled
message: message.o message.h
	g++ -c message.cpp

# running the file
run:
	./main

# clean
clean:
	rm *.o output