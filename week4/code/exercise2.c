#include <stdio.h>
#include <stdlib.h>

int main() {
	// Normal usage of scanf
	int a, b;

	printf("Type two integers seperated with space\n");
	scanf("%d %d", &a, &b);
	printf("The numbers are %d, %d\n", a, b);


	// Alternative usage with pointers
	int *aInt = malloc(1*sizeof(int));
	int *bInt = malloc(1*sizeof(int));
	int largest;

	printf("Type two integers seperated with space\n");
	scanf("%d %d", aInt, bInt);
	printf("The numbers are %d, %d \n", *aInt, *bInt);

	if (*aInt > *bInt) {
		largest = *aInt;
	} else {
		largest = *bInt;
	}

	printf("The largest number was %d\n", largest);

	free(aInt);
	free(bInt);
	aInt = NULL;
	bInt = NULL;

	return 0;
}
