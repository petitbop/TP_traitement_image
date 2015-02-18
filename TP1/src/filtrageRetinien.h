#ifndef _FILTRAGE
#define _FILTRAGE

#include <math.h>

unsigned char** filtrageRetinien( unsigned char** sortie,  unsigned char** entree, int nl, int nc);

unsigned char moyVoisin(int i, int j, int n, int nl, int nc, unsigned char** entree);

unsigned char moy(int nl, int nc, unsigned char** entree);


#endif
