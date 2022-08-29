/*
2. Faça um programa que leia do usuário o tamanho de um vetor a ser lido e faça a alocação
dinâmica de memória. Em seguida, leia do usuário seus valores e imprima o vetor lido.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int i, iTamanho = 7;
    char *cNome, *cNomeCopia;

    //printf ( "Qual e o tamanho do vetor? " );
    //scanf ( "%d", &iTamanho );

    cNome = ( char * ) malloc ( sizeof ( char ) * iTamanho );

    printf ( "Digite %d letra(s): ", iTamanho );

    for ( i = 0; i < iTamanho; i++ ) {
        scanf ( "%d", i);

    }

    printf ( "%s", cNome);
    
    return 0;
}