#ifndef _FILTRAGE
#define _FILTRAGE

#include <math.h>

unsigned char** filtrageRetinien( unsigned char** sortie,  unsigned char** entree, int nl, int nc);

int moyVoisin(int i, int j, int n, int nl, int nc, unsigned char** entree);

int moy(int nl, int nc, unsigned char** entree);


#endif
