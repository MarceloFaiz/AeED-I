/*
36. Leia a altura e o raio de um cilindro circular e imprima o volume do cilindro. O volume
de um cilindro circular é calculado por meio da seguinte fórmula: V = π ∗ raio² ∗ altura,
onde π = 3.141592.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int raio, altura;
    float volume, pi = 3.141592;

    scanf ( "%d %d", &raio, &altura );
    volume = pi * pow( raio, 2 ) * altura;

    printf ( "O volume do cilindro e: %.2f. ", volume );
    
    return 0;
}