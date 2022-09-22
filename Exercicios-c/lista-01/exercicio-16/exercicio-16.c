/*
16. Leia um valor de comprimento em polegadas e apresente-o convertido em centímetros.
A fórmula de conversão é: C = P ∗ 2.54, sendo C o comprimento em centímetros e P o
comprimento em polegadas.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float pol, cen;

    scanf ( "%f", &pol );
    cen = pol * 2.54;

    printf ( "%.2f polegadas equivalem a: %.2f centimetros.", pol, cen );

    return 0; 
}