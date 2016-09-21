Today we learnt about pointers. In all textbooks and forums, pointers are
mentioned to be complicated or complex and pushed to the end of the course. But
pointers are really simple. It is their flexibility that makes the applications
and use cases complicated. We will learn how to play with pointers and get our
hands dirty. 

Exercise 1:
Expected time on the problem: 10 min
Take the following code, what would you expect the answers would be? Why do you
think they are the way they are?

int *pInt;
char *pChar;
short *pShort;
double *pDouble;

printf("The size of pointers are %lu, %lu, %lu, %lu respectively \n", 
	sizeof(pInt), sizeof(pChar), sizeof(pShort), sizeof(pDouble));

printf("The size of variables are %lu, %lu, %lu, %lu respectively \n", 
	sizeof(*pInt), sizeof(*pChar), sizeof(*pShort), sizeof(*pDouble));


Exercise 2:
Expected time on the problem: 10 min
Normal usage of scanf is the following:
int a,b;
printf("Type two integers seperated with space\n");
scanf("%d %d", &a, &b);
printf("The numbers are %d, %d \n", a,b);

Write a program where you use scanf to read integers from the terminal, but
without using '&' in the scanf call. It should look more like this :

scanf("%d %d", p, q);

Also print the larger of the two.

Exercise 3:
Expected time on the problem: 40 min
Write a small program that does bubble sort on an array of positive integers. The
integers or the number of them is unknown. Use realloc to reallocate memory
They are typed through terminal.  Input should stop when you enter '0' and
then sorting should start. Swapping should be done by function call
- swap(a,b). 

The output should print :
	- The number of input integers
	- 0 should not be counted as part of the integers list
	- The sorted list of integers

Hints :
int i;
while(1){
	scanf("%d", &i);
} //Will give you input to i - but watch out for infinte loop. 

Bubble sort:

Run through the elements and swap when you find a[i-1] < a[i]. Keep doing
this until you cannot swap anymore. 
	


