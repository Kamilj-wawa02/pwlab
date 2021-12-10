#include "selekcja.h"
#include <math.h> //fabs()


void selekcja(Matrix *mat, Matrix *b, int c) { // operacja wykonywana jest dla konkretnej kolumny

        int elem = c;
        for(int w = c + 1 ; w < mat->r; w++) { // sprawdzamy jedynie wiersze od diagonali w dół
                if (fabs(mat->data[w][c]) > fabs(mat->data[elem][c]))
                        elem = w;
        }

	/* Jesli elem != c , to zamieniam wiersze c i elem miejscami */
        if (elem != c) {
                double *tmp = mat->data[c];
                mat->data[c] = mat->data[elem];
                mat->data[elem] = tmp;

                double tr = b->data[k];
                b->data[c] = b->data[elem];
                b->data[elem] = tr;
        }

}
