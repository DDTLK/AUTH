#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "md5.h"


#define TAILLE 20

/**
*	number
*	tableau pour la génération de nombre aléatoire
*/
static const char number[] =
    "0123456789";

/**
*	getKey
*	input: matrice vide
*	output: matrice de clefs aléatoire de 128 bits
*/
void getKey(char key [][16]);

/**
*	permutation
*	input: adresse de tableau de caractère
*	output: les couleurs du tableau ont été permutées
*/
void permutation(char *color);

/**
*	miseEnGageColoriage
*	input:
*		color: tableau de noeud colorés
*		key: chaine aléatoire de 128 bits
*	output: couleur mis en gage dans la matrice res
*/
void miseEnGageColoriage(char color[],char key[][16], char res[][16]);

/**
*	preuveColoriage
*	input:
*		color: tableau de noeud colorés
*		key: chaine aléatoire de 128 bits
*		res: couleur mis en gage dans la matrice
*	output: boolean -> true si la vérification est réussi 
*/
bool preuveColoriage(char color[], char key[][16], char gage [][16]);
