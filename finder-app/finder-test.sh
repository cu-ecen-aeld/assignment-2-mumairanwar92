#!/bin/bash

set -e

# Variables
WRITER_SRC="writer.c"
WRITER_EXEC="writer"
WRITEFILE="/tmp/aeld-data/mumairanwar92_assign2.txt"
WRITESTR="Test String"

# Clean any previous build artifacts
echo "Cleaning previous build artifacts..."
make clean

# Compile the writer application using native compilation
echo "Compiling the writer application..."
gcc -o $WRITER_EXEC $WRITER_SRC

# Create the directory for the writefile if it does not exist
mkdir -p $(dirname $WRITEFILE)

# Use the writer utility to write to the file
echo "Running the writer utility..."
./$WRITER_EXEC $WRITEFILE "$WRITESTR"

# Validate that the file was created and contains the correct content
echo "Validating written content..."
if [ ! -f "$WRITEFILE" ]; then
    echo "Error: File '$WRITEFILE' was not created."
    exit 1
fi

READSTR=$(cat "$WRITEFILE")
if [ "$READSTR" != "$WRITESTR" ]; then
    echo "Error: Content of the file '$WRITEFILE' does not match expected content."
    echo "Expected: $WRITESTR"
    echo "Found: $READSTR"
    exit 1
fi

echo "Test successful! File '$WRITEFILE' created with correct content."

exit 0
