/*
17. Leia um valor de comprimento em centímetros e apresente-o convertido em polegadas.
A fórmula de conversão é: P = C / 2.54, sendo C o comprimento em centímetros e P o
comprimento em polegadas.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float cen, pol;

    scanf ( "%f", &cen );
    pol = cen / 2.54;

    printf ( "%.2f polegadas equivalem a: %.2f centimetros.", cen, pol );

    return 0; 
}