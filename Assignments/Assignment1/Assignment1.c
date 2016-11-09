#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(); 
void bubbleSort();
void print();

int main(int argc, char *argv[])
{
	char line[256];
	int numWords = 0;
	int maxChars = 0;
	char **words;

	const char *fileName = argv[1];
	if (fileName == NULL) {
		perror("Error opening file");
		return -1;
	
	}

	FILE *file = fopen(fileName, "r");
	if (file == NULL) {
		perror("Error opening file");
		return -1;
	}
	
	// Read file once to
	// collect number of words and max length
	while (fgets(line, sizeof(line), file) != NULL) {
		size_t wordsize = strlen(line);
		
		if (wordsize > maxChars)
			maxChars = wordsize;

		numWords++;
	}
	words = malloc((numWords)*sizeof(char*));
	rewind(file);

	if (words == NULL) {
		perror("ERROR: Out of memory");
		return -1;
	}

	// Read file again and copy to 2D-array
	for (int i = 0; i < numWords; i++) {
		fgets(line, sizeof(line), file);
		// maxChars + 1 because string ends with 0
		words[i] = malloc((maxChars+1)*sizeof(char));
		strncpy(words[i], line, maxChars+1);
		
		if (words[i] == NULL) {
			perror("ERROR: Failed to allocate memory");
			return -1;
		}
	}	
	
	// Close file
	fclose(file);

	// Sort array
	bubbleSort(words, numWords);

	// Print sorted array
	print(words, numWords);	

	// Free up memory
	for (int k=0; k < numWords; k++) {
		free(words[k]);
	}
	free(words);

	return 0;
}

void bubbleSort(char **array, int size) 
{
	for (int i = 0; i < (size-1); i++) {
		for (int j = 0; j < (size-1); j++) {
			if (strcmp(array[j], array[j+1]) > 0) {
				swap(array, j, j+1);
			}
		}
	}
	
	return;
}

void swap(char **array, int a, int b)
{
	char *temp = array[a];
	array[a] = array[b];
	array[b] = temp;

	return;
}

void print(char **array, int size)
{
	printf("---- Sorted %d elements. ----\n", size);
	for (int i = 0; i < size; i++) {
		printf("%d. %s", (i+1), array[i]);
	}
	
	return;
}

