#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double x;
	double y;
} coord;

typedef struct {
	char name[20];
	coord vertices[4];
} rect;

int main()
{
	rect r1 = { "first",
	{
		{0,1},
		{0,0},
		{1,0},
		{1,1}
	}
	};

	rect r2 = { "second", 0,1,0,0,1,0,1,1 };
}
