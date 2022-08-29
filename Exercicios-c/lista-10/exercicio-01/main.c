/*
1. Crie um programa que:
(a) Aloque dinamicamente um array de 5 números inteiros,
(b) Peça para o usuário digitar os 5 números no espaço alocado,
(c) Mostre na tela os 5 números,
(d) Libere a memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int i, *aVetor, *aVetorCopia;

    aVetor = ( int * ) malloc ( sizeof ( int ) * 5 );

    aVetorCopia = aVetor;

    printf ( "Digite 5 numeros: " );

    for ( i = 0; i < 5; i++ ) {
        scanf ( "%d", &aVetor[i]);
    }

    for ( i = 0; i < 5; i++ ) {
        printf ( "%d\n", aVetor[i]);
    }

    free ( aVetorCopia );

    return 0;
}