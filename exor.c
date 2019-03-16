#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc > 2)
	{
		//Ez csak a törő program tesztelése miatt volt fontos megadni, ugyanis a törő 
		//program csak 8 karakter hosszúságú kulcsot tud törni.
		/*if(strlen(argv[2])!=8)
		{
			printf("Bad key\n");
			return -1;
		}*/
		FILE* fin = fopen(argv[1],"r");
		if(fin==NULL)
		{
			printf("File doesn't exist.\n");
			return -3;
		}
		else
		{
			char c;
			int i=0;
			while(!feof(fin))
			{
				fscanf(fin,"%c",&c);
				c^=argv[2][i%strlen(argv[2])];
				printf("%c",c);
			}
			fclose(fin);
		}

	}
	else 
	{
		printf("Használd: ./e fájlnév.txt kulcs\n");
		return -2;
	}
	printf("\n");
	return 0;
}
