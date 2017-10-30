# this is a basic makefile
# the following runs the command "build"

# command can be set to a variable
# here we are defining search paths 
# and also pointing to the helper

# src folder
HELPER_FILES=include/helpers.cpp

# include paths command
INCLUDE_PATHS=-I include

# lib folder
LIB_PATHS=-I libs

# define const command
# we are using linux :] 
DEFINE=-D_linux_

# build command
# std command -> compile our main file and ref the libs - also it checks
# for a define pre-processor directive to conclude it works
build:
	g++ -o main src/main.cpp $(HELPER_FILES) $(INCLUDE_PATHS) $(DEFINE) libs/helpers.so $(LIB_PATHS) 

buildso:
	g++ -o main src/main.cpp $(INCLUDE_PATHS) $(DEFINE) -L. -lhelpers.so 

# make libs
sos:
	g++ -fPIC -shared ./include/helpers.cpp ./include/helpers2.cpp $(INCLUDE_PATHS) $(DEFINE) -o helpers.so
	mv helpers.so src
	
# run
run: 
	./main

# clean command
clean:
	rm main
