#include "laplacien.h"


double fft_gaussian(double sigm, int i, int j, int nl, int nc){
    return exp(-2*pow(M_PI,2)*pow(sigm,2)*(pow((i-((double)nl/(double)2))/(double)nl,2) + pow((j-((double)nc/(double)2))/(double)nc,2)));
}

void  DoG(double ** entree_re,double **entree_im ,int nl,int nc, double sigm1, double sigm2){
    for(int i = 0 ; i < nl ; i++){
	for(int j = 0 ; j < nc ; j++){
	  entree_re[i][j] *= (fft_gaussian(sigm1,i,j,nl,nc) - fft_gaussian(sigm2,i,j,nl,nc));
	  entree_im[i][j] *= (fft_gaussian(sigm1,i,j,nl,nc) - fft_gaussian(sigm2,i,j,nl,nc));
	}
    }
}

void detectZero(double** laplacien, unsigned char** contour, int nl, int nc){
  for(int i = 1 ; i < nl-1 ; i++){
    for(int j = 0 ; j < nc-1 ; j++){
      if(laplacien[i][j]*laplacien[i+1][j] < 0 || 
	 laplacien[i][j]*laplacien[i][j+1] < 0 || 
	 laplacien[i][j]*laplacien[i+1][j+1] < 0 ){ /* on regarde s'il y a un 
					    changement de signe sur la fenetre 2x2*/
	contour[i][j] = 255;
      }
      else{
	contour[i][j] = 0;
      }
    }
  }
}

	/* 
		Exemple de code avec Entrees Sortie et transformations
		simples d'images S'utilise sous la forme "exemple
		tangram.pgm res.pgm"
 	*/
int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2]
			       le nom du resultat . */
  double sigm1 = 8;
  double sigm2 = 5; // le rapport des deux écarts types est alors de 1.6
  int nb,nl,nc, oldnl,oldnc;
  unsigned char **im2=NULL,** im1=NULL;
  double** im4,** im5, ** im6, ** im7, **im8, **im9,**im10, **im11, **im12, **im13;
  
  if (ac < 2) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
	/* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }

  im2 = alloue_image(nl, nc);
  /* convertion de l'image char en image double*/
  double** im3 = imuchar2double(im1,nl,nc);

  oldnl = nl ; oldnc = nc ;

im4 = padimdforfft(im3, &nl, &nc);

  im5 = alloue_image_double(nl,nc); im6 = alloue_image_double(nl,nc); im7 = alloue_image_double(nl,nc);

  fft(im4, im5, im6, im7, nl, nc); // im6 et im7 contiennent la fft

  im8 = alloue_image_double(nl,nc); im9 = alloue_image_double(nl,nc);
  
  fftshift(im6, im7, im8, im9, nl, nc);

  im10 =  alloue_image_double(nl,nc); im11 = alloue_image_double(nl,nc);
  
  DoG(im8,im9,nl,nc,sigm1, sigm2);

  im12 = alloue_image_double(nl,nc) ;  im13 = alloue_image_double(nl,nc) ;
  
  fftshift(im8,im9,im12,im13, nl, nc);

  ifft(im12, im13, im10, im11, nl, nc);  // im10 a l'image du laplacien, im11 aussi?

  // on trouve les contours en repérant les passage par 0
  detectZero(im10, im2, nl, nc);
	/* Sauvegarde dans un fichier dont le nom est passe sur la ligne de commande */
  ecritureimagepgm(av[2], im2, oldnl, oldnc);
}
