/*
14. Crie uma função que receba dois parâmetros: um array e um valor do mesmo tipo do
array. A função deverá preencher os elementos de array com esse valor. Não utilize
índices para percorrer o array, apenas aritmética de ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int iNum, i, iArraySize;

    printf ( "Qual será o tamanho do vetor? " );
    scanf ( "%d", &iArraySize );

    int iArray [iArraySize];

    printf ( "Escolha um número para preencher as posições do vetor: " );
    scanf ( "%d", &iNum);

    FillArray ( iArray, iNum, iArraySize );

    for ( i = 0; i < iArraySize; i++ ) {
        printf ( "%dº Elemento do vetor: %d \n", i + 1, *( iArray + i ) );
    }
    
    return 0;
}

void FillArray ( int *Array, int Num, int ArraySize ) {
    int i;

    for ( i = 0; i < ArraySize; i++ ) {
        *( Array + i ) = Num;
    }

}