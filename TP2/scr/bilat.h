#ifndef _BILAT
#define _BILAT


void cop(double **entree, double **copy, int nl, int nc);

double w_exp(double** entree, int i , int j , int h , int l, double sig1 , double sig2);

//t correspond au nombre d'itérations de la fonction
void bilat_filter(double** entree, int nl, int nc, int t, int sigm1, int sigm2);

#endif
