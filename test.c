#include "generator.h"

int main(int argc, char const *argv[])
{

	char ** pair[20][2];
	char * pre_puzzle_key; char * secret_key;
	get_pair(20,pair);
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 16; i++)
			{
				printf("%s\n",pair[i][j]);
			}
			
		}
	}

	/*srand(time(NULL));
	char secret_key[16];
	for (int i = 0; i < 16; i++)
	{
		secret_key[i] = gen_random();
	}

	
	for (int i = 0; i < (sizeof(secret_key) -1); i++)
	{
		printf("%c", secret_key[i]); 
		printf("%s\n","");
	}*/
		
	return 0;
}