#include <stdio.h>
#include <stdlib.h>

int *pVetor;

int main () {
	int iTamanho;
	
	printf ( "Digite qual sera o tamanho do vetor: " );
	scanf ( "%d", &iTamanho );

	pVetor = ( int * ) malloc ( sizeof ( int ) * iTamanho );

	free ( pVetor );

	return ( 0 );
}









