#include "pgm.h"
#include "math.h"

// renvoie la fft d'une gaussienne
double fft_gaussian(double sigm, int i, int j, int nl, int nc);

// réalise l'operation FFT(Gauss1 - Gauss2).FFT(image)
void  DoG(double ** entree_re,double **entree_im ,int nl,int nc, double sigm1, double sigm2);

// repère les passages par zéro du laplacien
void detectZero(double** laplacien, unsigned char** contour, int nl, int nc);
