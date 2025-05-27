SRC_DIR = src
BUILD_DIR = testBuild/debug
CC = gcc
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_NAME = game
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -L/opt/homebrew/Cellar/sdl2/2.30.12/lib/ -L/opt/homebrew/Cellar/sdl2_image/2.8.4/lib/
COMPILER_FLAGS = -Wall -std=c99
LINKER_FLAGS = -lsdl2

build:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)

run:
	./testBuild/debug/game

clean:
	rm testBuild/debug/game