#ifndef _MEDIAN
#define _MEDIAN

/* calcul un histogramme d'une fenetre 2N+1 autour de (i, j) */
int** hist( unsigned char** entree, int i, int j, int N, int nl, int nc);

/* renvoie la valeur du nouveau point */
int majHist(int** histogramme, int N);

/* applique un filtre median sur l'image*/
void median(unsigned char** entree, unsigned char** sortie, int N, int nl, int nc);
#endif
