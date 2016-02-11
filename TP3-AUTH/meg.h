#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "md5.h"


#define TAILLE 20

/**
*
*
*/
static const char number[] =
    "0123456789";

/**
*
*
*/
void getKey(char key [][16]);

/**
*
*
*/
void permutation(char *color);

/**
*
*
*/
void miseEnGageColoriage(char color[],char key[][16], char res[][16]);

/**
*
*
*/
bool preuveColoriage(char color[], char key[][16], char gage [][16]);
