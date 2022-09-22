/*
4. Faça um programa que leia 2 valores inteiros e chame uma função que receba estas
2 variáveis e troque o seu conteúdo, ou seja, esta função é chamada passando duas
variáveis A e B por exemplo e, após a execução da função, A conterá o valor de B e B
terá o valor de A.
*/

#include <stdio.h>
#include <stdlib.h>

int ChangeValue ( int *A, int *B );

int main () {
    int iVar1, iVar2;

    printf ( "Digite o valor da variável \"A\": " );
    scanf ( "%d", &iVar1 );
    printf ( "Agora, digite o valor da variável \"B\": " );
    scanf ( "%d", &iVar2 );

    ChangeValue ( &iVar1, &iVar2 );

    printf ( "Realizando a troca, os valores das variáveis A e B são, respectivamente: %d e %d!", iVar1, iVar2 );

    return 0; 
}

int ChangeValue ( int *A, int *B ) {
    int iTemp;

    iTemp = *B;
    *B = *A;
    *A = iTemp;

}