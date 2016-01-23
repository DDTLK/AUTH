#include "graph.h"


Graphe genererGraphe3Coloriable()
{
	Graphe graphe;
	colorNode(graphe.node);
	for (int i = 1; i < sizeof(graphe.node); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if ((i!=j) && graphe.node[i] == graphe.node[j])
			{
				graphe.edge[i][j] = 'X';
			}
		}
	}
	
	return graphe;
}