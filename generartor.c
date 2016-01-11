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

	srand(time(NULL));
	for (int i = 0; i < 16; i++)
	{
		pre_puzzle_key[i] = gen_random();
		secret_key[i] = gen_random();
	}
}

void get_pair(int n, char ** pair){
	char * pre_puzzle_key;
	char * secret_key;
	//char * pair[n][2];
	for (int i = 0; i < n; ++i)
	{
		get_key(pre_puzzle_key,secret_key);
		pair[i][0] = pre_puzzle_key;
		pair[i][1] = secret_key;
	}
}