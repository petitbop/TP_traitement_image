#ifndef _GAUSSIAN
#define _GAUSSIAN

double fft_gaussian(double sigm, int i, int j, int nl, int nc);

void gaussian_filter(double ** entree,double **entree_im,int nl,int nc);

#endif
