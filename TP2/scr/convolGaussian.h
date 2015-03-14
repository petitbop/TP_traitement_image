#ifndef _CONVOLGAUSSIAN
#define _CONVOLGAUSSIAN

/*
void filtrage_horizontale(double ** entree_re,double **entree_im, double** sortie_re,  double** sortie_im, double sigm, int w, int nl,int nc);*/
void filtrage_horizontal(double ** entree, double** sortie, double sigm, int w, int nl,int nc);
/*
  void filtrage_verticale(double ** entree_re,double **entree_im, double** sortie_re, double** sortie_im,double sigm, int w, int nl,int nc);*/
void filtrage_vertical(double ** entree, double** sortie,double sigm, int w, int nl,int nc);
#endif
