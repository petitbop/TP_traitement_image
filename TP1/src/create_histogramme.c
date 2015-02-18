#include "pgm.h"
#include "histogramme.h"
#include <stdlib.h>
#include <stdio.h>

/* ecriture de l'histogramme dans un fichier texte*/
int main (int ac, char **av){
    int nb,nl,nc, oldnl,oldnc;
    int **hist_im = NULL;
    unsigned char **im1 = NULL;
    if (ac < 2) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
    im1=lectureimagepgm(av[1],&nl,&nc);
    if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
    hist_im = hist(im1,nl,nc);
    ecriture_histogramme(hist_im,&av[2]);
    // faire les free
}
