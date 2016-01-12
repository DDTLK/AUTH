#include "generator.h"

int main(int argc, char const *argv[])
{

	char *pair[20][2];
	char pre_puzzle_key[16];
	char secret_key[16];

	char *p_pre_puzzle_key = pre_puzzle_key;
	char *p_secret_key = secret_key;
	//char *p_pair = pair;

	get_pair(20, pair);
	printf("%s\n","test1" );
	printf("%s\n",pair[1][1] );
	print_key(pair[0][0]);

		
	return 0;
}