#include "node.h"


void colorNode(char *node)
{
	for (int i = 0; i < TAILLE; ++i)
	{
		srand(time(0)*i);
		node[i] = color[rand() % (sizeof(color)-1)];
	}
}
	