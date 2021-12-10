#include "backsubst.h"
/**
	* Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
	* Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
	* Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
*/
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int w; // wiersz
	int k; // kolumna
	
	if (mat->r != b->r || mat->r != x->r || mat->c != x->r)
		return 2;
	
	for( w = mat->r - 1 ; w >= 0; w-- ) {
		double s = 0;
		for( k = w + 1; k < mat->c; k++ )
			s += mat->data[w][k] * x->data[k][0];
		
		double elem_na_diagon = mat->data[w][w];
		
		if (elem_na_diagon == 0)
			return 1;
		
		x->data[w][0] = ( b->data[w][0] - s ) / elem_na_diagon;
	}
	

	return 0;
}


