#include "gaussian.h"
#include "pgm.h"
#include "psnr.h"
#include "math.h"



double fft_gaussian(double sigm, int i, int j, int nl, int nc){
    return exp(-2*pow(M_PI,2)*pow(sigm,2)*(pow((i-((double)nl/(double)2))/(double)nl,2) + pow((j-((double)nc/(double)2))/(double)nc,2)));
}

void  gaussian_filter(double ** entree_re,double **entree_im ,int nl,int nc, int sig){
    for(int i = 0 ; i < nl ; i++){
	for(int j = 0 ; j < nc ; j++){
	    entree_re[i][j] *= fft_gaussian(sig,i,j,nl,nc);
	    entree_im[i][j] *= fft_gaussian(sig,i,j,nl,nc);
	}
    }
}


int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
  int nb,nl,nc, oldnl,oldnc;
  unsigned char ** im1=NULL;
  double ** im3 ,** im4,** im5, ** im6, ** im7, **im8, **im9,**im10, **im11, **im12, **im13;
  if (ac < 4) {printf("Usage : %s entree sortie sigma\n",av[0]); exit(1); }
  /* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }

  int sig = atoi(av[3]);
  /* convertion de l'image char en image double*/
  im3 = imuchar2double(im1,nl,nc);
  
  oldnl = nl ; oldnc = nc ;
  
  im4 = padimdforfft(im3, &nl, &nc);
  
  im5 = alloue_image_double(nl,nc); im6 = alloue_image_double(nl,nc); im7 = alloue_image_double(nl,nc);
  
  fft(im4, im5, im6, im7, nl, nc);
  
  im8 = alloue_image_double(nl,nc); im9 = alloue_image_double(nl,nc);
  
  fftshift(im6, im7, im8, im9, nl, nc);

  im10 =  alloue_image_double(nl,nc); im11 = alloue_image_double(nl,nc);
  
  gaussian_filter(im8,im9,nl,nc,sig);

  im12 = alloue_image_double(nl,nc) ;  im13 = alloue_image_double(nl,nc) ;
  
  fftshift(im8,im9,im12,im13, nl, nc);

  ifft(im12, im13, im10, im11, nl, nc);
  	/* Conversion en entier8bits de la partie reelle de la fftinverse, 
	   Suppresion des 0 qui ont servi a completer en utilisant la fonction crop
	   Sauvegarde au format pgm de cette image qui doit etre identique a 'linverse video 
	   car on a realise la suite fftinv(fft(image))*/
  printf("%s \n PSNR : %lf \n",av[1],psnr(im4,im10,nl,nc));
  ecritureimagepgm(av[2],crop(imdouble2uchar(im10,nl,nc),0,0,oldnl,oldnc),oldnl,oldnc);

}
