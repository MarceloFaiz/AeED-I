/*
7. Crie um programa que contenha uma função que permita passar por parâmetro dois
números inteiros A e B. A função deverá calcular a soma entre estes dois números e
armazenar o resultado na variável A. Esta função não deverá possuir retorno, mas deverá
modificar o valor do primeiro parâmetro. Imprima os valores de A e B na função principal.
*/

#include <stdio.h>
#include <stdlib.h>

void Sum ( int *A, int *B );

int main () {
    int iA, iB;

    printf ( "Digite o valor do inteiro A: " );
    scanf ( "%d", &iA );
    printf ( "Agora, digite o valor do inteiro B: " );
    scanf ( "%d", &iB );

    Sum ( &iA, &iB );

    printf ( "Após somar as duas variáveis e armazenar o resultado em A, os valores agora são: A = %d, B = %d!", iA, iB );
    
    return 0;
}

void Sum ( int *A, int *B ) {
    *A = *A + *B;
}