/*
9. Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
Imprima o endereço de cada posição dessa matriz.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float fMatrix [3] [3];
    int i, j;

    for ( i = 0; i < 3; i++ ) {
        for ( j = 0; j < 3; j++ ) {
            printf ( "\t%p\t", &fMatrix [i] [j] );
        }
        printf ( "\n\n" );
    }
  
    return 0;
}