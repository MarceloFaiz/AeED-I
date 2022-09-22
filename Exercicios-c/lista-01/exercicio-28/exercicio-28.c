/*
28. Faça a leitura de três valores e apresente como resultado a soma dos quadrados dos
três valores lidos.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int a, b, c, soma;

    scanf ( "%d %d %d", &a, &b, &c );
    soma = ( a * a ) + ( b * b ) +( c * c );

    printf ( "A soma dos quadrados de %d, %d e %d e: %d. ", a, b, c, soma );

    return 0;
}