#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n=1;
	int x=1;
	while(x<<=1) n++;
	printf("A gépi szó hossza: %d\n",n);
	return 0;
}