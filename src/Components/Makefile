CC = g++
CPPFLAGS = -Wall -g -lsfml-graphics -lsfml-window -lsfml-system

# Library name
LIBRARY = libComponents.a

# Source files
SRC = CShape.cc Vec2.cc

# Object files (replace .c with .o)
OBJ = $(SRC:.cc=.o)

# Default target: create the static library
all: $(LIBRARY)

# Rule to create the static library
$(LIBRARY): $(OBJ)
	ar rcs $@ $^

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f $(OBJ) $(LIBRARY)

.PHONY: all clean




