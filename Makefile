SRC_DIR = src
BUILD_DIR = testBuild/debug
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = editor
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -L/opt/homebrew/Cellar/sdl2/2.30.12/lib/ -L/opt/homebrew/Cellar/sdl2_image/2.8.4/lib/
COMPILER_FLAGS = -Wall
LINKER_FLAGS = -lsdl2

build:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)

run:
	./testBuild/debug/editor

clean:
	rm testBuild/debug/editor