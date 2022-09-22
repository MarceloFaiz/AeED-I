/*
20. Implemente uma função que receba como parâmetro um array de números reais de
tamanho N e retorne quantos números negativos há nesse array. Essa função deve
obedecer ao protótipo:

int negativos ( float *vet, int N );
*/

#include <stdio.h>
#include <stdlib.h>

int negativos ( float *vet, int N );

int main () {
    float fArray [10] = { 3.14, -5, 1.41, -2, 5.95, -7, 1.23, -3.14, 8.0, -125 };
    int iQtd, iNum;

    iQtd = negativos ( fArray, iNum );

    printf ( "A quantidade de números negativos no vetor é: %d", iQtd );
    
    return 0;
}

int negativos ( float *vet, int N ) {
    int i;

    for ( i = 0; i < 10; i++ ) {
        if ( *( vet + i ) < 0 ) {
            N++;
        }
    }

    return N;
}