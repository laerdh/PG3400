#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int antall_tall = 20;
	int *tall=malloc(antall_tall*sizeof(int));

	// Initialiser alt til null	
	memset(tall, 0, antall_tall*sizeof(int));
	tall[0] = 2;
	tall[10] = 20;
	
	for (int i = 0; i < antall_tall; i++) {
		printf("tall: %d\n", tall[i]);
	}
}
