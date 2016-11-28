#include <stdio.h>

int main(int argc, char *argv[])
{
	int a=3, b=6;

	FILE *fil = fopen("nyfil.txt", "w");
	fprintf(fil, "a=%d, b=%d", a, b);
	fclose(fil);

	return 0;
}
