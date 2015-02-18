#include "pgm.h"
#include <stdlib.h>
#include <stdio.h>

/* construction de l'histogramme de l'image d'entrée */

int** hist( unsigned char** entree, int nl, int nc){
    int ** histogramme = calloc(2,sizeof(int*));
    histogramme[0] = calloc(256,sizeof(int));
    histogramme[1] = calloc(256,sizeof(int));
    int i;
    int j;
    for(i=0; i<256; i++){
	histogramme[0][i] = i;
	histogramme[1][i] = 0;
    }
    

    for(i=0; i<nl; i++)
	for(j=0; j<nc; j++)
	    histogramme[1][entree[i][j]]++;

    return histogramme;
}

void ecriture_histogramme(int** hist,char** sortie){
    FILE* fichier = fopen(*sortie, "w");
    int i;
    for(i = 0 ; i < 256 ; i ++){
	fprintf(fichier,"%i ", hist[0][i]);
	fprintf(fichier,"%i \n" ,hist[1][i]);
    }
    fclose(fichier);
}

