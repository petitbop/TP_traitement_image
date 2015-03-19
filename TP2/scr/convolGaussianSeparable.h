#ifndef _CONVOLGAUSSIAN
#define _CONVOLGAUSSIAN


void filtrage_horizontal(double ** entree, double** sortie, double sigm, int w, int nl,int nc);

void filtrage_vertical(double ** entree, double** sortie,double sigm, int w, int nl,int nc);
#endif
