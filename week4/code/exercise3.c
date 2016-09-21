#include <stdio.h>
#include <stdlib.h>


// Function declaration (for Compiler)
void swap();
void printArray();


int main() {
	int *p_array = (int *)malloc(1*sizeof(int));
	int i;
	int count;

	while(1) {
		printf("Please enter a number\n");
		scanf("%d", &i);
		if (i == 0) break;
		p_array[count++] = i; 
		p_array = (int *)realloc(p_array, ((count+1)*sizeof(int)));
	}

	// Do Bubblesort algorithm here
	for (int n = 0; n < (count-1); n++) {
		for (int k = 0; k < (count-1); k++) {
			if (p_array[k] > p_array[k+1]) {
				swap(p_array, k, k+1);
			}
		}
	}

	// Print array
	printArray(p_array, count);

	// Free memory
	free(p_array);
	p_array = NULL;

	return 0;
}


// Function definitions
void swap(int *array, int a, int b) {
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;

	return;
}

void printArray(int *array, int size) {
	printf("List is sorted:\n");
	for (int i = 0; i < size; i++) {
		printf("[%d]", array[i]);
	}
	printf("\n");

	return;
}
