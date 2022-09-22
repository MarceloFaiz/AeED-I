/*
12. Faça um programa que leia três valores inteiros e chame uma função que receba estes 3
valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variável,
o segundo menor valor na variável do meio, e o maior valor na última variável. A função
deve retornar o valor 1 se os três valores forem iguais e 0 se existirem valores diferentes.
Exibir os valores ordenados na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int Sort ( int *A, int *B, int *C );

int main () {
    int iA, iB, iC, iRet;

    printf ( "Digite um valor para a primeira variável: " );
    scanf ( "%d", &iA );
    printf ( "Digite um valor para a segunda variável: " );
    scanf ( "%d", &iB );
    printf ( "Digite um valor para a terceira variável: " );
    scanf ( "%d", &iC );

    iRet = Sort ( &iA, &iB, &iC );

    if ( iRet == 0 ) {
        printf ( "Valores após ordenamento: %d, %d e %d! ", iA, iB, iC );
    } else {
        printf ( "Os três valores digitados são iguais! " );
    }
    
    return 0;
}

int Sort ( int *A, int *B, int *C ) {
    int iTemp;

    if ( *A == *B && *B == *C) {
        return 1;
    } else {
        if ( *A >= *B && *B >= *C ) {
            iTemp = *A;
            *A = *C;
            *C = iTemp;

            return 0;
        } else if ( *A >= *C && *C >= *B ) {
            iTemp = *A;
            *A = *B;
            *B = *C;
            *C = iTemp;

            return 0;
        } else if ( *B >= *A && *A >= *C ) {
            iTemp = *B;
            *B = *A;
            *A = *C;
            *C = iTemp;

            return 0;
        } else if ( *B >= *C && *C >= *A ) {
            iTemp = *B;
            *B = *C;
            *C = iTemp;

            return 0;
        } else if ( *C >= *A && *A >= *B ) {
            iTemp = *A;
            *A = *B;
            *B = iTemp;

            return 0;
        } else if ( *C >= *B && *B >= *A ) {
            return 0;
        }
    }
}