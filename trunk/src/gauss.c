#include <stdio.h>
#include "gauss.h"
#include "selekcja.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){


        for( int k = 0 ; k < mat->r - 1; k++) {
		  selekcja(mat, b, k);
          for(int w = k+1 ; w < mat->r; w++) {
               if( mat->data[k][k] == 0 )
                        return 1;
               double q = mat->data[w][k] / mat->data[k][k];
               for( int i = k ; i < mat->c ; ++i)
                    mat->data[w][i] -= q * mat->data[k][i];
               b->data[w][0] -= q * b->data[k][0];
           }
        }
        return 0;

}

