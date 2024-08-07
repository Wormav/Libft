#!/bin/bash

# Compile the project using Makefile
make

# Compile the test file with the library and execute the test
cc -Wall -Wextra -Werror tests_libft.c libft.a -g -o tests_libft && ./tests_libft

# Clean the project using Makefile
make fclean

# Remove the test executable
rm tests_libft