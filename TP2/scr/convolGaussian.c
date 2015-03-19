#include "pgm.h"
#include "convolGaussian.h"
#include "math.h"


void filtrage(double ** entree, double** sortie,double sigm, int w, int nl,int nc){
  double tmp = 0;
  // on parcourt l'image
  for(int x = 0; x < nl; x++){
    for(int y = 0; y < nc; y++){
      sortie[x][y] = 0;
      // on fait la convolution
      for(int i = -w; i <= w; i++){
	for(int j = -w; j <= w; j++){
	  // l'image est periodisee
	  int xPrime = (x+i) % nl;
	  if (xPrime < 0){
	    xPrime += nl;
	  }
	  int yPrime = (y+j) % nc;
	  if (yPrime < 0){
	    yPrime += nc;
	  }
	  tmp = 1/(2*M_PI * pow(sigm, 2)) * entree[xPrime][yPrime] * exp(-(pow(i, 2)+pow(j,2))/(2*pow(sigm,2)));
	  sortie[x][y] += tmp;
	}
      }
    }
  }
}

	/* 
		Exemple de code avec Entrees Sortie et transformations simples d'images
		S'utilise sous la forme  "exemple tangram.pgm res.pgm"
 	*/
int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
  int nb,nl,nc, oldnl,oldnc;
  unsigned char **im2=NULL,** im1=NULL;
  double** im4,** im5, ** im6, ** im7, **im8, **im9,**im10;
  double sigm = 2 /* valeur du lissage */;
  int w = 4; /* taille du filtre */

  if (ac < 3) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
	/* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }

  double**im3=imuchar2double(im1,nl,nc);
  oldnl=nl; oldnc=nc;

  /* Creation d'images pour l'application du filtre */
  im4=alloue_image_double(nl,nc);

  /* filtrage im3 */  
  filtrage(im3, im4, sigm, w, nl, nc);

  ecritureimagepgm(av[2],crop(imdouble2uchar(im4,nl,nc),0,0,oldnl,oldnc),oldnl,oldnc);
}

