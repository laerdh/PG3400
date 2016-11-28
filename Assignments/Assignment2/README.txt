PG3400 - Programming in C
Assignment 2

Date: 24/11-2016
Name: Lars Erling Westbye Dahl


Sources:
- main.c
- merger.c
- merger.h

Use included Makefile to compile the sources.
- make
And clean:
- make clean


Description:
This program merges parts of an ASCII-art to one file.
ASCII-files must have a structure of 30x30 bytes. This is defined in a constant 'LIMIT' (merger.c).

The program takes as input a directory name and a filename where to produce the output.
Ex: ./ascii_merger <directory> <output filename>
- ./ascii_merger wolf/ wolf.txt
- ./ascii_merger wolf wolf.txt

When the function merge() is invoked, it starts scanning the provided directory for files
that should be part of an ASCII art. The files must match the pattern 'part_x_y_name.txt' for the program to be
able to read and parse them. While reading the files it also calculates the number of rows and columns. Those values
are stored in two static int variables (x and y). This is used to dynamically initialize a 2D-array with the number of 
rows equal to calculated rows times 30 bytes, and the number of columns equal to the calculated columns times 30 bytes.
The initialization of the 2D-array is done in the init() method.

The process of parsing the files begins by parsing and concatenating the columns of the first row incrementally,
then all columns of the second row etc. The array contains the merged ASCII-art when its done.
Two static int variables (row_pos and col_pos) keeps track of the position in the array where each line of text
should be placed.
Static was used to limit the scope of variables and functions to file only (merger.c), 
but make variables global to local functions.

Next step is writing the merged ASCII-art to a file. A method print() is invoked and starts a nested for-loop
which runs through the array and prints it out all rows and columns. The filename of the output-file is
specified by the user.
A message will appear in the terminal informing the user when the merging is done.

At last, a function, clean(), free's up the memory allocated by the 2D-array.
