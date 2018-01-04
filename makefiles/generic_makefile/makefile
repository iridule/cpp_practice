#=================================================
#   GENERIC MAKEFILE
#=================================================

#  target
TARGET = main

# compiler
CC = g++ -std=c++11

# directories
OBJDIR = obj
SRCDIR = src
BINDIR = bin

# sources
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# flags
IFLAGS = -Isrc
LDFLAGS =

#=================================================
#   MAIN BUILD - DO NOT EDIT BELOW!
#=================================================

# main target build
$(TARGET): $(OBJECTS)
	@echo "Linking the objects..."
	@echo "Linking $^"
	$(CC) $^ -o $(BINDIR)/$(TARGET)

# compile objects
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	@echo "Compiling $<"
	$(CC) -c $(IFLAGS) $< -o $@ $(LDFLAGS)	

run:
	$(BINDIR)/$(TARGET)

clean:
	rm -rf $(OBJDIR)/*.o