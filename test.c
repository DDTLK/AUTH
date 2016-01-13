#include "generator.h"



int main(int argc, char const *argv[])
{

	char pre_puzzle_key[16];
	char secret_key[16];

	for (int i = 0; i < 20; ++i)
	{
		//initialise seed value
		srand(time(0)+i);
		//get pair of secret string
		get_key(pre_puzzle_key,secret_key);
		//print key
		print_key(pre_puzzle_key);
		print_key(secret_key);
	}
		
	return 0;
}