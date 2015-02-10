#include "pgm.h"
#include "etirement.h"

/* etirement de l'histogramme */

unsigned char** etire( unsigned char** sortie,  unsigned char** entree, int nl, int nc){
    if (sortie==NULL) sortie=alloue_image(nl,nc);
    int i;
    int j;
    int mine = min(entree);
    int maxe = max(entree);
    for(i=0; i<nl; i++)
	for(j=0; j<nc; j++)
	    sortie[i][j]=255*(entree[i][j]-mine)/(maxe - mine);
    return sortie;
}

unsigned char min(unsigned char** entree){
    char min = entree[0][0];
    int i;
    int j;
    for(i = 0 ; i < 255 ; i++){
	for(j = 0 ; j < 255 ; j++){
	    if(min > entree[i][j])
		min = entree[i][j];
	}
    }
    return min;
}


unsigned char max(unsigned char** entree){
    char max = entree[0][0];
    int i;
    int j;
    for(i = 0 ; i < 255 ; i++){
	for(j = 0 ; j < 255 ; j++){
	    if(max < entree[i][j])
		max = entree[i][j];
	}
    }
    return max;
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
  im2=etire(im2,im1,nl,nc);
	/* Sauvegarde dans un fichier dont le nom est passe sur la ligne de commande */
  ecritureimagepgm(av[2],im2,nl,nc);

}
