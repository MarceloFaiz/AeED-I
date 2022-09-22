/*
33. Leia o tamanho do lado de um quadrado e imprima como resultado a sua área.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int lado, area;

    scanf ( "%d", &lado );
    area = lado * lado;

    printf ( "A area de um quadrado de lado %d e: %d. ", lado, area );
    
    return 0;
}