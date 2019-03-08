#include <stdio.h>
#include <stdlib.h>

int *h()
{
	return (int*) malloc(sizeof(int));
}

/*int *(*l())()
{
	return &h;
}*/



int main()
{
	int *(*l)() = h;

	printf("%p\n",l());
	return 0;
}