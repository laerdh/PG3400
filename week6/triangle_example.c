#include <stdio.h>

typedef struct point{
	int x,y;
}point;

typedef struct triangle{
	point points[3];
}triangle;

int main(int argc, char *argv[])
{
	triangle thisTriangle={
	0.0f,1.0f,
	0.0f,0.0f,
	1.0f,0.0f };
	
	FILE* file = fopen("triangle.txt", "wb");
	fwrite(&thisTriangle, sizeof(triangle), 1, file);
	//fread(&thisTriangle, sizeof(triangle), 1, file);
	printf("siste point = %d,%d", thisTriangle.points[2].x, thisTriangle.points[2].y);

	fclose(file);

	return 0;
}
