#include "pgm.h"
#include "convolGaussian.h"
#include "math.h"

/*
void filtrage_horizontale(double ** sortie_re,double **sortie_im,double ** entree_re,double **entree_im, double sigm, int w, int nl,int nc){
  double tmp = 0;
  // on parcourt l'image
  for(int x = 0; x < nl; x++){
    for(int y = 0; y < nc; y++){
      	sortie_re[x][y] = 0;
	sortie_im[x][y] = 0;
      // on fait la convolution horizontale
      for(int j = -w; j <= w; j++){
	// l'image est periodisee
	int yPrime = (y-j) % nc;
	tmp = 1/(2*M_PI * pow(sigm, 2))*entree_re[x][yPrime] * exp(-pow(j, 2)/(2*pow(sigm,2)));
	sortie_re[x][y] += tmp;

	tmp = 1/(2*M_PI * pow(sigm, 2)) * entree_im[x][yPrime] * exp(-pow(j, 2)/(2*pow(sigm,2)));
	sortie_im[x][y] += tmp;
      }
    }
  }
}
*/
void filtrage_horizontal(double ** entree,double ** sortie, double sigm, int w, int nl,int nc){
  double tmp = 0;
  // on parcourt l'image
  for(int x = 0; x < nl; x++){
    for(int y = 0; y < nc; y++){
      	sortie[x][y] = 0;
      // on fait la convolution horizontale
      for(int j = -w; j <= w; j++){
	// l'image est periodisee
	int yPrime = (y-j) % nc;
	if (yPrime < 0){
	  yPrime += nc;
	}
	tmp = 1/(2*M_PI * pow(sigm, 2))*entree[x][yPrime] * exp(-pow(j, 2)/(2*pow(sigm,2)));
	sortie[x][y] += tmp;
      }
    }
  }
}

/*
void filtrage_vertical(double ** entree_re,double **entree_im, double** sortie_re, double** sortie_im,double sigm, int w, int nl,int nc){
  double tmp = 0;
  // on parcourt l'image
  for(int x = 0; x < nl; x++){
    for(int y = 0; y < nc; y++){
        sortie_re[x][y] = 0;
	sortie_im[x][y] = 0;
      // on fait la convolution verticale
      for(int i = -w; i <= w; i++){
	// l'image est periodisee
	int xPrime = (x-i) % nl;
	tmp = 1/(2*M_PI * pow(sigm, 2)) * entree_re[xPrime][y] * exp(-pow(i, 2)/(2*pow(sigm,2)));
	sortie_re[x][y] += tmp;

	tmp = 1/(2*M_PI * pow(sigm, 2)) * entree_im[xPrime][y] * exp(-pow(i, 2)/(2*pow(sigm,2)));
	sortie_im[x][y] += tmp;
      }
    }
  }
}
*/

void filtrage_vertical(double ** entree, double** sortie,double sigm, int w, int nl,int nc){
  double tmp = 0;
  // on parcourt l'image
  for(int x = 0; x < nl; x++){
    for(int y = 0; y < nc; y++){
        sortie[x][y] = 0;
      // on fait la convolution verticale
      for(int i = -w; i <= w; i++){
	// l'image est periodisee
	int xPrime = (x-i) % nl;
	if (xPrime < 0){
	  xPrime += nl;
	}
	// la normalisation est faite deux fois sinon
	tmp = //1/(2*M_PI * pow(sigm, 2)) * 
	  entree[xPrime][y] * exp(-pow(i, 2)/(2*pow(sigm,2)));
	sortie[x][y] += tmp;
      }
    }
  }
}

	/* 
		Exemple de code avec Entrees Sortie et transformations simples d'images
		S'utilise sous la forme  "exemple tangram.pgm res.pgm"
 	*/
main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
  int nb,nl,nc, oldnl,oldnc;
  unsigned char **im2=NULL,** im1=NULL;
  double** im4,** im5, ** im6, ** im7, **im8, **im9,**im10;
  double sigm = 2 /* valeur du lissage */;
  int w = 4; /* taille du filtre */

  if (ac < 3) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
	/* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
	/* Calcul de son inverse video */
  double**im3=imuchar2double(im1,nl,nc);
  oldnl=nl; oldnc=nc;

  /* Creation d'images pour l'application des filtres */
  im4=alloue_image_double(nl,nc); im5=alloue_image_double(nl,nc); im6=alloue_image_double(nl,nc);

  /* filtrage horizontale applique a l'image im3 */  
  filtrage_horizontal(im3, im4, sigm, w, nl, nc);

  /* filtrage verticale applique au resultat du filtrage horizontale */
  filtrage_vertical(im4, im5, sigm, w, nl, nc);  

  ecritureimagepgm(av[2],crop(imdouble2uchar(im5,nl,nc),0,0,oldnl,oldnc),oldnl,oldnc);
}

