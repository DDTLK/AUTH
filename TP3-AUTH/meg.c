#include "meg.h"

void getKey(char ** key)
{
	char str1;
	char tmp[16];
	for (int i = 0; i < TAILLE; ++i)
	{
		srand(time(0)+i);
		for (int j = 0; j < 16; ++j)
		{
			str1 = number[rand() % (sizeof(number)-1)];
			tmp[i] = str1;
			//printf("%c",str1 );
		}
		//printf("\n");
		key[i] = tmp;
		for (int i = 0; i < 20; ++i)
		{
			printf("%s\n",key[i] );
		}
	}
}

