/*
11. Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o endereço das posições contendo valores pares.
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
        if ( *( iArray+i ) % 2 == 0 ) {
            printf ( "%dº Endereço: %p\n", i+1, &iArray+i );
        }
    }
    
    return 0;
}