#include "generator.h"

int main(int argc, char const *argv[])
{

	char pair[20][2];
	char pre_puzzle_key[16];
	char secret_key[16];

	char *p_pre_puzzle_key = pre_puzzle_key;
	char *p_secret_key = secret_key;
	//char *p_pair = pair;

	//get_key(p_pre_puzzle_key,p_secret_key);
	//print_key(p_secret_key);
	//print_key(p_pre_puzzle_key);


	char *ptr_pair = get_pair(20);
	printf("%s\n","test1" );

	/*for (int i = 0; i < 20; ++i)
	{
				char * key  = pair[i];
				for (int i = 0; i < 2; ++i)
				{
					char * secret = key[i];
					printf("%s\n","key:" );
					print_key(key);

				}
	}*/

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