#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
typedef enum{false,true} bool;

void draw(char map[20][61],int x, int y,char c);

int main()
{
	bool ver=true,hor=true;
	int x=5,y=5;
	char map [20][61] ={    "############################################################",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"#                                                          #",
							"############################################################"};
	//char map [20][60];
	while(1)
	{
		if(y==1||y==18)
		{
			ver=!ver;
		}
		if(ver) y++;
		else y--;
		if(x==1||x==58)
		{
			hor=!hor;
		}
		if(hor) x++;
		else x--;


		draw(map,x,y,'@');

		usleep(50000);

		/*for(int i=0;i<20;i++)
		{
			strcpy(map[i],map_orig[i]);
		}*/

	}

	return 0;
}

void draw(char map[20][61],int x, int y,char c)
{
	system("clear");
	map[y][x]=c;
	for(int i=0;i<20;i++)
	{
		printf("%s\n",map[i]);
	}
	map[y][x]=' ';
}