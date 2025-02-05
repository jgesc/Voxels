SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := $(shell find $(SRC_DIR) -name *.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
OBJ_DIRS := $(dir $(OBJ_FILES))
DUMMY:=$(shell mkdir --parents $(OBJ_DIRS))
# -pthread, -lunwind and -lbfb are used only for debugging purposes
# TODO: differentiate debugging and release includes
INCLUDES := -pthread -lglfw -ldl -lunwind -lbfd


main: $(OBJ_FILES)
	g++ -O3 -g3 -std=c++17 -o bin/main $^ $(INCLUDES)

resources:
	rm -rf bin/Resources
	cp -r src/Resources bin/Resources

clean:
	-rm -rf bin/*
	-rm -rf obj/*

all:
	make clean
	make main
	make resources



$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -O3 -g3 -include "src/Debugging/Logger.hpp" -std=c++17 -c -o $@ -MMD $<

-include $(shell find $(OBJ_DIR) -name *.d)
