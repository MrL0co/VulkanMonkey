STB_INCLUDE_PATH = /home/rjacobse/projects/personal/stb
TINY_OBJ_LOADER_INCLUDE_PATH = /home/rjacobse/projects/personal/tinyobjloader

CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -O3

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

INCLUDES	:= -I$(STB_INCLUDE_PATH) -I$(TINY_OBJ_LOADER_INCLUDE_PATH)
LIBRARIES	:= `pkg-config --static --libs glfw3` -lvulkan
EXECUTABLE	:= main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $(INCLUDES) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
