#include "gaussian.h"
#include "pgm.h"



void  gaussian_filter(double ** entree){

}


main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
  int nb,nl,nc, oldnl,oldnc;
  unsigned char ** im1=NULL;
  double ** im3 ,** im4,** im5, ** im6, ** im7, **im8, **im9,**im10, **im11;
  if (ac < 3) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
  /* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
  
  im3 = imuchar2double(im1,nl,nc);
  
  oldnl = nl ; oldnc = nc ;
  
  im4 = padimdforfft(im3, &nl, &nc);
  
  im5 = alloue_image_double(nl,nc); im6 = alloue_image_double(nl,nc); im7 = alloue_image_double(nl,nc);
  
  fft(im4, im5, im6, im7, nl, nc);
  
  fftshift(im6, im7, im8, im9, nl, nc);

  im10 =  alloue_image_double(nl,nc); im11 = alloue_image_double(nl,nc);
  
  gaussian_filter(im8);

  ifft(im8, im9, im10, im11, nl, nc);
  	/* Conversion en entier8bits de la partie reelle de la fftinverse, 
	   Suppresion des 0 qui ont servi a completer en utilisant la fonction crop
	   Sauvegarde au format pgm de cette image qui doit etre identique a 'linverse video 
	   car on a realise la suite fftinv(fft(image))*/
  ecritureimagepgm(av[2],crop(imdouble2uchar(im10,nl,nc),0,0,oldnl,oldnc),oldnl,oldnc);

}
