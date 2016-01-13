#include "generator.h"
#include "md4.h"
#include "aes.h"


int main(int argc, char const *argv[])
{

	char pre_puzzle_key[16];
	char secret_key[16];

	uint32_t inv[4]={0,0,0,0};
	char puzzle_key[4];

	for (int i = 0; i < 5; ++i)
	{
		//initialise seed value
		srand(time(0)+i);
		//get pair of secret string
		get_key(pre_puzzle_key,secret_key);
		//print key
		print_key(pre_puzzle_key);
		print_key(secret_key);
		cMD4(inv,(uint32_t*)pre_puzzle_key,(uint32_t*)puzzle_key);
	}
		
	return 0;
}