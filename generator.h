#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*	gen_random
*
*	Generateur de caractère aléatoire
*
*/
char gen_random();

/*	get_key
*
*	Genère deux chaine aléatoire de 128 bits
*	sortie: pre_puzzle_key, secret_key
*
*/
void get_key(char * pre_puzzle_key, char * secret_key);

/*	print_key
*
*	Affiche la chaine pointer par *key
*
*/
void print_key(char * key);

