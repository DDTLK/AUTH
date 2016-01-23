#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAILLE 20

/**
*
*	Stockage des couleurs
*
*/
static const char color[]=
	"R"
	"V"
	"B";

/**
*
*	Creation aléatoire de noeuds de differente coulers
*
*
*/
void colorNode(char *node);