#include <math.h>

/* calcul la convolution de entree avec filtre et met le resultat dans sortie
   w est la "demi-taille" du filtre, nl et nc les nombres de lignes et colonnes de l'image */
void convol(double ** entree, double** sortie, int** filtre, int w, int nl,int nc);

/* Soient P1 et P2 les points (virtuels) situés à distance de 1 de P dans la direction θ=arctan(Gy/Gx). On interpole la valeur de la norme du gradient en ces points */ 
double interpolGrad(double** G, int i, int j, double di, double dj);

/* Met dans 0 ou des 255 dans contour selon que notre gradient représente ou non un contour
 */
void supMaxima(double** GX, double** GY, double** G, unsigned char** contour, int nl, int nc);

/* Applique le seuillage par hystéresis
 */
void seuillage(double** G, unsigned char** contour, int nl, int nc, double seuilMin, double seuilMax);

double norm(double x, double y);

void normMatrix(double ** MX, double** MY, double ** M, int nl, int nc);

double average(double** M, int nl, int nc);
