# Compiler name
CC = gcc

# Compilation flags (warnings and debug info)
CFLAGS = -Wall -Wextra -g

# Source and object files
SRC = euclides.c
OBJ = euclides.o

# Name of the final executable
TARGET = im_the_exec

# By defect rule
all: $(TARGET)

# How to compile the object
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

# How to build the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Clean the intermediate objects
clean:
	rm -f $(OBJ) $(TARGET)
