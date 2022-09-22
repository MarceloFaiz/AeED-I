/*
34. Leia o valor do raio de um círculo e calcule e imprima a área do círculo correspondente.
A área do círculo é π ∗ raio², considere π = 3.141592.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int raio;
    float area, pi = 3.141592;

    scanf ( "%d", &raio );
    area = pi * ( raio * raio );

    printf ( "A area de um circulo com raio %d e: %.2f. ", raio, area );
    return 0;
}