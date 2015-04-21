#include "laplacien.h"

void convol(unsigned char ** entree, double** sortie, int** filtre, int nl,int nc){
  // on parcourt l'image
  for(int x = 0; x < nl; x++){
    for(int y = 0; y < nc; y++){
      sortie[x][y] = 0;
      for(int i = 0; i <= 2; i++){
	for(int j = 0; j <= 2; j++){
	  // on périodise l'image
	  int xPrime = (x-i+nl) % nl;
	  int yPrime = (y-j+nc) % nc;
	  sortie[x][y] += entree[xPrime][yPrime]*filtre[i][j];
	}
      }    
    }
  }
}

int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
  int typeLaplacien;
  int nb,nl,nc, oldnl,oldnc;
  int w = 3;

  int** laplacien1;
  laplacien1 = malloc(w*sizeof(int));
  for(int i = 0; i < w; i++){
    laplacien1[i] = malloc(w*sizeof(int));
  }
  laplacien1[0][0] = 0;
  laplacien1[0][1] = 1;
  laplacien1[0][2] = 0;
  laplacien1[1][0] = 1;
  laplacien1[1][1] = -4;
  laplacien1[1][2] = 1;
  laplacien1[2][0] = 0;
  laplacien1[2][1] = 1;
  laplacien1[2][2] = 0;

  int** laplacien2;
  laplacien2 = malloc(w*sizeof(int));
  for(int i = 0; i < w; i++){
    laplacien2[i] = malloc(w*sizeof(int));
  }
  laplacien2[0][0] = 1;
  laplacien2[0][1] = 1;
  laplacien2[0][2] = 1;
  laplacien2[1][0] = 1;
  laplacien2[1][1] = -8;
  laplacien2[1][2] = 1;
  laplacien2[2][0] = 1;
  laplacien2[2][1] = 1;
  laplacien2[2][2] = 1;

  int** laplacien3;
  laplacien3 = malloc(w*sizeof(int));
  for(int i = 0; i < w; i++){
    laplacien3[i] = malloc(w*sizeof(int));
  }
  laplacien3[0][0] = -1;
  laplacien3[0][1] = 2;
  laplacien3[0][2] = -1;
  laplacien3[1][0] = 2;
  laplacien3[1][1] = -4;
  laplacien3[1][2] = 2;
  laplacien3[2][0] = -1;
  laplacien3[2][1] = 2;
  laplacien3[2][2] = -1;

  unsigned char **im2=NULL,** im1=NULL;
  double** laplacien; // les valeurs du Laplacien
  double** im4,** im5, ** im6, ** im7, **im8, **im9,**im10;
  
  if (ac < 3) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
  /* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }

  laplacien = alloue_image_double(nl, nc);
  im2 = alloue_image(nl, nc);

  typeLaplacien = atoi(av[3]);  

  if(typeLaplacien == 0){
    convol(im1, laplacien, laplacien1, nl, nc);  
  }
  else if( typeLaplacien == 1){
    convol(im1, laplacien, laplacien2, nl, nc); 
  }
  else{
    convol(im1, laplacien, laplacien3, nl, nc); 
  }



  /*
  double res = average(G, nl, nc);
  printf("%lf \n", res);*/

  /* Sauvegarde dans un fichier dont le nom est passe sur la ligne de commande */
  ecritureimagepgm(av[2], crop(imdouble2uchar(laplacien,nl,nc),0,0,nl,nc), nl,nc);
}
