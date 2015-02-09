#include "pgm.h"


/* etirement de l'histogramme */

unsigned char** etire( unsigned char** sortie,  unsigned char** entree, int nl, int nc){
    if (sortie==NULL) sortie=alloue_image(nl,nc);
    for(i=0; i<nl; i++)
	for(j=0; j<nc; j++)
	    sortie[i][j]=255*(entree[i][j]-min(entree))/(max(entree) - min(entree));
    return sortie;
}
