#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee{
	int id; // 4 byte
	char name[30]; // 30 byte
	int salary; // 4 byte
} Employee; // size = 38 byte

int main()
{
	Employee a;
	a.id = 42;
	strcpy(a.name, "Foo Bar");
	a.salary = 1000;

	printf("Employee id: %d, name: %s, salary: %d\n", a.id, a.name, a.salary);		
	printf("Sizeof Employee: %lu bytes\n", sizeof(Employee));
}
