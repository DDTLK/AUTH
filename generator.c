#include "generator.h"

static const char dictionaire[] =
    "0123456789"
	"!@#$%^&*"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	"abcdefghijklmnopqrstuvwxyz";


char gen_random() {
        return dictionaire[rand() % (sizeof(dictionaire) - 1)];
}

void get_key(char * pre_puzzle_key, char * secret_key){	
	for (int i = 0; i < 16; ++i)
	{	
		//
		pre_puzzle_key[i] = gen_random();
		secret_key[i] = gen_random();
	}
}

void get_pair(int n, char *pair[][2]){
	char pre_puzzle_key[16];
	char secret_key[16];

	char *ptr_pre_puzzle_key = pre_puzzle_key;
	char *ptr_secret_key = secret_key;

	for (int i = 0; i < n; ++i)
	{
		//initialise seed value
		srand(time(0)+i);
		//get pair of secret string
		get_key(ptr_pre_puzzle_key,ptr_secret_key);
		//put string in pair
		pair[i][0] = pre_puzzle_key;
		pair[i][1] = secret_key;
		print_key(ptr_pre_puzzle_key);
		print_key(ptr_secret_key);
	}
}

void print_key(char * key){
	for (int i = 0; i < 16; i++)
	{
		printf("%c", key[i]);
	}
	printf("%s\n", "");
}