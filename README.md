UNDERSTANDING THE MAKEFILE

General structure of a rule:

target: dependencies
<TAB> recipe/command

target: is the file that you want to build (file1, file1.o, etc.)
dependencies: the files required to build the target (like .c, .h, .o)
recipe: the commands that are executed to create the target (THE MUST START WITH TAB)

-----------------------------------------
EXAMPLE

# Line 1: we choose the compiler
CC = gcc

This defines a variable CC (usually for "C Compiler") equals to "gcc". You can change it to clang if you use another compiler.

# Line 2: Compilation flag
CFLAGS = -Wall -Wextra -g

-Wall: enable common warnings
-Wextra: enable additional warnings
-g: includes depuration symbols to use with gdb

# Line 3 - 5: We define our files
SRC = euclides.c
OBJ = euclides.o
TARGET = im_the_exec

SRC = source file
OBJ = object file that the intermediate compilation generates
TARGET = name of the executable

# Line 7: Principal Rule
all: $(TARGET)

all is the default target that is executed if you simply do "make"
it says to build "all", first I need "im_the_exec"

# Line 9-10: How to generate the .o
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

This rule says:
- if euclides.c change or euclides.o doesn't exists,
- compile it with gcc -c, that generates the .o without linking.
- the -c means "just compile, do not create the executable yet"

# Line 12-13: How to generate the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

if main doesn't exists but I have euclides.o, link it and create the executable

# Line 15-17: Rule to clean
clean:
	rm -f $(OBJ) $(TARGET)

This defines the make clean command, that deletes the generated files.
-f makes that rm doesn't fail if the files doens't exist.

---------------------------------
ADDITIONAL INFO

You can define variables like

NAME = value

and use $(NAME)
Example: $(CC) or $(CFLAGS)

