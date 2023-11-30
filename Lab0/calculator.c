#include <stdio.h>

int main()
{
	int x;
	int y;
	int add;
	int mult;
	int div;
	int mod;

	printf("Enter x: ");
	scanf("%d", &x);
	printf("Enter y: ");
	scanf("%d", &y);

	add = x+y;
	mult = x*y;
	div = x/y;
	mod = x%y;

	printf("\nHere are the results:\n");
	printf("x+y = %d \n", add );
	printf("x*y = %d \n", mult);
	printf("x/y = %d \n", div);
	printf("x%%y = %d \n", mod);

	return 0;
}
