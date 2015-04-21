#include <math.h>


void convol(double ** entree, double** sortie, int** filtre, int w, int nl,int nc);

void seuillage(double** G, unsigned char** contour, int nl, int nc, double seuil);

double norm(double x, double y);

void normMatrix(double ** MX, double** MY, double ** M, int nl, int nc);

double average(double** M, int nl, int nc);
