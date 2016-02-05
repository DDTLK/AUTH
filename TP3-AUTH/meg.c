#include "meg.h"

void getKey(char * key)
{
	char tmp[16];
	for (int i = 0; i < TAILLE; ++i)
	{
		srand(time(0)*i+1);
		for (int j = 0; j < 16; ++j)
		{
			tmp[j] = number[rand() % (sizeof(number)-1)];
			printf("%c",tmp[j] );
		}
		printf("\n");
		key[i] = tmp;
		/*for (int j = 0; j < 16; ++j)
		{
			printf("%c", key[j]);	 
		}
		printf("\n");*/
	}
	printf("\n");
}