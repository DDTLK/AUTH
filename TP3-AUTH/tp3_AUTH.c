#include "graph.h"
#include "meg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	Graphe graph;
	char *tab[20];
	graph = genererGraphe3Coloriable();
	for (int i = 0; i < sizeof(graph.node); ++i)
	{
		printf("node %d : %c\n", i, graph.node[i]);
	}
	for (int i = 1; i < sizeof(graph.node); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			printf(" | %c \t",graph.edge[i][j]);
			if(j==i-1) printf("\n");
		}
	}
	getKey(tab);
	for (int i = 0; i < TAILLE; ++i)
	{
		char *tmp = NULL;
		tmp = tab[i];
		printf("%c", *tab[i]);
				printf("\n");

		for (int j = 0; j < 16; ++j)
		{
			printf("%s", &tmp[j]);
			//if(j==16) printf("\n");
			 
		}
		printf("\n");
	}
	return 0;
}