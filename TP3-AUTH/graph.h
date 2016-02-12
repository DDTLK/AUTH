#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"


/**
*	Declaration des Graphes
*	noeuds et arcs
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
*	return: graphe colorié
*/
Graphe genererGraphe3Coloriable();