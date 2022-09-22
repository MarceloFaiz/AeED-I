/*
18. Implemente uma função que calcule a área da superfície e o volume de uma esfera de
raio R. Essa funçaão deve obedecer ao protótipo:

void calc_esfera ( float R, float *area, float *volume )

A área da superfície e o volume são dados, respectivamente, por:
A = 4 ∗ p ∗ R2

V = 4/3 ∗ p ∗ R3
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_esfera ( float R, float *area, float *volume );

int main () {
    float R, area, volume;

    printf ( "Digite o raio da esfera: " );
    scanf ( "%f", &R );

    calc_esfera ( R, &area, &volume );

    printf ( "Valor da área da esfera de raio %.2f: %f \n", R, area );
    printf ( "Valor do volume da esfera de raio %.2f: %f \n", R, volume );
    
    return 0;
}

void calc_esfera ( float R, float *area, float *volume ) {
    float pi = 3.1415;

    *area = 4 * pi * pow ( R, 2 );
    *volume = ( 4 / 3 ) * pi * pow ( R, 3 );

}