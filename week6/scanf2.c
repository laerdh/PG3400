#include <stdio.h>

int main(int argc, char *argv[]) {
	int a,b;

	printf("Hi this is just an ouput\n");

	int c = scanf("%d, %d", &a, &b);
	printf("a=%d, b=%d, returverdi=%d", a, b, c);

	return 0;
}
