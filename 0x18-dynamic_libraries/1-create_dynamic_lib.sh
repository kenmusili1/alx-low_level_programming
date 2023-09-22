#!/bin/bash

# Compile all .c files into object files
gcc -Wall -Werror -Wextra -pedantic -fPIC -c *.c

# Create the dynamic library liball.so
gcc -shared -o liball.so *.o

# Clean up the object files
rm -f *.o
