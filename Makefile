# Compiling options
CXX := g++
CXXFLAGS := -Wall -g -O2 -std=c++14 -std=c++11 -Wall
LDFLAGS := -L2f -l2f -lsfml-graphics -lsfml-window -lsfml-system
# Directories
SOURCES := game
OBJECTS := obj
# Separation (transforming / into DIR_SEPARATOR in file path to keep all object files in the same directory)
DIR_SEPARATOR := __
# Files
SRC := $(shell find $(SOURCES)/ -type f -name '*.cpp') main.cpp
OBJ := $(patsubst %.cpp,$(OBJECTS)/%.o, $(subst /,$(DIR_SEPARATOR),$(SRC)))
INC := -I2f/include
# Library needed
LIB_FOLDER := 2f
LIB := $(LIB_FOLDER)/lib2f.a
# End product
EXECUTABLE := SpaceWarfare

$(LIB): # Creating library
	@$(MAKE) -C $(LIB_FOLDER) all

all: $(LIB) $(OBJ) # Creating executable from library and .o files
	$(CXX) $(OBJ) -o $(EXECUTABLE) $(CXXFLAGS) $(LDFLAGS)

$(OBJECTS)/%.o: # Compiling .o file from .cpp file
	$(CXX) -c $(INC) -o $@ $(patsubst $(OBJECTS)/%.o,%.cpp,$(subst $(DIR_SEPARATOR),/,$@)) $(CXXFLAGS) $(LDFLAGS)

.PHONY: clean

clean: # Cleaning
	rm -rf $(OBJECTS)/*.o
	@$(MAKE) -C $(LIB_FOLDER) clean
	rm -f $(EXECUTABLE)
