/*
5. Faça um programa que leia dois valores inteiros e chame uma função que receba estes
2 valores de entrada e retorne o maior valor na primeira variável e o menor valor na
segunda variável. Escreva o conteúdo das 2 variáveis na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int VariableSort ( int *A, int *B );

int main () {
    int iVar1, iVar2;

    printf ( "Digite o valor da variável \"A\": " );
    scanf ( "%d", &iVar1 );
    printf ( "Agora, digite o valor da variável \"B\": " );
    scanf ( "%d", &iVar2 );

    VariableSort ( &iVar1, &iVar2 );

    printf ( "Variáveis após o ordenamento: %d e %d!", iVar1, iVar2 );
    
    return 0;
}

int VariableSort ( int *A, int *B ) {

    if ( *B > *A ) {
        int iTemp;
        iTemp = *B;
        *B = *A;
        *A = iTemp;
    }

}