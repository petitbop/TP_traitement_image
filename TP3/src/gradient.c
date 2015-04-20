#include "pgm.h"
#include "gradient.h"

void convol(double ** entree, double** sortie, int** filtre, int w, int nl,int nc){
  double tmp = 0;
  // on parcourt l'image
  for(int x = 0; x < nl; x++){
    for(int y = 0; y < nc; y++){
      sortie[x][y] = 0;
      // on fait la convolution
      for(int i = -w/2; i <= w/2; i++){
	for(int j = -w/2; j <= w/2; j++){
	  // l'image est periodisee
	  int xPrime = (x+i) % nl;
	  if (xPrime < 0){
	    xPrime += nl;
	  }
	  int yPrime = (y+j) % nc;
	  if (yPrime < 0){
	    yPrime += nc;
	  }
	  tmp = filtre[i+1][j+1] * entree[xPrime][yPrime]; //bidouille immonde
	  sortie[x][y] += tmp;
	}
      }
    }
  }
}

double interpolGrad(double** G, int i, int j, double di, double dj){
  double res;
  if(di > 0 && dj > 0){
    res = (1-di)*(1-dj)*G[i][j] + di*(1-dj)*G[i+1][j] + 
      (1-di)*dj*G[i][j+1] + di*dj*G[i+1][j+1];
  }
  else if(di > 0 && dj < 0){
    res = (1-di)*(dj - 1)*G[i][j] + di*(dj - 1)*G[i+1][j] + 
      (1-di)*(-dj)*G[i][j-1] + di*(-dj)*G[i+1][j-1];
  }
  else if (di < 0 && dj > 0){
    res = (di - 1)*(1-dj)*G[i][j] + (-di)*(1-dj)*G[i-1][j] + 
      (di - 1)*dj*G[i][j+1] + (-di)*dj*G[i-1][j+1];
  }
  else{  
    res = (di - 1)*(dj - 1)*G[i][j] + -di*(dj - 1)*G[i-1][j] + 
      (di-1)*(-dj)*G[i][j-1] + (-di)*(-dj)*G[i-1][j-1];  
  }
  return res;
}

void supMaxima(double** GX, double** GY, double** G, unsigned char** contour, int nl, int nc){
  double theta; // angle de la direction du gradient
  double diP1; // distance sur l'axe des abscisses du point courant au point P1
  double djP1; // distance sur l'axe des ordonnées du point courant au point P1
  double diP2; // distance sur l'axe des ordonnées du point courant au point P2
  double djP2; // distance sur l'axe des ordonnées du point courant au point P2
  double G1; // valeur de la norme du gradient en P1
  double G2; // valeur de la norme du gradient en P2
  for(int i = 2; i < nl-1; i++){
    for(int j = 2; j < nc-1; j++){
      theta = atan2(GY[i][j], GX[i][j]);
      diP1 = cos(theta);
      djP1 = sin(theta);
      diP2 = cos(theta + M_PI);
      djP2 = sin(theta + M_PI);

      G1 = interpolGrad(G, i, j, diP1, djP1);
      G2 = interpolGrad(G, i, j, diP2, djP2);

      if(G[i][j] < G1 || G[i][j] < G2){
	contour[i][j] = 120; // valeur intermédiaire pour aider au filtrage
      }
      else{
	contour[i][j] = 0;
      }
    }
  }
}

void seuillage(double** G, unsigned char** contour, int nl, int nc, double seuilMin, double seuilMax){
  for(int i = 1; i < nl-1; i++){
    for(int j = 1; j < nc-1; j++){
      if(contour[i][j] = 255){ // on est dans un potentiel contour
	if(G[i][j] > seuilMax){
	  contour[i][j] = 255;
	}
	else if(G[i][j] < seuilMin){
	  contour[i][j] = 0; // c'était du bruit
	} 
	else{ // on regarde si l'un des 8 voisins de (i,j) est un VRAI contour
	  if(G[i-1][j-1] == 255 ||G[i-1][j] == 255 ||G[i-1][j+1] == 255 ||
	     G[i][j-1] == 255 ||G[i][j+1] == 255 ||G[i+1][j-1] == 255 ||
	     G[i+1][j+1] == 255 ||G[i+1][j+1] == 255){
	    contour[i][j] = 255;
	  }
	  else{
	    contour[i][j] = 0;
	  }
	}
      }
    }
  }
}

double norm(double x, double y){
  return sqrt(x*x + y*y);
}

void normMatrix(double ** MX, double** MY, double ** M, int nl, int nc){
  for(int i = 0; i < nl; i++){
    for(int j = 0; j < nc; j++){
      M[i][j] = norm(MX[i][j], MY[i][j]);
    }
  }
}

