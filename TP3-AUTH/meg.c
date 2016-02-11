#include "meg.h"

void getKey(char key[][16])
{
	for (int i = 0; i < TAILLE; ++i)
	{
		srand(time(0)+i+1);
		for (int j = 0; j < 16; ++j)
		{
			key[i][j] = number[rand() % (sizeof(number)-1)];
		}
	}
}

void permutation(char *color)
{
	for (int i = 0; i < TAILLE; ++i)
	{
		switch(color[i])
		{
			case 'B': color[i]='R';
			break;
			case 'R': color[i]='V';
			break;
			case 'V': color[i]='B';
			break;
		}
	}
}

static MD5_CTX MDString (inString)
char *inString;
{
  MD5_CTX mdContext;
  unsigned int len = strlen (inString);
  MD5Init (&mdContext);
  MD5Update (&mdContext, inString, len);
  MD5Final (&mdContext);
return mdContext;
}

void miseEnGageColoriage(char color[], char key[][16], char res[][16]) 
{
	char tmp[17];

	permutation(color);

	for (int i = 0; i < TAILLE; ++i)
	{
		tmp[0]=color[i];

		for (int j = 0; j < 16; ++j)
		{
			tmp[1+j]=key[i][j];	
		}

		MD5_CTX mdContext = MDString(tmp);
		
		for (int x = 0; x < 16; ++x)
		{
			res[i][x]=mdContext.digest[x];
		}
	}
}

bool preuveColoriage(char color[], char key[][16], char gage [][16])
{
	char preuve[20][16];
	bool res = false;
	miseEnGageColoriage(color, key, preuve);

	for (int i = 0; i < TAILLE; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			if (preuve[i][j]==gage[i][j]) res =true;
			else res=false;
		}
	}
	return res;
}