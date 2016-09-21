#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arrayInt = (int *)malloc(1*sizeof(int));
	int i;
	int count;

	while(i != 0) {
		printf("Please enter a number\n");
		scanf("%d", &i);
		arrayInt[count] = i; 
		count++;
		arrayInt = (int *)realloc(arrayInt, ((count+1)*sizeof(int)));
	}

	free(arrayInt);
	arrayInt = NULL;

	// Do Bubblesort algorithm here

	return 0;
}