double average(double** M, int nl, int nc){
  double res = 0;
  for(int i = 0; i < nl; i++){
    for(int j = 0; j < nc; j++){
      res = res + M[i][j];
    }
  }
  res = res/(nl*nc);
  return res;
}


int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
  double seuilMax = 500; // varie selon l'image...
  double seuilMin = 20; // varie selon l'image...
  int nb,nl,nc, oldnl,oldnc;
  int w = 3;
  int** filtrePrewitt;
  filtrePrewitt = malloc(w*sizeof(int));
  for(int i = 0; i < w; i++){
    filtrePrewitt[i] = malloc(w*sizeof(int));
  }
  filtrePrewitt[0][0] = -1;
  filtrePrewitt[0][1] = 0;
  filtrePrewitt[0][2] = 1;
  filtrePrewitt[1][0] = -1;
  filtrePrewitt[1][1] = 0;
  filtrePrewitt[1][2] = 1;
  filtrePrewitt[2][0] = -1;
  filtrePrewitt[2][1] = 0;
  filtrePrewitt[2][2] = 1;

  int** filtrePrewittTranspose;
  filtrePrewittTranspose = malloc(w*sizeof(int));
  for(int i = 0; i < w; i++){
    filtrePrewittTranspose[i] = malloc(w*sizeof(int));
  }
  filtrePrewittTranspose[0][0] = -1;
  filtrePrewittTranspose[0][1] = -1;
  filtrePrewittTranspose[0][2] = -1;
  filtrePrewittTranspose[1][0] = 0;
  filtrePrewittTranspose[1][1] = 0;
  filtrePrewittTranspose[1][2] = 0;
  filtrePrewittTranspose[2][0] = 1;
  filtrePrewittTranspose[2][1] = 1;
  filtrePrewittTranspose[2][2] = 1;

  int** filtreSobel;
  filtreSobel = malloc(w*sizeof(int));
  for(int i = 0; i < w; i++){
    filtreSobel[i] = malloc(w*sizeof(int));
  }
  filtreSobel[0][0] = -1;
  filtreSobel[0][1] = 0;
  filtreSobel[0][2] = 1;
  filtreSobel[1][0] = -2;
  filtreSobel[1][1] = 0;
  filtreSobel[1][2] = 2;
  filtreSobel[2][0] = -1;
  filtreSobel[2][1] = 0;
  filtreSobel[2][2] = 1;

  int** filtreSobelTranspose;
  filtreSobelTranspose = malloc(w*sizeof(int));
  for(int i = 0; i < w; i++){
    filtreSobelTranspose[i] = malloc(w*sizeof(int));
  }
  filtreSobelTranspose[0][0] = -1;
  filtreSobelTranspose[0][1] = 2;
  filtreSobelTranspose[0][2] = -1;
  filtreSobelTranspose[1][0] = 0;
  filtreSobelTranspose[1][1] = 0;
  filtreSobelTranspose[1][2] = 0;
  filtreSobelTranspose[2][0] = 1;
  filtreSobelTranspose[2][1] = 2;
  filtreSobelTranspose[2][2] = 1;

  unsigned char **im2=NULL,** im1=NULL;
  double** GX,** GY; // les deux coordonnées du vecteur G gradient
  double** im4,** im5, ** im6, ** im7, **im8, **im9,**im10;
  
  if (ac < 3) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
	/* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }

  double**im3=imuchar2double(im1,nl,nc); // im3 contient l'image initiale
  // Calcul de la norme du gradient et des ses composantes
  GX = alloue_image_double(nl, nc);
  GY = alloue_image_double(nl, nc);
  if(av[3] = 0){
  convol(im3, GX, filtrePrewitt, w, nl, nc); 
  convol(im3, GY, filtrePrewittTranspose, w, nl, nc); 
  }
  else{
  convol(im3, GX, filtreSobel, w, nl, nc); 
  convol(im3, GY, filtreSobelTranspose, w, nl, nc); 
  }
  double** G;
  G = alloue_image_double(nl, nc);
  normMatrix(GX, GY, G, nl, nc);
  
  im2 = alloue_image(nl, nc);

  // Suppression des points non maxima
  supMaxima(GX, GY, G, im2, nl, nc);

  // Seuillage par hystéresis
  seuillage(G, im2, nl, nc, seuilMin, seuilMax);

  double res = average(G, nl, nc);
  printf("%lf \n", res);

	/* Sauvegarde dans un fichier dont le nom est passe sur la ligne de commande */
  ecritureimagepgm(av[2],im2,nl,nc);
}
