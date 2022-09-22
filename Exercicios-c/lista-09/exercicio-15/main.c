/*
15. Crie uma função que receba como parâmetro um array e o imprima. Não utilize índices
para percorrer o array, apenas aritmética de ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int iArray [5] = { 2, 4, 6, 8, 0 };

    PrintArray ( iArray );
    
    return 0;
}

void PrintArray ( int *Array ) {
    int i;

    for ( i = 0; i < 5; i++ ) {
        printf ( "%dº elemento do vetor: %d \n", i + 1, *( Array + i ) );
    }
}