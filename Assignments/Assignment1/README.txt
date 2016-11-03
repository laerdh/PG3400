PG3400 - Programming in C
Assignment 1

Date: 02/11-2016
Name: Lars Erling Westbye Dahl

Description:
This program reads the file once to find the number of words and the length of the
longest word in the file. This information is stored in two variables, numWords and maxChars respectively.
Each line is read and stored in a temporarily array of char called line, which have a max length of 256.
This means that the length of the word read cannot exceed 256 characters.

When the file has been read the next step is to allocate enough memory so we can have pointers
to all the words in the file (array). This is done by using malloc and multiplying number of words with the size of char-pointers.

The FILE-pointer is then rewind back to start of file so the file can be read one more time to copy the words.

Next step is running a for-loop through the list of char pointers and allocate memory to a new char pointer which
points to an array of char (the word itself). This is also done by using malloc. Since we already know the length of the longest
word (maxChars), we safely allocate enough memory by multiplying maxChars+1 with the size of char.
We take in account that chars ends with /0 and therefore adds 1 to maxChars.
The words are copied to the newly allocated memory, which have it's own pointer, using strncpy().

The file is closed using fclose().

A pointer to the array of words is sent to the function bubbleSort() along with it's size, numWords.
Bubblesort works directly on the array in memory and sorts it, then it returns.
Bubblesort also uses a utilitiy-function (swap), to change position of two words.

At last, the array is printed to the terminal/console telling the user how many words it sorted
and the list of all words, and the program free's up the memory used.

The program provides checks for user input, but also when allocating memory.
