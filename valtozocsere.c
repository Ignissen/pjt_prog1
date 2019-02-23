#include <stdio.h>

int main()
{
	int a=5,b=4;

	printf("a=%d, b=%d\n",a,b);
	int tmp = a;
	a=b;
	b=tmp;
	printf("a=%d,b=%d\n",a,b);
	return 0;
}