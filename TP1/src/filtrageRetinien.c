#include "pgm.h"
#include "filtrageRetinien.h"


// scan retinien

unsigned char** filtrageRetinien(unsigned char** sortie, unsigned char** entree,
				 int nl, int nc){

    if (sortie==NULL) sortie=alloue_image(nl,nc);
    int i; // indices permettant le parcours des matrices
    int j;
    int n = 3; // taille du voisinage
    float alpha = 0.5;
    int entreeMoy = moy(nl, nc, entree);
    int mij = 0;

    for(i = 0; i < nl; i++){
      for(j = 0; j < nc; j++){
	mij = moyVoisin(i, j, n, nl, nc, entree);
	sortie[i][j] = entree[i][j]*((255 + mij + alpha * entreeMoy)/(entree[i][j] + mij + alpha * entreeMoy));
      }
    }
    return sortie;
}

int moyVoisin(int i, int j, int n, int nl, int nc, unsigned char** entree){

  int mij = 0;
  int tmp = 0;

  for(int k = -n; k <= n; k++){
    for(int l = -n; l <= n; l++){
      // on verifie qu'on considere des voisins de i j qui existent
      if(i+k >= 0 && i+k <= nl-1 && j+l >= 0 && j+l <= nc - 1){
	tmp += entree[i+k][j+l];
      }
    }
  }
  mij = tmp/(pow(2*n+1, 2));
  return mij;
}

int moy(int nl, int nc, unsigned char** entree){

  int entreeMoy = 0;
  int tmp = 0;

  for(int l = 0; l <= nc - 1; l++){
    for(int k = 0; k <= nl - 1; k++){
      tmp += entree[k][l];
    }
  }
  entreeMoy = tmp/(nl * nc);
  return entreeMoy;
}



int main (int ac, char **av) {  /* av[1] contient le nom de l'image, av[2] le nom du resultat . */
  int nb,nl,nc, oldnl,oldnc;
  unsigned char **im2=NULL,** im1=NULL;
  double** im4,** im5, ** im6, ** im7, **im8, **im9,**im10;
  
  if (ac < 2) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
	/* Lecture d'une image pgm dont le nom est passe sur la ligne de commande */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
	/* Calcul de son inverse video */
  im2=filtrageRetinien(im2,im1,nl,nc);
	/* Sauvegarde dans un fichier dont le nom est passe sur la ligne de commande */
  ecritureimagepgm(av[2],im2,nl,nc);

}
