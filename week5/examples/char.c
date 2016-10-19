#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char * tekst = "Hei alle sammen!";
	
	for (int i = 0; i < 16; i++) {
		printf("bokstav: %c\n", tekst[i]);
	}
}
