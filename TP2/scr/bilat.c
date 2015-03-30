#include "pgm.h"
#include "bilat.h"
#include "math.h"

void cop(double **entree, double **copy, int nl, int nc){
    for(int i = 0 ; i < nl ; i++){
	for(int j = 0 ; j < nc ; j++){
	    copy[i][j] = entree[i][j];
	}
    }
}

double w_exp(double** entree, int i , int j , int h , int l, double sig1 , double sig2){
    return exp(-(h*h + l*l)/(2*sig1*sig1))*exp(-(pow(entree[i+h][j+l] - entree[i][j],2))/(2*sig2*sig2));
}

void bilat_filter(double** entree, int nl, int nc, int t){
    double ** copy = alloue_image_double(nl, nc);
    cop(entree,copy,nl,nc);
    double num = 0;
    double denom = 0;
    double sig1 = 5;
    double sig2 = 2;
    double sum;
    while(t >= 0){
	for(int i = 0 ; i < nl ; i++){
	    for(int j = 0 ; j < nc; j++){
		//calul dans la fenetre de taille 3
		for(int h = -3*sig1 ; h <= 3*sig1 ; h++){
		    for(int l = -3*sig2 ; l <= 3*sig2 ; l++){
			if( h + i >= 0 && j + l >= 0 && h + i < nl && j + l < nc){
			    sum = w_exp(copy,i,j,h,l,sig1,sig2);
			    num += sum*copy[i+h][j+l];
			    denom += sum;
			}
		    }
		}
		entree[i][j] = (double)num/(double)denom;
		num = 0;
		denom = 0;
	    }
	}
	cop(entree,copy,nl,nc);
	t--;
	}
}


int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
  int nb,nl,nc, oldnl,oldnc;
  unsigned char **im2=NULL,** im1=NULL;
  double** im4,** im5, ** im6, ** im7, **im8, **im9,**im10;
  int nbr_iter = 10;
  if (ac < 3) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
	/* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
  double**im3=imuchar2double(im1,nl,nc);
  oldnl=nl; oldnc=nc;
  /*for(int i = 0 ; i < nl ; i++){
	for(int j = 0 ; j < nc ; j++){
	    printf("%lf \n",im3[i][j]);
	}
	}*/
  bilat_filter(im3,nl,nc,nbr_iter);
  
  ecritureimagepgm(av[2],crop(imdouble2uchar(im3,nl,nc),0,0,oldnl,oldnc),oldnl,oldnc);
}
