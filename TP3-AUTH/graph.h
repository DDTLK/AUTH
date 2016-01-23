#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"


/**
*	Declaration des Graphes
*
*/
struct Graphe
{
	char node[20];
	char edge[20][20];
};
typedef struct Graphe Graphe;

/**
*	Generation des graphes
*
*
*/
Graphe genererGraphe3Coloriable();