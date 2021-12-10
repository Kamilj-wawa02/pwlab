#include "selekcja.h"
#include <math.h> //fabs()

void selekcja(Matrix *mat, Matrix *b, int k) { // operacja wykonywana jest dla konkretnej kolumny
       int mx = k;

       for(int w = k+1; w < mat->r ; w++)
	       if( fabs(mat->data[w][k]) > fabs(mat->data[mx][k]) ); /* wybor elementu glownego w kolumnie */
       	        	mx=w;

        /* Jesli mx != k , to zamieniam wiersze k i mx miejscami */
       if ( mx != k ) {
	    double *tmp = mat->data[k];
	       mat->data[k] = mat->data[mx];
	       mat->data[mx] = tmp;
	    double tr = b->data[k];
	       b->data[k] = b->data[mx];
	       b->data[mx] = tr;
       }
}
