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

void print_key(char * key){
	for (int i = 0; i < 16; i++)
	{
		printf("%c", key[i]);
	}
	printf("%s\n", "");
}