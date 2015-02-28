#include "pgm.h"
#include "contraste.h"

double contraste(unsigned char** entree , int nl, int nc){
	int i;
	int j;
	int n = 5 ; // taille du voisinage
	int max ;
	int min ;
	double moy = 0;
	for(i = 0 ; i < nl ; i++){
		for(j = 0 ; j < nc ; j++){
			max = maxloc(i,j,n,nl,nc,entree);
			min = minloc(i,j,n,nl,nc,entree);
			moy += (double)(max - min)/(double)(max + min);
		}
	}
	return  moy/(double)(nc*nl);
}

int maxloc(int i, int j, int n, int nl, int nc, unsigned char** entree){
	int max = entree[i][j];
	int k;
	int l;
	for(k = -n; k <= n; k++){
		for(l = -n; l <= n; l++){
			 if(i+k >= 0 && i+k <= nl-1 && j+l >= 0 && j+l <= nc - 1){
				 if(entree[i+k][j+l] > max)
					 max = entree[i+k][j+l];
			 }
		}
	}
	return max;
}

int minloc(int i, int j, int n, int nl, int nc, unsigned char** entree){
	int min = entree[i][j];
	int k;
	int l;
	for(k = -n; k <= n; k++){
		for(l = -n; l <= n; l++){
			 if(i+k >= 0 && i+k <= nl-1 && j+l >= 0 && j+l <= nc - 1){
				 if(entree[i+k][j+l] < min)
					 min = entree[i+k][j+l];
			 }
		}
	}
	return min;
}

int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
  int nb,nl,nc, oldnl,oldnc;
  unsigned char ** im1=NULL;
  double contr;
  if (ac < 1) {printf("Usage : %s entree \n",av[0]); exit(1); }
	/* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
  contr = contraste(im1,nl,nc);
  printf("contraste de l'image : %f \n", contr);
  libere_image(im1);
}
