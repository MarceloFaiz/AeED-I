/*
6. Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faça uma função
que retorne a soma do dobro dos dois números lidos. A função deverá armazenar o dobro
de A na própria variável A e o dobro de B na própria variável B.
*/

#include <stdio.h>
#include <stdlib.h>

int DoubleSum ( int *A, int *B );

int main () {
    int iA, iB, iAB;

    printf ( "Digite o valor do inteiro A: " );
    scanf ( "%d", &iA );
    printf ( "Agora, digite o valor do inteiro B: " );
    scanf ( "%d", &iB );

    iAB = DoubleSum ( &iA, &iB );

    printf ( "A soma do dobro das variáveis é igual à: %d! ", iAB );
    
    return 0;
}

int DoubleSum ( int *A, int *B ) {
    int AB;

    *A = *A * 2;
    *B = *B * 2;

    AB = *A + *B;

    return AB;
}