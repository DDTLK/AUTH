#include "graph.h"
#include "meg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	Graphe graph;
	char key[20][16];
	char gageColor[20][16];
	bool auth = false;

	for (int i = 0; i < 400; ++i)
	{
		graph = genererGraphe3Coloriable();
		/*
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
		*/
	
		getKey(key);
		/*
		printf("\n");
		for (int i = 0; i < TAILLE; ++i)
		{
			for (int j = 0; j < 16; ++j)
			{
				printf("%c", key[i][j]);	 
			}
			printf("\n");
		}
		*/

		miseEnGageColoriage(graph.node, key, gageColor);
		/*
		printf("\n");
		for (int i = 0; i < TAILLE; ++i)
		{
			for (int j = 0; j < 16; ++j)
			{
				printf("%c", gageColor[i][j]);	 
			}
			printf("\n");
		}
		*/
		bool res = preuveColoriage(graph.node, key, gageColor);
		if (!res) auth = true;
		else
		{
			printf("Wrong authentification, retry!\n");
			break;
		}
	}
	if (auth) printf("You are authentified\n");
	
	return 0;
}