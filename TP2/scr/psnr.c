#include "psnr.h"
#include "math.h"
double psnr(double** entree, double** sortie, int nl, int nc){
  double eqm = 0;
  for(int i = 0 ; i < nl ; i++){
    for(int j = 0 ; j < nc ; j++){
      eqm += pow(entree[i][j] - sortie[i][j],2);
    }
  }
  eqm /= nl*nc;
  return 10*log10(255*255/eqm);
}
