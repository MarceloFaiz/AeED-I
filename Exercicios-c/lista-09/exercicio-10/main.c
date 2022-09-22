/*
10. Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando
apenas aritmética de ponteiros, leia esse array do teclado e imprima o dobro de cada
valor lido.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int iArray [5];

    printf ( "Digite 5 valores para o vetor: " );

    for ( int i = 0; i < 5; i++ ) {
        scanf ( "%d", iArray+i );
    }

    for ( int i = 0; i < 5; i++ ) {
        printf ( "%dº Elemento dobrado: %d \n", i + 1, *( iArray+i ) + *( iArray+i ) );
    }
    
    return 0;
}