#include <math.h>

/* calcul la convolution de entree avec filtre et met le resultat dans sortie
   w est la "demi-taille" du filtre, nl et nc les nombres de lignes et colonnes de l'image */
void convol(double ** entree, double** sortie, int** filtre, int w, int nl,int nc);

void seuillage(double** G, unsigned char** contour, int nl, int nc, double seuil);

double norm(double x, double y);

void normMatrix(double ** MX, double** MY, double ** M, int nl, int nc);
