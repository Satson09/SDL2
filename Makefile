# Specify compiler
CC = gcc

# Source and header directories
SRC_DIR = src
INC_DIR = inc

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Executable name
NAME = maze

# Compiler flags
CFLAGS = -O2 -g -Wall -Werror -Wextra -pedantic -I$(INC_DIR)

# Linker flags
LFLAGS = -lSDL2 -lSDL2_image -lm

# SDL flags
SDLFLAGS = `sdl2-config --cflags --libs`

# Compiles executable
all: $(SRC_FILES)
	$(CC) $(SRC_FILES) $(CFLAGS) $(LFLAGS) -o $(NAME) $(SDLFLAGS)

# Remove temporary files and executable
clean:
	rm -f *~ $(NAME)

.PHONY: all clean

