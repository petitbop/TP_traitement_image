#include "median.h"
#include "pgm.h"

int** hist( unsigned char** entree, int i, int j, int N, int nl, int nc){
    int** histogramme = calloc(2,sizeof(int*));
    histogramme[0] = calloc(256,sizeof(int));
    histogramme[1] = calloc(256,sizeof(int));
    int k;
    int l;
    for(k=0; k<256; k++){
	histogramme[0][k] = k;
	histogramme[1][k] = 0;
    }
    

    for(k = i - N; k < i + N; k++)
	for(l = j - N; l < j + N; l++)
	    histogramme[1][entree[k][l]]++;

    return histogramme;
}

int majHist(int** histogramme, int N){
  int k = 0;
  int tmp = histogramme[1][0];
  while(tmp < 2*N*N + 2*N){
    k++;
    tmp += histogramme[1][k];
  }
  return k;
}

void median(unsigned char** entree, unsigned char** sortie, int N, int nl, int nc){
  int** histogramme;
  for(int i = N; i < nl - N; i++){
    // calculer l'histogramme d'une fenêtre 2N+1 * 2N+1 autour du point d'indices i,N
    histogramme = hist(entree, i, N, N, nl, nc);
    // la valeur du nouveau point est déterminée par la valeur k
    sortie[i][N] = majHist(histogramme, N);

    for(int j = N + 1 ; j < nc - N; j++){
      // supprimer de l'histogramme les valeurs des points de la colonne j-N-1
      // ajouter à l'histogramme les valeurs des points de la colonne j+N
      histogramme = hist(entree, i, j, N, nl, nc);

      // la nouvelle valeur du point k:
      sortie[i][j] = majHist(histogramme, N);
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
  unsigned char** im4,** im5, ** im6, ** im7, **im8, **im9,**im10;
  int N = 14; /* taille de la fenetre a prendre en consideration lors
		du calcul de la valeur mediane */
   
  
  if (ac < 3) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
	/* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
	/* Calcul de son inverse video */
  //double**im3=imuchar2double(im1,nl,nc);
  oldnl=nl; oldnc=nc;

  im4=alloue_image(nl,nc);
  median(im1, im4, N, nl, nc);

	/* Conversion en entier8bits de la partie reelle de la fftinverse, 
	   Suppresion des 0 qui ont servi a completer en utilisant la fonction crop
	   Sauvegarde au format pgm de cette image qui doit etre identique a 'linverse video 
	   car on a realise la suite fftinv(fft(image))*/
  ecritureimagepgm(av[2], im4,oldnl,oldnc);
}



