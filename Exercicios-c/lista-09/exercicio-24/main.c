/*
24. Escreva uma função que receba um array de inteiros V e os endereços de duas variáveis
inteiras, min e max, e armazene nessas variáveis o valor mínimo e máximo do array.
Escreva também uma função main que use essa função.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int iArray [ 10 ] = { 5, 3, 7, 2, 4, 8, 1, 10, 9, 15 }, iMin, iMax;

    NumExtract ( iArray, &iMin, &iMax );

    printf ( "O maior valor do vetor é %d. O mínimo é %d. ", iMax, iMin );
    
    return 0;
}

void NumExtract ( int *Array, int *Min, int *Max ) {
    int i;

    *Max = *( Array + 0 );
    *Min = *( Array + 0 );

    for ( i = 0; i < 10; i++ ) {
        if ( *Max < *( Array + i ) ) {
            *Max = *( Array + i );
        }

        if ( *Min > *( Array + i ) ) {
            *Min = *( Array + i ); 
        }
    }
}