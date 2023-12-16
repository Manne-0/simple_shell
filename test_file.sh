#!/bin/bash

# Test Case 1: Check if the shell executes a basic command
shell_input="echo Hello, World!"
echo "Running: $shell_input"
echo "$shell_input" | ./hsh

# Test Case 2: Check another command
shell_input="ls -l"
echo "Running: $shell_input"
echo "$shell_input" | ./hsh

# Add more test cases as needed

