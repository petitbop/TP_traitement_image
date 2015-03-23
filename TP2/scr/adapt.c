#include "pgm.h"
#include "adapt.h"
#include "math.h"


void cop(double **entree, double **copy, int nl, int nc){
    for(int i = 0 ; i < nl ; i++){
	for(int j = 0 ; j < nc ; j++){
	    copy[i][j] = entree[i][j];
	    //printf("%d \n",entree[i][j]);
	}
    }
}

double wt(double GT, double k){
    return exp(-GT/(2*pow(k,2)));
}


double sum_GT(double** entree, int i, int j, int nl, int nc){
    double s_x_p1;
    double s_x_m1;
    double s_y_p1;
    double s_y_m1;
    /* if(i <= 0){
	s_x_m1 = 0;
    }
    else {*/
	s_x_m1 = entree[i - 1][j];
	/* }
    if(i >= nl - 1){
	s_x_p1 = 0;
    }
    else {*/
	s_x_p1 =  entree[i + 1][j];
	/* }
    if(j <= 0){
	s_y_m1 = 0;
    }
    else {*/
	s_y_m1 = entree[i][j - 1];
	/*}
    if(j >= nc - 1){
	s_y_p1 = 0;
    }
    else {*/
	s_y_p1 =  entree[i][j + 1];
	//}
	printf("%i %i \n",i,j);
	printf("%i %i \n",nl,nc);
    return pow(s_x_p1 - s_x_m1,2) + pow(s_y_p1 - s_y_m1,2); 
}


void adap_filter(double** entree, int nl,int nc, int t){
    double ** copy = alloue_image_double(nl, nc);
    cop(entree,copy,nl,nc);
    double num = 0;
    double denom = 0;
    double k = 4;
    while(t >= 0){
	for(int i = 2 ; i < nl - 2 ; i++){
	    for(int j = 2 ; j < nc - 2 ; j++){
		//calul dans la fenetre de taille 3
		for(int k = -1 ; k <= 1 ; k++){
		    for(int l = -1 ; l <= 1 ; l++){
			num += wt(sum_GT(copy,i + k,j + l,nl,nc),k)*copy[i+k][j+l];
			denom += wt(sum_GT(copy,i + k,j + l,nl,nc),k);
			//printf("%lf \n",denom);
		    }
		}
		entree[i][j] = num/denom;
		
	    }
	}
	num = 0;
	denom = 0;
	cop(entree,copy,nl,nc);
	t--;
    }
}

int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
  int nb,nl,nc, oldnl,oldnc;
  unsigned char **im2=NULL,** im1=NULL;
  double** im4,** im5, ** im6, ** im7, **im8, **im9,**im10;
  int nbr_iter = 1;
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
  adap_filter(im3,nl,nc,nbr_iter);
  
  ecritureimagepgm(av[2],crop(imdouble2uchar(im3,nl,nc),0,0,oldnl,oldnc),oldnl,oldnc);
}
