#include "pgm.h"
#include "psnr.h"
#include "adapt.h"
#include "math.h"


void cop(double **entree, double **copy, int nl, int nc){
    for(int i = 0 ; i < nl ; i++){
	for(int j = 0 ; j < nc ; j++){
	    copy[i][j] = entree[i][j];
	}
    }
}

double wt(double** entree,int i, int j, int  nl, int nc , double k){
    return exp(-sum_GT(entree,i,j,nl,nc)/(2*k*k));
}


double sum_GT(double** entree, int i, int j, int nl, int nc){
    double s_x_p1;
    double s_x_m1;
    double s_y_p1;
    double s_y_m1;
    s_x_m1 = entree[i - 1][j];
    s_x_p1 =  entree[i + 1][j];
    s_y_m1 = entree[i][j - 1];
    s_y_p1 =  entree[i][j + 1];
    double pow1 = (s_x_p1 - s_x_m1)*(s_x_p1 - s_x_m1);
    double pow2 = (s_y_p1 - s_y_m1)*(s_y_p1 - s_y_m1);
    return pow1 + pow2; 
}


void adap_filter(double** entree, int nl,int nc, int t, int ki){
    double ** copy = alloue_image_double(nl, nc);
    cop(entree,copy,nl,nc);
    double num = 0;
    double denom = 0;
    double k = ki;
    double sum;
    while(t >= 0){
	for(int i = 0 ; i < nl ; i++){
	    for(int j = 0 ; j < nc; j++){
		//calul dans la fenetre de taille 3
		for(int h = -1 ; h <= 1 ; h++){
		    for(int l = -1 ; l <= 1 ; l++){
			if( h + i >= 1 && j + l >= 1 && h + i < nl - 1 && j + l < nc -1){
			    num += wt(copy,i+h,j+l,nl,nc,k)*copy[i+h][j+l];
			    denom += wt(copy,i+h,j+l,nl,nc,k);
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
  int nbr_iter = 100;
  int k;
  if (ac < 4) {printf("Usage : %s entree sortie k \n",av[0]); exit(1); }
	/* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
  double**im3=imuchar2double(im1,nl,nc);
  im4=imuchar2double(im1,nl,nc);
  oldnl=nl; oldnc=nc;

  k =  atoi(av[3]);

  adap_filter(im3,nl,nc,nbr_iter,k);
  
  printf("%s \n PSNR : %lf \n",av[1],psnr(im4,im3,nl,nc));
  ecritureimagepgm(av[2],crop(imdouble2uchar(im3,nl,nc),0,0,oldnl,oldnc),oldnl,oldnc);
}
