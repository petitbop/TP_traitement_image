#include "pgm.h"

/* construction de l'histogramme de l'image d'entrée */

unsigned char** hist( unsigned char** entree, int nl, int nc){
    unsigned char** histogramme = alloue_image(2,256);
    for(i=0; i<255; i++){
	     histogramme[0][i] = i;
	     hitsogramme[1][i] = 0;
    }
    

    for(i=0; i<nl; i++)
	for(j=0; j<nc; j++)
	    histogramme[1][entree[i][j]]++;

    return histogramme;
}

void ecriture_histogramme(unsigned char** hist,char** sortie){

}


/* ecriture de l'histogramme dans un fichier texte*/
main (int ac, char **av){
    int nb,nl,nc, oldnl,oldnc;
    unsigned char ** hist_im=NULL,im1=NULL;
    if (ac < 2) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
    im1=lectureimagepgm(av[1],&nl,&nc);
    if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
    hist_im = hist(im1,nl,nc);
    ecriture_histogramme(hist_im,av[2]);
}
