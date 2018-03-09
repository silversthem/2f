# Compiling options
CXX := g++
CXXFLAGS := -Wall -g -O2 -std=c++14 -std=c++11 -Wall
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system
# Directories
SOURCES := src
OBJECTS := obj
# Separation (transforming / into DIR_SEPARATOR in file path to keep all object files in the same directory)
DIR_SEPARATOR := __
# Files
SRC := $(shell find $(SOURCES)/ -type f -name '*.cpp')
OBJ := $(patsubst %.cpp,$(OBJECTS)/%.o, $(subst /,$(DIR_SEPARATOR),$(SRC)))
INC := -Iinclude

LIBNAME := lib2f.a

all: $(OBJ)
	ar rvs $(LIBNAME) $(OBJ)

$(OBJECTS)/%.o:
	$(CXX) -c $(INC) -o $@ $(patsubst $(OBJECTS)/%.o,%.cpp,$(subst $(DIR_SEPARATOR),/,$@)) $(CXXFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJECTS)/*.o
	rm -rf $(LIBNAME)
