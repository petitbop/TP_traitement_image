#ifndef _ADAPT
#define _ADAPT

//copie les valeurs d'une image dans une autre
void cop(double **entree, double **copy, int nl, int nc);

//calcule wt
double wt(double GT, double k);

//calcule Gtx^2 + Gty^2
double sum_GT(double** entree, int i, int j, int nl, int nc);

//t correspond au nombe d'itérations de la fonction
void adap_filter(double** entree, int nl,int nc, int t);


#endif
